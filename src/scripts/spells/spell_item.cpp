/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "scriptPCH.h"

// 2833 - Heavy Armor Kit
struct HeavyArmorKitScript : public SpellScript
{
    SpellCastResult OnCheckCast(Spell* spell, bool strict) const final
    {
        Item* targetItem = spell->m_targets.getItemTarget();
        if (targetItem->GetProto()->ItemLevel < 15)
            return SPELL_FAILED_LOWLEVEL;
        return SPELL_CAST_OK;
    }
};

SpellScript* GetScript_HeavyArmorKit(SpellEntry const*)
{
    return new HeavyArmorKitScript();
}

// 8063 - Deviate Fish
struct DeviateFishScript : public SpellScript
{
    bool OnEffectExecute(Spell* spell, SpellEffectIndex effIdx) const final
    {
        if (effIdx == EFFECT_INDEX_0)
        {
            Player* pPlayer = spell->GetCaster()->ToPlayer();
            if (!pPlayer)
                return false;

            uint32 randomSpellId = PickRandomValue(
                8064u, // Sleepy
                8065u, // Invigorate
                8066u, // Shrink
                8067u, // Party Time!
                8068u, // Healthy Spirit
                8070u  // Rejuvenation
            );

            pPlayer->CastSpell(pPlayer, randomSpellId, true, nullptr);
        }
        return true;
    }
};

SpellScript* GetScript_DeviateFish(SpellEntry const*)
{
    return new DeviateFishScript();
}

// 8213 - Cooked Deviate Fish
struct CookedDeviateFishScript : public SpellScript
{
    bool OnEffectExecute(Spell* spell, SpellEffectIndex effIdx) const final
    {
        if (effIdx == EFFECT_INDEX_0)
        {
            Player* pPlayer = spell->GetCaster()->ToPlayer();
            if (!pPlayer)
                return false;

            uint32 randomSpellId = 0;
            uint32 spells[6] = {
                (pPlayer->GetGender() == GENDER_MALE ? 8219u : 8220u), // Flip Out - ninja
                (pPlayer->GetGender() == GENDER_MALE ? 8221u : 8222u), // Yaaarrrr - pirate
                8223u, // Oops - goo
                8215u, // Rapid Cast
                8224u, // Cowardice
                8226u  // Fake Death
            };

            // Had additional effects before BWL patch.
#if SUPPORTED_CLIENT_BUILD <= CLIENT_BUILD_1_5_1
            randomSpellId = spells[urand(0, 5)];
#else
            randomSpellId = spells[urand(0, 1)];
#endif
            pPlayer->CastSpell(pPlayer, randomSpellId, true, nullptr);
        }
        return true;
    }
};

SpellScript* GetScript_CookedDeviateFish(SpellEntry const*)
{
    return new CookedDeviateFishScript();
}

// 16589 - Noggenfogger Elixir
struct NoggenfoggerElixirScript : public SpellScript
{
    bool OnEffectExecute(Spell* spell, SpellEffectIndex effIdx) const final
    {
        if (effIdx == EFFECT_INDEX_0)
        {
            Player* pPlayer = spell->GetCaster()->ToPlayer();
            if (!pPlayer)
                return false;

            // https://old.reddit.com/r/classicwow/comments/jwycmc/noggenfogger_1000_consumes_593_skellies_210_minis/
            uint32 randomSpellId = 16591; // skeleton (60%)
            switch (urand(1, 10))
            {
                case 1:
                case 2:
                {
                    randomSpellId = 16595; // mini (20%)
                    break;
                }
                case 3:
                case 4:
                {
                    randomSpellId = 16593; // slow fall (20%)
                    break;
                }
            }

            pPlayer->CastSpell(pPlayer, randomSpellId, true, nullptr);
        }
        return true;
    }
};

SpellScript* GetScript_NoggenfoggerElixir(SpellEntry const*)
{
    return new NoggenfoggerElixirScript();
}

