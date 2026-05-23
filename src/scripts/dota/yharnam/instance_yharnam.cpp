#include "scriptPCH.h"
#include "yharnam.h"
#include "Group.h"

struct instance_yharnam : public ScriptedInstance
{
    instance_yharnam(Map* pMap) : ScriptedInstance(pMap)
    {
        Initialize();
    };

    uint64 m_uiBloodStarvedBeastGUID;
    uint64 m_uiFatherGascoigneGUID;
    uint64 m_uiLudwigGUID;
    uint64 m_uiPudgeGUID;
    uint64 m_uiGehrmanGUID;
    uint64 m_uiMoonPresenceGUID;
    uint32 m_uiSpawnChestOnAllBossDeath;
    bool   m_isBloodStarvedBeastDead;
    bool   m_isFatherGascoigneDead;
    bool   m_isLudwigDead;
    bool   m_isPudgeDead;
    bool   m_isGehrmanDead;

    void Initialize() override
    {
        m_uiBloodStarvedBeastGUID = 0;
        m_uiFatherGascoigneGUID = 0;
        m_uiLudwigGUID = 0;
        m_uiPudgeGUID = 0;
        m_uiGehrmanGUID = 0;
        m_uiMoonPresenceGUID = 0;
        m_uiSpawnChestOnAllBossDeath = 10000;
        m_isBloodStarvedBeastDead = false;
        m_isFatherGascoigneDead = false;
        m_isLudwigDead = false;
        m_isPudgeDead = false;
        m_isGehrmanDead = false;
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
        if (pPlayer->HasAura(34293))
            return;
        if (pPlayer->GetQuestStatus(10015) != QUEST_STATUS_COMPLETE || pPlayer->GetQuestStatus(10016) != QUEST_STATUS_COMPLETE || pPlayer->GetQuestStatus(10017) != QUEST_STATUS_COMPLETE)
        {
            pPlayer->AddAura(34293);
            pPlayer->GetSession()->SendNotification("%s must complete quests 10015, 10016 and 10017 to enter map %u.", pPlayer->GetName(), pPlayer->GetMapId());
            return;
        }
        uint32 todayStart = getTodayStartTimestamp();
        uint32 todayEnd = todayStart + 86399;
        std::unique_ptr<QueryResult> result = CharacterDatabase.PQuery("SELECT 1 FROM `character_dota_instance` WHERE `guid`='%u' and `map_id`='%u' and `timer`>='%u' and `timer`<='%u' and `instance_id`<>'%u'", pPlayer->GetObjectGuid(), pPlayer->GetMapId(), todayStart, todayEnd, pPlayer->GetInstanceId());
        if (result)
        {
            pPlayer->AddAura(34293);
            pPlayer->GetSession()->SendNotification("%s can enter map %u only once a day.", pPlayer->GetName(), pPlayer->GetMapId());
        }
    }

    void OnCreatureCreate(Creature* pCreature) override
    {
        switch (pCreature->GetEntry())
        {
            case NPC_BLOOD_STARVED_BEAST:
                m_uiBloodStarvedBeastGUID = pCreature->GetGUID();
                break;
            case NPC_FATHER_GASCOIGNE:
                m_uiFatherGascoigneGUID = pCreature->GetGUID();
                break;
            case NPC_LUDWIG:
                m_uiLudwigGUID = pCreature->GetGUID();
                break;
            case NPC_PUDGE:
                m_uiPudgeGUID = pCreature->GetGUID();
                break;
            case NPC_GEHRMAN:
                m_uiGehrmanGUID = pCreature->GetGUID();
                break;
            case NPC_MOON_PRESENCE:
                m_uiMoonPresenceGUID = pCreature->GetGUID();
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
            case NPC_BLOOD_STARVED_BEAST :
                m_isBloodStarvedBeastDead = true;
                m_uiSpawnChestOnAllBossDeath = 10000;
                DotaInstance(who);
                break;
            case NPC_FATHER_GASCOIGNE :
                m_isFatherGascoigneDead = true;
                m_uiSpawnChestOnAllBossDeath = 10000;
                DotaInstance(who);
                break;
            case NPC_LUDWIG :
                m_isLudwigDead = true;
                m_uiSpawnChestOnAllBossDeath = 10000;
                DotaInstance(who);
                break;
            case NPC_PUDGE :
                m_isPudgeDead = true;
                m_uiSpawnChestOnAllBossDeath = 10000;
                DotaInstance(who);
                break;
            case NPC_GEHRMAN :
                m_isGehrmanDead = true;
                m_uiSpawnChestOnAllBossDeath = 10000;
                if (Creature* pMoonPresence = instance->GetCreature(m_uiMoonPresenceGUID))
                {
                    DoScriptText(SAY_AGGRO_MOON_PRESENCE, pMoonPresence);
                    pMoonPresence->ForcedDespawn(5000);
                }
                DotaInstance(who);
                break;
        }
    }

    void Update(uint32 uiDiff) override
    {
        //spawn chest
        if (m_isBloodStarvedBeastDead && m_isFatherGascoigneDead && m_isLudwigDead && m_isPudgeDead && m_isGehrmanDead && m_uiSpawnChestOnAllBossDeath)
        {
            if (m_uiSpawnChestOnAllBossDeath <= uiDiff)
            {
                if (Creature* pGehrman = instance->GetCreature(m_uiGehrmanGUID))
                {
                    pGehrman->SummonGameObject(GO_CHEST, -1095.44f, 2234.75f, 182.862f, 0.0f, 0, 0, 0, 0, 43200);
                    m_uiSpawnChestOnAllBossDeath = 0;
                }
            }
            else
                m_uiSpawnChestOnAllBossDeath -= uiDiff;
        }
    }
};

InstanceData* GetInstanceData_instance_yharnam(Map* pMap)
{
    return new instance_yharnam(pMap);
}

void AddSC_instance_yharnam()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "instance_yharnam";
    newscript->GetInstanceData = &GetInstanceData_instance_yharnam;
    newscript->RegisterSelf();
}