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

// 5246 - Intimidating Shout
struct WarriorIntimidatingShoutScript : SpellScript
{
    bool OnCheckTarget(Spell const* spell, Unit* target, SpellEffectIndex /*eff*/) const final
    {
        // Exception: Intimidating Shout
        // The AoE fear does not apply to spell main target (that is stunned by another aura)
        if (target == spell->m_targets.getUnitTarget())
            return false;
        return true;
    }
};

SpellScript* GetScript_WarriorIntimidatingShout(SpellEntry const*)
{
    return new WarriorIntimidatingShoutScript();
}

void AddSC_warrior_spell_scripts()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "spell_intimidating_shout";
    newscript->GetSpellScript = &GetScript_WarriorIntimidatingShout;
    newscript->RegisterSelf();
}