// 15712 - Linken's Boomerang
struct LinkensBoomerangScript : public SpellScript
{
    bool OnEffectExecute(Spell* spell, SpellEffectIndex effIdx) const final
    {
        // 10% chance to proc stun, 3% chance to proc disarm (dubious numbers)
        if (effIdx == EFFECT_INDEX_1)
        {
            if (urand(0, 30))
                return false;
        }
        else if (effIdx == EFFECT_INDEX_2)
        {
            if (urand(0, 10))
                return false;
        }
        return true;
    }
};

SpellScript* GetScript_LinkensBoomerang(SpellEntry const*)
{
    return new LinkensBoomerangScript();
}

// 6410 - Food (Scorpid Surprise)
struct ScorpidSurpriseScript : public SpellScript
{
    bool OnEffectExecute(Spell* spell, SpellEffectIndex effIdx) const final
    {
        if (effIdx == EFFECT_INDEX_1)
        {
            // Heals 294 damage over 21 sec, assuming you don't bite down on a poison sac.
            // 10% proc rate (no source !)
            if (urand(0, 10))
                return false;
        }
        return true;
    }
};

SpellScript* GetScript_ScorpidSurprise(SpellEntry const*)
{
    return new ScorpidSurpriseScript();
}

// 29284 - Brittle Armor (Zandalarian Hero Badge)
struct BrittleArmorDummyScript : public SpellScript
{
    bool OnEffectExecute(Spell* spell, SpellEffectIndex effIdx) const final
    {
        if (effIdx == EFFECT_INDEX_0 && spell->GetUnitTarget())
        {
            spell->m_caster->CastSpell(spell->GetUnitTarget(), 24575, true);
        }
        return true;
    }
};

SpellScript* GetScript_BrittleArmorDummy(SpellEntry const*)
{
    return new BrittleArmorDummyScript();
}

// 29286 - Mercurial Shield (Petrified Scarab)
struct MercurialShieldDummyScript : public SpellScript
{
    bool OnEffectExecute(Spell* spell, SpellEffectIndex effIdx) const final
    {
        if (effIdx == EFFECT_INDEX_0 && spell->GetUnitTarget())
        {
            spell->m_caster->CastSpell(spell->GetUnitTarget(), 26464, true);
        }
        return true;
    }
};

SpellScript* GetScript_MercurialShieldDummy(SpellEntry const*)
{
    return new MercurialShieldDummyScript();
}

// 23442 - Everlook Transporter (Dimensional Ripper - Everlook)
struct EverlookTransporterScript : public SpellScript
{
    bool OnEffectExecute(Spell* spell, SpellEffectIndex effIdx) const final
    {
        if (effIdx == EFFECT_INDEX_0 && spell->m_casterUnit)
        {
            int32 r = irand(0, 119);
            if (r >= 70)                                    // 7/12 success
            {
                if (r < 100)                                // 4/12 evil twin
                    spell->m_casterUnit->CastSpell(spell->m_casterUnit, 23445, true);
                else                                        // 1/12 fire
                    spell->m_casterUnit->CastSpell(spell->m_casterUnit, 23449, true);
            }
        }
        return true;
    }
};

SpellScript* GetScript_EverlookTransporter(SpellEntry const*)
{
    return new EverlookTransporterScript();
}

void AddSC_item_spell_scripts()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "spell_heavy_armor_kit";
    newscript->GetSpellScript = &GetScript_HeavyArmorKit;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "spell_deviate_fish";
    newscript->GetSpellScript = &GetScript_DeviateFish;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "spell_cooked_deviate_fish";
    newscript->GetSpellScript = &GetScript_CookedDeviateFish;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "spell_noggenfogger_elixir";
    newscript->GetSpellScript = &GetScript_NoggenfoggerElixir;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "spell_linkens_boomerang";
    newscript->GetSpellScript = &GetScript_LinkensBoomerang;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "spell_scorpid_surprise";
    newscript->GetSpellScript = &GetScript_ScorpidSurprise;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "spell_brittle_armor_dummy";
    newscript->GetSpellScript = &GetScript_BrittleArmorDummy;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "spell_mercurial_shield_dummy";
    newscript->GetSpellScript = &GetScript_MercurialShieldDummy;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "spell_everlook_transporter";
    newscript->GetSpellScript = &GetScript_EverlookTransporter;
    newscript->RegisterSelf();
}
