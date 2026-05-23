#include "scriptPCH.h"
#include "emerald_sanctum.h"
#include "Group.h"

struct instance_emerald_sanctum : public ScriptedInstance
{
    instance_emerald_sanctum(Map* pMap) : ScriptedInstance(pMap)
    {
        Initialize();
    };

    uint64 m_uiDragonKnightGreenGUID;
    uint64 m_uiDragonKnightRedGUID;
    uint64 m_uiDragonKnightBlueGUID;
    uint64 m_uiWarlockGUID;
    uint32 m_uiSpawnWarlockOnDragonKnightsDeath;
    uint32 m_uiSpawnChestOnWarlockDeath;
    uint32 m_uiDragonKnightDeathCount;
    bool   m_isDragonKnightGreenDead;
    bool   m_isDragonKnightRedDead;
    bool   m_isDragonKnightBlueDead;
    bool   m_isWarlockDead;    

    void Initialize() override
    {
        m_uiDragonKnightGreenGUID = 0;
        m_uiDragonKnightRedGUID = 0;
        m_uiDragonKnightBlueGUID = 0;
        m_uiWarlockGUID = 0;
        m_uiSpawnWarlockOnDragonKnightsDeath = 5000;
        m_uiSpawnChestOnWarlockDeath = 10000;
        m_uiDragonKnightDeathCount = 0;
        m_isDragonKnightGreenDead = false;
        m_isDragonKnightRedDead = false;
        m_isDragonKnightBlueDead = false;
        m_isWarlockDead = false;
    }

    uint32 getTodayStartTimestamp()
    {
        time_t rawtime = time(NULL);
        struct tm *timeinfo = localtime(&rawtime);
        timeinfo->tm_hour = 0;
        timeinfo->tm_min = 0;
        timeinfo->tm_sec = 0;
        return mktime(timeinfo);
    }

    void OnPlayerEnter(Player* pPlayer) override
    {
        if (!pPlayer)
            return;
        if (pPlayer->IsBot())
            return;
        if (pPlayer->HasAura(34291))
            return;
        if (pPlayer->GetQuestStatus(10015) != QUEST_STATUS_COMPLETE || pPlayer->GetQuestStatus(10016) != QUEST_STATUS_COMPLETE || pPlayer->GetQuestStatus(10017) != QUEST_STATUS_COMPLETE)
        {
            pPlayer->AddAura(34291);
            pPlayer->GetSession()->SendNotification("%s must complete quests 10015, 10016 and 10017 to enter map %u.", pPlayer->GetName(), pPlayer->GetMapId());
            return;
        }
        uint32 todayStart = getTodayStartTimestamp();
        uint32 todayEnd = todayStart + 86399;
        std::unique_ptr<QueryResult> result = CharacterDatabase.PQuery("SELECT 1 FROM `character_dota_instance` WHERE `guid`='%u' and `map_id`='%u' and `timer`>='%u' and `timer`<='%u' and `instance_id`<>'%u'", pPlayer->GetObjectGuid(), pPlayer->GetMapId(), todayStart, todayEnd, pPlayer->GetInstanceId());
        if (result)
        {
            pPlayer->AddAura(34291);
            pPlayer->GetSession()->SendNotification("%s can enter map %u only once a day.", pPlayer->GetName(), pPlayer->GetMapId());
        }
    }

    void OnCreatureCreate(Creature* pCreature) override
    {
        switch (pCreature->GetEntry())
        {
            case NPC_DRAGON_KNIGHT_GREEN:
                m_uiDragonKnightGreenGUID = pCreature->GetGUID();
                break;
            case NPC_DRAGON_KNIGHT_RED:
                m_uiDragonKnightRedGUID = pCreature->GetGUID();
                break;
            case NPC_DRAGON_KNIGHT_BLUE:
                m_uiDragonKnightBlueGUID = pCreature->GetGUID();
                break;
            case NPC_WARLOCK:
                m_uiWarlockGUID = pCreature->GetGUID();
                break;
        }
    }

    uint32 getTimestamp()
    {
        time_t rawtime = time(NULL);
        struct tm *timeinfo = localtime(&rawtime);
        return mktime(timeinfo);
    }

