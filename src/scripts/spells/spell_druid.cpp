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

// 22568, 22827, 22828, 22829, 31018 - Ferocious Bite
struct DruidFerociousBiteScript : SpellScript
{
    void OnEffectExecute(Spell* spell, SpellEffectIndex effIdx) const final
    {
        if (effIdx == EFFECT_INDEX_0 && spell->GetUnitTarget())
        {
            Player* pPlayer = spell->m_caster->ToPlayer();
            if (!pPlayer)
                return;

#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_11_2
            // World of Warcraft Client Patch 1.12.0 (2006-08-22)
            // - Ferocious Bite: Book of Ferocious Bite (Rank 5) now drops off The
            //   Beast in Black Rock Spire. In addition, Ferocious Bite now increases
            //   in potency with greater attack power.
            // ( AP * 3% * combo + energy * 2,7 + damage )
            if (uint32 combo = ((Player*)pPlayer)->GetComboPoints())
                spell->damage += pPlayer->GetTotalAttackPowerValue(BASE_ATTACK) * combo * 0.03f;
#endif
            spell->damage += pPlayer->GetPower(POWER_ENERGY) * spell->m_spellInfo->DmgMultiplier[effIdx];
            pPlayer->SetPower(POWER_ENERGY, 0);
        }
    }
};

SpellScript* GetScript_DruidFerociousBite(SpellEntry const*)
{
    return new DruidFerociousBiteScript();
}

void AddSC_druid_spell_scripts()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "spell_druid_ferocious_bite";
    newscript->GetSpellScript = &GetScript_DruidFerociousBite;
    newscript->RegisterSelf();
}
