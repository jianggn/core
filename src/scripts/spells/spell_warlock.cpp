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

// 18788 - Demonic Sacrifice
struct WarlockDemonicSacrificeScript : SpellScript
{
    void OnEffectExecute(Spell* spell, SpellEffectIndex effIdx) const final
    {
        if (effIdx == EFFECT_INDEX_0 && spell->m_casterUnit && spell->GetUnitTarget())
        {
            uint32 entry = spell->GetUnitTarget()->GetEntry();
            uint32 spellId;
            switch (entry)
            {
                case   416:
                    spellId = 18789;
                    break;               // imp
                case   417:
                    spellId = 18792;
                    break;               // fellhunter
                case  1860:
                    spellId = 18790;
                    break;               // void
                case  1863:
                    spellId = 18791;
                    break;               // succubus
                default:
                    sLog.Out(LOG_BASIC, LOG_LVL_ERROR, "Demonic Sacrifice: Unhandled creature entry (%u) case.", entry);
                    return;
            }

            spell->m_casterUnit->CastSpell(spell->m_casterUnit, spellId, true);
        }
    }
};

SpellScript* GetScript_WarlockDemonicSacrifice(SpellEntry const*)
{
    return new WarlockDemonicSacrificeScript();
}

// 17962, 18930, 18931, 18932 - Conflagrate
struct WarlockConflagrateScript : SpellScript
{
    void OnEffectExecute(Spell* spell, SpellEffectIndex effIdx) const final
    {
        if (effIdx == EFFECT_INDEX_0 && spell->GetUnitTarget())
        {
            // for caster applied auras only
            Unit::AuraList const& mPeriodic = spell->GetUnitTarget()->GetAurasByType(SPELL_AURA_PERIODIC_DAMAGE);
            float coefficientImmolate = 0.0f, coefficientCurseOfAgony = 0.0f, coefficientCorruption = 0.0f;
            for (const auto i : mPeriodic)
            {
                // Immolate
                if (i->GetSpellProto()->IsFitToFamily<SPELLFAMILY_WARLOCK, CF_WARLOCK_IMMOLATE>() &&
                    i->GetCasterGuid() == spell->m_caster->GetObjectGuid())
                {
                    spell->GetUnitTarget()->RemoveAurasByCasterSpell(i->GetId(), spell->m_caster->GetObjectGuid());
                    coefficientImmolate = 1.0f;
                    break;
                }
            }
            for (const auto i : mPeriodic)
            {
                // Curse of Agony
                if (i->GetSpellProto()->IsFitToFamily<SPELLFAMILY_WARLOCK, CF_WARLOCK_CURSE_OF_AGONY>() &&
                    i->GetCasterGuid() == spell->m_caster->GetObjectGuid())
                {
                    spell->GetUnitTarget()->RemoveAurasByCasterSpell(i->GetId(), spell->m_caster->GetObjectGuid());
                    coefficientCurseOfAgony = 2.0f;
                    break;
                }
            }
            for (const auto i : mPeriodic)
            {
                // Corruption
                if (i->GetSpellProto()->IsFitToFamily<SPELLFAMILY_WARLOCK, CF_WARLOCK_CORRUPTION>() &&
                    i->GetCasterGuid() == spell->m_caster->GetObjectGuid())
                {
                    spell->GetUnitTarget()->RemoveAurasByCasterSpell(i->GetId(), spell->m_caster->GetObjectGuid());
                    coefficientCorruption = 1.5f;
                    break;
                }
            }
            spell->damage = spell->damage * (coefficientImmolate + coefficientCurseOfAgony + coefficientCorruption);
            // Wildfire - Conflagrate
            if (spell->m_casterUnit->HasAura(34359) && spell->GetUnitTarget()->GetHealthPercent() < 50.0f)
                spell->damage = spell->damage * 1.3f;
        }
    }
};

SpellScript* GetScript_WarlockConflagrate(SpellEntry const*)
{
    return new WarlockConflagrateScript();
}

void AddSC_warlock_spell_scripts()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "spell_warlock_demonic_sacrifice";
    newscript->GetSpellScript = &GetScript_WarlockDemonicSacrifice;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "spell_warlock_conflagrate";
    newscript->GetSpellScript = &GetScript_WarlockConflagrate;
    newscript->RegisterSelf();
}