    void DotaInstance(Creature *who)
    {
        if (Player* pLootRecepient = who->GetLootRecipient())
        {
            if (Group* pGroup = pLootRecepient->GetGroup())
            {
                for (GroupReference *itr = pGroup->GetFirstMember(); itr != nullptr; itr = itr->next())
                {
                    Player* pGroupGuy = itr->getSource();
                    if (!pGroupGuy || !pGroupGuy->IsInWorld())
                        continue;
                    std::unique_ptr<QueryResult> result(CharacterDatabase.PQuery("SELECT 1 FROM `characters` WHERE `guid` = '%u' and `name` = '%s'", pGroupGuy->GetObjectGuid(), pGroupGuy->GetName()));
                    if (!result)
                        continue;
                    CharacterDatabase.PExecute("replace into `character_dota_instance` (`guid`, `map_id`, `instance_id`, `timer`) VALUES (%u, %u, %u, %u)", pGroupGuy->GetObjectGuid(), pGroupGuy->GetMapId(), pGroupGuy->GetInstanceId(), getTimestamp());
                }
            }
            else
                CharacterDatabase.PExecute("replace into `character_dota_instance` (`guid`, `map_id`, `instance_id`, `timer`) VALUES (%u, %u, %u, %u)", pLootRecepient->GetObjectGuid(), pLootRecepient->GetMapId(), pLootRecepient->GetInstanceId(), getTimestamp());
        }
    }

    void OnCreatureDeath(Creature *who) override
    {
        switch (who->GetEntry())
        {
            case NPC_DRAGON_KNIGHT_GREEN :
                m_isDragonKnightGreenDead = true;
                m_uiSpawnWarlockOnDragonKnightsDeath = 5000;
                m_uiDragonKnightDeathCount += 1;
                DotaInstance(who);
                break;
            case NPC_DRAGON_KNIGHT_RED :
                m_isDragonKnightRedDead = true;
                m_uiSpawnWarlockOnDragonKnightsDeath = 5000;
                m_uiDragonKnightDeathCount += 1;
                DotaInstance(who);
                break;
            case NPC_DRAGON_KNIGHT_BLUE :
                m_isDragonKnightBlueDead = true;
                m_uiSpawnWarlockOnDragonKnightsDeath = 5000;
                m_uiDragonKnightDeathCount += 1;
                DotaInstance(who);
                break;
            case NPC_WARLOCK :
                m_isWarlockDead = true;
                m_uiSpawnChestOnWarlockDeath = 10000;
                DotaInstance(who);
                break;
        }
    }

    uint32 GetData(uint32 uiType) override
    {
        if (uiType == TYPE_DRAGON_KNIGHT_DEATH_COUNT)
            return m_uiDragonKnightDeathCount;
        return 0;
    }

    void Update(uint32 uiDiff) override
    {
        //spawn warlock
        if (m_isDragonKnightGreenDead && m_isDragonKnightRedDead && m_isDragonKnightBlueDead && m_uiSpawnWarlockOnDragonKnightsDeath)
        {
            if (m_uiSpawnWarlockOnDragonKnightsDeath <= uiDiff)
            {
                if (Creature* pDragonKnightGreen = instance->GetCreature(m_uiDragonKnightGreenGUID))
                {
                    if (Creature* pWarlock = pDragonKnightGreen->SummonCreature(NPC_WARLOCK, 3319.990f, 3057.540f, 23.333f, 3.172990f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 120 * MINUTE * IN_MILLISECONDS))
                    {
                        pWarlock->SetRespawnDelay(7 * DAY);
                        m_uiSpawnWarlockOnDragonKnightsDeath = 0;
                    }
                }
            }
            else
                m_uiSpawnWarlockOnDragonKnightsDeath -= uiDiff;
        }
        //spawn chest
        if (m_isWarlockDead && m_uiSpawnChestOnWarlockDeath)
        {
            if (m_uiSpawnChestOnWarlockDeath <= uiDiff)
            {
                if (Creature* pWarlock = instance->GetCreature(m_uiWarlockGUID))
                {
                    pWarlock->SummonGameObject(GO_CHEST, 2762.25f, 2972.77f, 26.903f, 0.0f, 0, 0, 0, 0, 43200);
                    m_uiSpawnChestOnWarlockDeath = 0;
                }
            }
            else
                m_uiSpawnChestOnWarlockDeath -= uiDiff;
        }
    }
};

InstanceData* GetInstanceData_instance_emerald_sanctum(Map* pMap)
{
    return new instance_emerald_sanctum(pMap);
}

void AddSC_instance_emerald_sanctum()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "instance_emerald_sanctum";
    newscript->GetInstanceData = &GetInstanceData_instance_emerald_sanctum;
    newscript->RegisterSelf();
}