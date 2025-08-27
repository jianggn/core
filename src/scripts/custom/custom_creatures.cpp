/* Copyright (C) 2009 - 2010 ScriptDevZero <http://github.com/scriptdevzero/scriptdevzero>
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
#include "custom.h"
#include "ScriptedAI.h"
#include <ctime>

// HARDCORE REWARD NPC

bool GossipHello_Hardcore_Reward_NPC(Player *player, Creature *_Creature)   
{
    player->ADD_GOSSIP_ITEM(7, "各职业第一个到达60级的硬核模式玩家，可随机获取一件职业橙装。",               GOSSIP_SENDER_MAIN, 1);
    player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
    return true;
}
void SendDefaultMenu_Hardcore_Reward_NPC(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case 1:
            if (!player->GetQuestStatus(10000) == QUEST_STATUS_COMPLETE)
            {
                player->GetSession()->SendNotification("非硬核模式，无法领取奖励。");
                player->CLOSE_GOSSIP_MENU();
                break;
            }
            if (player->GetLevel() < 60)
            {
                player->GetSession()->SendNotification("未到达60级，无法领取奖励。");
                player->CLOSE_GOSSIP_MENU();
                break;
            }
            std::unique_ptr<QueryResult> result = CharacterDatabase.PQuery("select name from `hardcore_reward` where `class` = %u", player->GetClass());
            if(result)
            {
                std::string playerName = result->Fetch()[0].GetString();
                player->GetSession()->SendNotification("同职业玩家：%s已第一个到达60级，无法领取奖励。", playerName);
                player->CLOSE_GOSSIP_MENU();
                break;
            }
            bool has_26010 = player->HasItemCount(26010, 1, true) || player->HasItemCount(26137, 1, true);
            bool has_26020 = player->HasItemCount(26020, 1, true) || player->HasItemCount(26138, 1, true);
            bool has_26021 = player->HasItemCount(26021, 1, true) || player->HasItemCount(26139, 1, true);
            bool has_26022 = player->HasItemCount(26022, 1, true) || player->HasItemCount(26140, 1, true);
            bool has_26023 = player->HasItemCount(26023, 1, true) || player->HasItemCount(26141, 1, true);
            bool has_26024 = player->HasItemCount(26024, 1, true) || player->HasItemCount(26142, 1, true);
            bool has_26027 = player->HasItemCount(26027, 1, true) || player->HasItemCount(26143, 1, true);
            bool has_26028 = player->HasItemCount(26028, 1, true) || player->HasItemCount(26144, 1, true);
            bool has_26029 = player->HasItemCount(26029, 1, true) || player->HasItemCount(26145, 1, true);
            bool has_26032 = player->HasItemCount(26032, 1, true) || player->HasItemCount(26146, 1, true);
            bool has_26034 = player->HasItemCount(26034, 1, true) || player->HasItemCount(26147, 1, true);
            bool has_26035 = player->HasItemCount(26035, 1, true) || player->HasItemCount(26148, 1, true);
            bool has_26036 = player->HasItemCount(26036, 1, true) || player->HasItemCount(26149, 1, true);
            bool has_26037 = player->HasItemCount(26037, 1, true) || player->HasItemCount(26150, 1, true);
            bool has_26038 = player->HasItemCount(26038, 1, true) || player->HasItemCount(26151, 1, true);
            bool has_26044_1 = player->HasItemCount(26044, 1, true) || player->HasItemCount(26152, 1, true);
            bool has_26044_2 = player->HasItemCount(26044, 2, true) || player->HasItemCount(26152, 2, true) || (player->HasItemCount(26044, 1, true) && player->HasItemCount(26152, 1, true));
            bool has_26045 = player->HasItemCount(26045, 1, true) || player->HasItemCount(26153, 1, true);
            bool has_26046 = player->HasItemCount(26046, 1, true) || player->HasItemCount(26154, 1, true);
            bool has_26047 = player->HasItemCount(26047, 1, true) || player->HasItemCount(26155, 1, true);
            bool has_26049 = player->HasItemCount(26049, 1, true) || player->HasItemCount(26156, 1, true);
            bool has_26050 = player->HasItemCount(26050, 1, true) || player->HasItemCount(26157, 1, true);
            switch (player->GetClass())
            {
                // WARRIOR
                case 1:
                    // 有0件
                    if (!has_26010 && !has_26027 && !has_26028)
                    {
                        switch (urand(1,3))
                        {
                            case 1:
                                player->AddItem(26010);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 2:
                                player->AddItem(26027);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 3:
                                player->AddItem(26028);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                        }
                    }
                    // 有1件
                    else if (has_26010 && !has_26027 && !has_26028)
                    {
                        switch (urand(1,2))
                        {
                            case 1:
                                player->AddItem(26027);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 2:
                                player->AddItem(26028);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                        }
                    }
                    else if (!has_26010 && has_26027 && !has_26028)
                    {
                        switch (urand(1,2))
                        {
                            case 1:
                                player->AddItem(26010);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 2:
                                player->AddItem(26028);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                        }
                    }
                    else if (!has_26010 && !has_26027 && has_26028)
                    {
                        switch (urand(1,2))
                        {
                            case 1:
                                player->AddItem(26010);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 2:
                                player->AddItem(26027);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                        }
                    }
                    // 有2件
                    else if (!has_26010 && has_26027 && has_26028)
                    {
                        player->AddItem(26010);
                        CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    else if (has_26010 && !has_26027 && has_26028)
                    {
                        player->AddItem(26027);
                        CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    else if (has_26010 && has_26027 && !has_26028)
                    {
                        player->AddItem(26028);
                        CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    // 有3件
                    else if (has_26010 && has_26027 && has_26028)
                    {
                        player->GetSession()->SendNotification("已集齐职业橙装，奖励3000金币。");
                        player->ModifyMoney(3000 * GOLD);
                        CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    break;
                // PALADIN
                case 2:
                    // 有0件
                    if (!has_26022 && !has_26027 && !has_26028 && !has_26036)
                    {
                        switch (urand(1,4))
                        {
                            case 1:
                                player->AddItem(26022);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 2:
                                player->AddItem(26027);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 3:
                                player->AddItem(26028);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 4:
                                player->AddItem(26036);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                        }
                    }
                    // 有1件
                    else if (has_26022 && !has_26027 && !has_26028 && !has_26036)
                    {
                        switch (urand(1,3))
                        {
                            case 1:
                                player->AddItem(26027);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 2:
                                player->AddItem(26028);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 3:
                                player->AddItem(26036);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                        }
                    }
                    else if (!has_26022 && has_26027 && !has_26028 && !has_26036)
                    {
                        switch (urand(1,3))
                        {
                            case 1:
                                player->AddItem(26022);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 2:
                                player->AddItem(26028);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 3:
                                player->AddItem(26036);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                        }
                    }
                    else if (!has_26022 && !has_26027 && has_26028 && !has_26036)
                    {
                        switch (urand(1,3))
                        {
                            case 1:
                                player->AddItem(26022);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 2:
                                player->AddItem(26027);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 3:
                                player->AddItem(26036);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                        }
                    }
                    else if (!has_26022 && !has_26027 && !has_26028 && has_26036)
                    {
                        switch (urand(1,3))
                        {
                            case 1:
                                player->AddItem(26022);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 2:
                                player->AddItem(26027);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 3:
                                player->AddItem(26028);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                        }
                    }
                    // 有2件
                    else if (has_26022 && has_26027 && !has_26028 && !has_26036)
                    {
                        switch (urand(1,2))
                        {
                            case 1:
                                player->AddItem(26028);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 2:
                                player->AddItem(26036);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                        }
                    }
                    else if (has_26022 && !has_26027 && has_26028 && !has_26036)
                    {
                        switch (urand(1,2))
                        {
                            case 1:
                                player->AddItem(26027);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 2:
                                player->AddItem(26036);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                        }
                    }
                    else if (has_26022 && !has_26027 && !has_26028 && has_26036)
                    {
                        switch (urand(1,2))
                        {
                            case 1:
                                player->AddItem(26027);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 2:
                                player->AddItem(26028);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                        }
                    }
                    else if (!has_26022 && has_26027 && has_26028 && !has_26036)
                    {
                        switch (urand(1,2))
                        {
                            case 1:
                                player->AddItem(26022);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 2:
                                player->AddItem(26036);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                        }
                    }
                    else if (!has_26022 && has_26027 && !has_26028 && has_26036)
                    {
                        switch (urand(1,2))
                        {
                            case 1:
                                player->AddItem(26022);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 2:
                                player->AddItem(26028);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                        }
                    }
                    else if (!has_26022 && !has_26027 && has_26028 && has_26036)
                    {
                        switch (urand(1,2))
                        {
                            case 1:
                                player->AddItem(26022);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 2:
                                player->AddItem(26027);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                        }
                    }
                    // 有3件
                    else if (!has_26022 && has_26027 && has_26028 && has_26036)
                    {
                        player->AddItem(26022);
                        CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    else if (has_26022 && !has_26027 && has_26028 && has_26036)
                    {
                        player->AddItem(26027);
                        CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    else if (has_26022 && has_26027 && !has_26028 && has_26036)
                    {
                        player->AddItem(26028);
                        CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    else if (has_26022 && has_26027 && has_26028 && !has_26036)
                    {
                        player->AddItem(26036);
                        CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    // 有4件
                    else if (has_26022 && has_26027 && has_26028 && has_26036)
                    {
                        player->GetSession()->SendNotification("已集齐职业橙装，奖励4000金币。");
                        player->ModifyMoney(4000 * GOLD);
                        CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    break;
                // HUNTER
                case 3:
                    // 有0件
                    if (!has_26024 && !has_26032)
                    {
                        switch (urand(1,2))
                        {
                            case 1:
                                player->AddItem(26024);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 2:
                                player->AddItem(26032);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                        }
                    }
                    // 有1件
                    else if (!has_26024 && has_26032)
                    {
                        player->AddItem(26024);
                        CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    else if (has_26024 && !has_26032)
                    {
                        player->AddItem(26032);
                        CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    // 有2件
                    else if (has_26024 && has_26032)
                    {
                        player->GetSession()->SendNotification("已集齐职业橙装，奖励2000金币。");
                        player->ModifyMoney(2000 * GOLD);
                        CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    break;
                // ROGUE
                case 4:
                    // 有0件
                    if (!has_26020 && !has_26021 && !has_26044_1 && !has_26044_2)
                    {
                        switch (urand(1,3))
                        {
                            case 1:
                                player->AddItem(26020);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 2:
                                player->AddItem(26021);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 3:
                                player->AddItem(26044);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                        }
                    }
                    // 有1件
                    else if (has_26020 && !has_26021 && !has_26044_1 && !has_26044_2)
                    {
                        switch (urand(1,2))
                        {
                            case 1:
                                player->AddItem(26021);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 2:
                                player->AddItem(26044);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                        }
                    }
                    else if (!has_26020 && has_26021 && !has_26044_1 && !has_26044_2)
                    {
                        switch (urand(1,2))
                        {
                            case 1:
                                player->AddItem(26020);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 2:
                                player->AddItem(26044);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                        }
                    }
                    else if (!has_26020 && !has_26021 && has_26044_1 && !has_26044_2)
                    {
                        switch (urand(1,3))
                        {
                            case 1:
                                player->AddItem(26020);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 2:
                                player->AddItem(26021);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 3:
                                player->AddItem(26044);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                        }
                    }
                    // 有2件
                    else if (has_26020 && has_26021 && !has_26044_1 && !has_26044_2)
                    {
                            player->AddItem(26044);
                            CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                            player->CLOSE_GOSSIP_MENU();
                    }
                    else if (has_26020 && !has_26021 && has_26044_1 && !has_26044_2)
                    {
                        switch (urand(1,2))
                        {
                            case 1:
                                player->AddItem(26021);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 2:
                                player->AddItem(26044);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                        }
                    }
                    else if (!has_26020 && has_26021 && has_26044_1 && !has_26044_2)
                    {
                        switch (urand(1,2))
                        {
                            case 1:
                                player->AddItem(26020);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 2:
                                player->AddItem(26044);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                        }
                    }
                    else if (!has_26020 && !has_26021 && has_26044_1 && has_26044_2)
                    {
                        switch (urand(1,2))
                        {
                            case 1:
                                player->AddItem(26020);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 2:
                                player->AddItem(26021);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                        }
                    }
                    // 有3件
                    else if (!has_26020 && has_26021 && has_26044_1 && has_26044_2)
                    {
                        player->AddItem(26020);
                        CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    else if (has_26020 && !has_26021 && has_26044_1 && has_26044_2)
                    {
                        player->AddItem(26021);
                        CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    else if (has_26020 && has_26021 && has_26044_1 && !has_26044_2)
                    {
                        player->AddItem(26044);
                        CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    // 有4件
                    else if (has_26020 && has_26021 && has_26044_1 && has_26044_2)
                    {
                        player->GetSession()->SendNotification("已集齐职业橙装，奖励4000金币。");
                        player->ModifyMoney(4000 * GOLD);
                        CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    break;
                // PRIEST
                case 5:
                    // 有0件
                    if (!has_26029 && !has_26046)
                    {
                        switch (urand(1,2))
                        {
                            case 1:
                                player->AddItem(26029);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 2:
                                player->AddItem(26046);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                        }
                    }
                    // 有1件
                    else if (!has_26029 && has_26046)
                    {
                        player->AddItem(26029);
                        CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    else if (has_26029 && !has_26046)
                    {
                        player->AddItem(26046);
                        CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    // 有2件
                    else if (has_26029 && has_26046)
                    {
                        player->GetSession()->SendNotification("已集齐职业橙装，奖励2000金币。");
                        player->ModifyMoney(2000 * GOLD);
                        CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    break;
                // SHAMAN
                case 7:
                    // 有0件
                    if (!has_26023 && !has_26038 && !has_26049 && !has_26050)
                    {
                        switch (urand(1,4))
                        {
                            case 1:
                                player->AddItem(26023);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 2:
                                player->AddItem(26038);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 3:
                                player->AddItem(26049);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 4:
                                player->AddItem(26050);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                        }
                    }
                    // 有1件
                    else if (has_26023 && !has_26038 && !has_26049 && !has_26050)
                    {
                        switch (urand(1,3))
                        {
                            case 1:
                                player->AddItem(26038);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 2:
                                player->AddItem(26049);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 3:
                                player->AddItem(26050);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                        }
                    }
                    else if (!has_26023 && has_26038 && !has_26049 && !has_26050)
                    {
                        switch (urand(1,3))
                        {
                            case 1:
                                player->AddItem(26023);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 2:
                                player->AddItem(26049);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 3:
                                player->AddItem(26050);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                        }
                    }
                    else if (!has_26023 && !has_26038 && has_26049 && !has_26050)
                    {
                        switch (urand(1,3))
                        {
                            case 1:
                                player->AddItem(26023);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 2:
                                player->AddItem(26038);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 3:
                                player->AddItem(26050);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                        }
                    }
                    else if (!has_26023 && !has_26038 && !has_26049 && has_26050)
                    {
                        switch (urand(1,3))
                        {
                            case 1:
                                player->AddItem(26023);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 2:
                                player->AddItem(26038);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 3:
                                player->AddItem(26049);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                        }
                    }
                    // 有2件
                    else if (has_26023 && has_26038 && !has_26049 && !has_26050)
                    {
                        switch (urand(1,2))
                        {
                            case 1:
                                player->AddItem(26049);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 2:
                                player->AddItem(26050);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                        }
                    }
                    else if (has_26023 && !has_26038 && has_26049 && !has_26050)
                    {
                        switch (urand(1,2))
                        {
                            case 1:
                                player->AddItem(26038);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 2:
                                player->AddItem(26050);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                        }
                    }
                    else if (has_26023 && !has_26038 && !has_26049 && has_26050)
                    {
                        switch (urand(1,2))
                        {
                            case 1:
                                player->AddItem(26038);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 2:
                                player->AddItem(26049);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                        }
                    }
                    else if (!has_26023 && has_26038 && has_26049 && !has_26050)
                    {
                        switch (urand(1,2))
                        {
                            case 1:
                                player->AddItem(26023);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 2:
                                player->AddItem(26050);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                        }
                    }
                    else if (!has_26023 && has_26038 && !has_26049 && has_26050)
                    {
                        switch (urand(1,2))
                        {
                            case 1:
                                player->AddItem(26023);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 2:
                                player->AddItem(26049);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                        }
                    }
                    else if (!has_26023 && !has_26038 && has_26049 && has_26050)
                    {
                        switch (urand(1,2))
                        {
                            case 1:
                                player->AddItem(26023);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 2:
                                player->AddItem(26038);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                        }
                    }
                    // 有3件
                    else if (!has_26023 && has_26038 && has_26049 && has_26050)
                    {
                        player->AddItem(26023);
                        CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    else if (has_26023 && !has_26038 && has_26049 && has_26050)
                    {
                        player->AddItem(26038);
                        CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    else if (has_26023 && has_26038 && !has_26049 && has_26050)
                    {
                        player->AddItem(26049);
                        CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    else if (has_26023 && has_26038 && has_26049 && !has_26050)
                    {
                        player->AddItem(26050);
                        CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    // 有4件
                    else if (has_26023 && has_26038 && has_26049 && has_26050)
                    {
                        player->GetSession()->SendNotification("已集齐职业橙装，奖励4000金币。");
                        player->ModifyMoney(4000 * GOLD);
                        CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    break;
                // MAGE
                case 8:
                    // 有0件
                    if (!has_26029 && !has_26045)
                    {
                        switch (urand(1,2))
                        {
                            case 1:
                                player->AddItem(26029);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 2:
                                player->AddItem(26045);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                        }
                    }
                    // 有1件
                    else if (!has_26029 && has_26045)
                    {
                        player->AddItem(26029);
                        CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    else if (has_26029 && !has_26045)
                    {
                        player->AddItem(26045);
                        CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    // 有2件
                    else if (has_26029 && has_26045)
                    {
                        player->GetSession()->SendNotification("已集齐职业橙装，奖励2000金币。");
                        player->ModifyMoney(2000 * GOLD);
                        CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    break;
                // WARLOCK
                case 9:
                    // 有0件
                    if (!has_26029 && !has_26047)
                    {
                        switch (urand(1,2))
                        {
                            case 1:
                                player->AddItem(26029);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 2:
                                player->AddItem(26047);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                        }
                    }
                    // 有1件
                    else if (!has_26029 && has_26047)
                    {
                        player->AddItem(26029);
                        CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    else if (has_26029 && !has_26047)
                    {
                        player->AddItem(26047);
                        CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    // 有2件
                    else if (has_26029 && has_26047)
                    {
                        player->GetSession()->SendNotification("已集齐职业橙装，奖励2000金币。");
                        player->ModifyMoney(2000 * GOLD);
                        CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    break;
                // DRUID
                case 11:
                    // 有0件
                    if (!has_26029 && !has_26034 && !has_26035 && !has_26037)
                    {
                        switch (urand(1,4))
                        {
                            case 1:
                                player->AddItem(26029);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 2:
                                player->AddItem(26034);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 3:
                                player->AddItem(26035);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 4:
                                player->AddItem(26037);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                        }
                    }
                    // 有1件
                    else if (has_26029 && !has_26034 && !has_26035 && !has_26037)
                    {
                        switch (urand(1,3))
                        {
                            case 1:
                                player->AddItem(26034);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 2:
                                player->AddItem(26035);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 3:
                                player->AddItem(26037);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                        }
                    }
                    else if (!has_26029 && has_26034 && !has_26035 && !has_26037)
                    {
                        switch (urand(1,3))
                        {
                            case 1:
                                player->AddItem(26029);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 2:
                                player->AddItem(26035);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 3:
                                player->AddItem(26037);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                        }
                    }
                    else if (!has_26029 && !has_26034 && has_26035 && !has_26037)
                    {
                        switch (urand(1,3))
                        {
                            case 1:
                                player->AddItem(26029);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 2:
                                player->AddItem(26034);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 3:
                                player->AddItem(26037);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                        }
                    }
                    else if (!has_26029 && !has_26034 && !has_26035 && has_26037)
                    {
                        switch (urand(1,3))
                        {
                            case 1:
                                player->AddItem(26029);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 2:
                                player->AddItem(26034);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 3:
                                player->AddItem(26035);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                        }
                    }
                    // 有2件
                    else if (has_26029 && has_26034 && !has_26035 && !has_26037)
                    {
                        switch (urand(1,2))
                        {
                            case 1:
                                player->AddItem(26035);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 2:
                                player->AddItem(26037);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                        }
                    }
                    else if (has_26029 && !has_26034 && has_26035 && !has_26037)
                    {
                        switch (urand(1,2))
                        {
                            case 1:
                                player->AddItem(26034);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 2:
                                player->AddItem(26037);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                        }
                    }
                    else if (has_26029 && !has_26034 && !has_26035 && has_26037)
                    {
                        switch (urand(1,2))
                        {
                            case 1:
                                player->AddItem(26034);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 2:
                                player->AddItem(26035);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                        }
                    }
                    else if (!has_26029 && has_26034 && has_26035 && !has_26037)
                    {
                        switch (urand(1,2))
                        {
                            case 1:
                                player->AddItem(26029);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 2:
                                player->AddItem(26037);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                        }
                    }
                    else if (!has_26029 && has_26034 && !has_26035 && has_26037)
                    {
                        switch (urand(1,2))
                        {
                            case 1:
                                player->AddItem(26029);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 2:
                                player->AddItem(26035);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                        }
                    }
                    else if (!has_26029 && !has_26034 && has_26035 && has_26037)
                    {
                        switch (urand(1,2))
                        {
                            case 1:
                                player->AddItem(26029);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                            case 2:
                                player->AddItem(26034);
                                CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                                player->CLOSE_GOSSIP_MENU();
                                break;
                        }
                    }
                    // 有3件
                    else if (!has_26029 && has_26034 && has_26035 && has_26037)
                    {
                        player->AddItem(26029);
                        CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    else if (has_26029 && !has_26034 && has_26035 && has_26037)
                    {
                        player->AddItem(26034);
                        CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    else if (has_26029 && has_26034 && !has_26035 && has_26037)
                    {
                        player->AddItem(26035);
                        CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    else if (has_26029 && has_26034 && has_26035 && !has_26037)
                    {
                        player->AddItem(26037);
                        CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    // 有4件
                    else if (has_26029 && has_26034 && has_26035 && has_26037)
                    {
                        player->GetSession()->SendNotification("已集齐职业橙装，奖励4000金币。");
                        player->ModifyMoney(4000 * GOLD);
                        CharacterDatabase.PExecute("REPLACE INTO `hardcore_reward` (`guid`, `name`, `class`) VALUES (%u, '%s', %u)", player->GetGUIDLow(), player->GetName(), player->GetClass());
                        player->CLOSE_GOSSIP_MENU();
                    }
                    break;
            }
            std::string className = "";
            switch (player->GetClass())
            {
              case 1:
                className = "战士";
                break;
              case 2:
                className = "圣骑士";
                break;
              case 3:
                className = "猎人";
                break;
              case 4:
                className = "盗贼";
                break;
              case 5:
                className = "牧师";
                break;
              case 7:
                className = "萨满";
                break;
              case 8:
                className = "法师";
                break;
              case 9:
                className = "术士";
                break;
              case 11:
                className = "德鲁伊";
                break;
            }
            std::string str = "恭喜玩家：";
            str.append(player->GetName());
            str.append("完成硬核挑战，成为服务器第一个满级");
            str.append(className+"。专属奖励已发放。");
            sWorld.SendServerMessage(SERVER_MSG_CUSTOM, str.c_str());
            break;
    }
}
bool GossipSelect_Hardcore_Reward_NPC(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
    // Main menu
    if (sender == GOSSIP_SENDER_MAIN)
        SendDefaultMenu_Hardcore_Reward_NPC(player, _Creature, action);

    return true;
}

// TELEPORT NPC

bool GossipHello_TeleportNPC(Player *player, Creature *_Creature)   
{
    // HORDE
    if (player->GetTeam() == HORDE)
    {
        // player->ADD_GOSSIP_ITEM(5, "PreTBC Mall",             GOSSIP_SENDER_MAIN, 74);
        player->ADD_GOSSIP_ITEM(5, "部落主城",               GOSSIP_SENDER_MAIN, 1);
        player->ADD_GOSSIP_ITEM(5, "种族出生地",             GOSSIP_SENDER_MAIN, 3);
        player->ADD_GOSSIP_ITEM(5, "地下城",                  GOSSIP_SENDER_MAIN, 5);
        player->ADD_GOSSIP_ITEM(5, "团队副本",                      GOSSIP_SENDER_MAIN, 101);
        player->ADD_GOSSIP_ITEM(5, "古拉巴什竞技场",            GOSSIP_SENDER_MAIN, 4015);
        player->ADD_GOSSIP_ITEM(5, "卡利姆多区域",           GOSSIP_SENDER_MAIN, 6010);
        player->ADD_GOSSIP_ITEM(5, "东部王国区域",   GOSSIP_SENDER_MAIN, 6020);

        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
    }
    // ALLIANCE
    else
    {
        //player->ADD_GOSSIP_ITEM(5, "PreTBC Mall",              GOSSIP_SENDER_MAIN, 74);
        player->ADD_GOSSIP_ITEM(5, "联盟主城",               GOSSIP_SENDER_MAIN, 2);
        player->ADD_GOSSIP_ITEM(5, "种族出生地",             GOSSIP_SENDER_MAIN, 4);
        player->ADD_GOSSIP_ITEM(5, "地下城",                  GOSSIP_SENDER_MAIN, 5);
        player->ADD_GOSSIP_ITEM(5, "团队副本",                      GOSSIP_SENDER_MAIN, 101);
        player->ADD_GOSSIP_ITEM(5, "古拉巴什竞技场",            GOSSIP_SENDER_MAIN, 4015);
        player->ADD_GOSSIP_ITEM(5, "卡利姆多区域",           GOSSIP_SENDER_MAIN, 6010);
        player->ADD_GOSSIP_ITEM(5, "东部王国区域",   GOSSIP_SENDER_MAIN, 6020);

        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
    }
    return true;
}

void SendDefaultMenu_TeleportNPC(Player *player, Creature *_Creature, uint32 action)
{
    uint32 travelboots = sWorld.getConfig(CONFIG_UINT32_PRICE_TRAVELBOOTS);
    std::string costprice;
    if (travelboots > 10000 * GOLD)
        travelboots = 10000 * GOLD;
    if (travelboots >= GOLD)
    {
        costprice = "传送费用：" + std::to_string(travelboots / GOLD) + "金币" + std::to_string((travelboots % GOLD) / SILVER) + "银币" + std::to_string(travelboots % SILVER) + "铜币";
    }
    else if (travelboots >= SILVER && travelboots < GOLD)
    {
        costprice = "传送费用：" + std::to_string(travelboots / SILVER) + "银币" + std::to_string(travelboots % SILVER) + "铜币";
    }
    else if (travelboots < SILVER)
    {
        costprice = "传送费用：" + std::to_string(travelboots) + "铜币";
    }

    switch (action)
    {
        case 1: // Cities [HORDE]
            player->ADD_GOSSIP_ITEM(5, "奥格瑞玛",                 GOSSIP_SENDER_MAIN, 20);
            player->ADD_GOSSIP_ITEM(5, "幽暗城",                 GOSSIP_SENDER_MAIN, 21);
            player->ADD_GOSSIP_ITEM(5, "雷霆崖",              GOSSIP_SENDER_MAIN, 22);
            //player->ADD_GOSSIP_ITEM(5, "Goldshire (Stormwind)",   GOSSIP_SENDER_MAIN, 4018);
            player->ADD_GOSSIP_ITEM(7, "<-[主菜单]",             GOSSIP_SENDER_MAIN, 100);

            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            break;
        case 2: // Cities [ALLIANCE]
            player->ADD_GOSSIP_ITEM(5, "暴风城",            GOSSIP_SENDER_MAIN, 23);
            player->ADD_GOSSIP_ITEM(5, "铁炉堡",                 GOSSIP_SENDER_MAIN, 24);
            player->ADD_GOSSIP_ITEM(5, "达纳苏斯",                 GOSSIP_SENDER_MAIN, 25);
            //player->ADD_GOSSIP_ITEM(5, "Razor Hill(Orgrimmar)",   GOSSIP_SENDER_MAIN, 4017);
            player->ADD_GOSSIP_ITEM(7, "<-[主菜单]",             GOSSIP_SENDER_MAIN, 100);

            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            break;
        case 3: // Starting Places [HORDE]
            player->ADD_GOSSIP_ITEM(5, "亡灵-灰影墓穴",       GOSSIP_SENDER_MAIN, 40);
            player->ADD_GOSSIP_ITEM(5, "兽人&巨魔-试炼谷",   GOSSIP_SENDER_MAIN, 41);
            player->ADD_GOSSIP_ITEM(5, "牛头人-纳拉其营地",       GOSSIP_SENDER_MAIN, 42);
            player->ADD_GOSSIP_ITEM(7, "<-[主菜单]",      GOSSIP_SENDER_MAIN, 100);

            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            break;
        case 4: // Starting Places [ALLIANCE]
            player->ADD_GOSSIP_ITEM(5, "人类-北郡山谷",   GOSSIP_SENDER_MAIN, 43);
            player->ADD_GOSSIP_ITEM(5, "矮人&侏儒-寒脊山谷",    GOSSIP_SENDER_MAIN, 44);
            player->ADD_GOSSIP_ITEM(5, "暗夜精灵-幽影谷",          GOSSIP_SENDER_MAIN, 45);
            player->ADD_GOSSIP_ITEM(7, "<-[主菜单]",       GOSSIP_SENDER_MAIN, 100);

            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            break;
        case 5: // Instances [PAGE 1]
            player->ADD_GOSSIP_ITEM(5, "哀嚎洞穴 17-20级",   GOSSIP_SENDER_MAIN, 1249);
            player->ADD_GOSSIP_ITEM(5, "死亡矿井 17-20级",             GOSSIP_SENDER_MAIN, 1250);
            player->ADD_GOSSIP_ITEM(5, "影牙城堡 18-21级",       GOSSIP_SENDER_MAIN, 1251);
            player->ADD_GOSSIP_ITEM(5, "黑暗深渊 21-24级",     GOSSIP_SENDER_MAIN, 1252);
            player->ADD_GOSSIP_ITEM(5, "剃刀沼泽 24-27级",        GOSSIP_SENDER_MAIN, 1254);
            player->ADD_GOSSIP_ITEM(5, "剃刀高地 34-37级",        GOSSIP_SENDER_MAIN, 1256);
            player->ADD_GOSSIP_ITEM(5, "血色修道院 29-40级",     GOSSIP_SENDER_MAIN, 1257);
            player->ADD_GOSSIP_ITEM(7, "[更多] ->",             GOSSIP_SENDER_MAIN, 5551);
            player->ADD_GOSSIP_ITEM(7, "<-[主菜单]",         GOSSIP_SENDER_MAIN, 100);

            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            break;
        case 5551: // Instances [PAGE 2]
            player->ADD_GOSSIP_ITEM(5, "奥达曼 37-40级",             GOSSIP_SENDER_MAIN, 1258);
            player->ADD_GOSSIP_ITEM(5, "祖尔法拉克 43-46级",          GOSSIP_SENDER_MAIN, 1259);
            player->ADD_GOSSIP_ITEM(5, "玛拉顿 41-48级",            GOSSIP_SENDER_MAIN, 1260);
            player->ADD_GOSSIP_ITEM(5, "沉没的神庙 47-50级",   GOSSIP_SENDER_MAIN, 1261);
            player->ADD_GOSSIP_ITEM(5, "黑石深渊 49-56级",    GOSSIP_SENDER_MAIN, 1262);
            player->ADD_GOSSIP_ITEM(5, "厄运之槌 55-60级",           GOSSIP_SENDER_MAIN, 1263);
            player->ADD_GOSSIP_ITEM(5, "黑石塔 57-60级",     GOSSIP_SENDER_MAIN, 1264);
            player->ADD_GOSSIP_ITEM(5, "斯坦索姆 55-60级",          GOSSIP_SENDER_MAIN, 1265);
            player->ADD_GOSSIP_ITEM(5, "通灵学院 55-60级",         GOSSIP_SENDER_MAIN, 1266);
            player->ADD_GOSSIP_ITEM(7, "[更多] ->",             GOSSIP_SENDER_MAIN, 5552);
            player->ADD_GOSSIP_ITEM(7, "<- [后退]",           GOSSIP_SENDER_MAIN, 5);
            player->ADD_GOSSIP_ITEM(7, "<-[主菜单]",       GOSSIP_SENDER_MAIN, 100);

            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            break;
        case 5552: // Instances [PAGE 3]
            player->ADD_GOSSIP_ITEM(5, "暴风城金库 60级",             GOSSIP_SENDER_MAIN, 1267);
            player->ADD_GOSSIP_ITEM(5, "时光之穴 60级",             GOSSIP_SENDER_MAIN, 1268);
            player->ADD_GOSSIP_ITEM(5, "卡拉赞 60级",          GOSSIP_SENDER_MAIN, 1269);
            player->ADD_GOSSIP_ITEM(5, "翡翠圣所 60级",            GOSSIP_SENDER_MAIN, 1270);
            player->ADD_GOSSIP_ITEM(5, "仇恨熔炉 60级",   GOSSIP_SENDER_MAIN, 1271);
            player->ADD_GOSSIP_ITEM(5, "冬幕谷 60级",    GOSSIP_SENDER_MAIN, 1272);
            player->ADD_GOSSIP_ITEM(5, "亚楠镇 60级",           GOSSIP_SENDER_MAIN, 1273);
            player->ADD_GOSSIP_ITEM(5, "凄凉山 60级",           GOSSIP_SENDER_MAIN, 1274);
            player->ADD_GOSSIP_ITEM(5, "修道院 60级",           GOSSIP_SENDER_MAIN, 1275);
            player->ADD_GOSSIP_ITEM(7, "[更多] ->",             GOSSIP_SENDER_MAIN, 5553);
            player->ADD_GOSSIP_ITEM(7, "<- [后退]",           GOSSIP_SENDER_MAIN, 5551);
            player->ADD_GOSSIP_ITEM(7, "<-[主菜单]",       GOSSIP_SENDER_MAIN, 100);

            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            break;
        case 5553: // Instances [PAGE 4]
            player->ADD_GOSSIP_ITEM(5, "德拉诺 60级",           GOSSIP_SENDER_MAIN, 1276);
            player->ADD_GOSSIP_ITEM(5, "血环竞技场 60级",             GOSSIP_SENDER_MAIN, 1277);
            player->ADD_GOSSIP_ITEM(5, "旧铁炉堡 60级",          GOSSIP_SENDER_MAIN, 1278);
            player->ADD_GOSSIP_ITEM(5, "星露谷 60级",            GOSSIP_SENDER_MAIN, 1279);
            player->ADD_GOSSIP_ITEM(5, "新月林地 60级",   GOSSIP_SENDER_MAIN, 1280);
            player->ADD_GOSSIP_ITEM(7, "<- [后退]",           GOSSIP_SENDER_MAIN, 5552);
            player->ADD_GOSSIP_ITEM(7, "<-[主菜单]",       GOSSIP_SENDER_MAIN, 100);

            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            break;
        case 101: // Raids
            player->ADD_GOSSIP_ITEM(5, "祖尔格拉布 20人",             GOSSIP_SENDER_MAIN, 4000);
            player->ADD_GOSSIP_ITEM(5, "奥妮克希亚的巢穴 40人",         GOSSIP_SENDER_MAIN, 4001);
            player->ADD_GOSSIP_ITEM(5, "熔火之心 40人 t1",           GOSSIP_SENDER_MAIN, 4002);
            player->ADD_GOSSIP_ITEM(5, "黑翼之巢 40人 t2",        GOSSIP_SENDER_MAIN, 4003);
            player->ADD_GOSSIP_ITEM(5, "安其拉废墟 20人",    GOSSIP_SENDER_MAIN, 4004);
            player->ADD_GOSSIP_ITEM(5, "安其拉神殿 40人 t2.5",   GOSSIP_SENDER_MAIN, 4005);
            player->ADD_GOSSIP_ITEM(5, "纳克萨玛斯 40人 t3",             GOSSIP_SENDER_MAIN, 4006);
            player->ADD_GOSSIP_ITEM(7, "<-[主菜单]",         GOSSIP_SENDER_MAIN, 100);

            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            break;
        case 6010: // Kalimdor
            player->ADD_GOSSIP_ITEM(5, "灰谷",              GOSSIP_SENDER_MAIN, 601);
            player->ADD_GOSSIP_ITEM(5, "黑海岸",              GOSSIP_SENDER_MAIN, 602);
            player->ADD_GOSSIP_ITEM(5, "凄凉之地",               GOSSIP_SENDER_MAIN, 603);
            player->ADD_GOSSIP_ITEM(5, "杜隆塔尔",                GOSSIP_SENDER_MAIN, 604);
            player->ADD_GOSSIP_ITEM(5, "尘泥沼泽",       GOSSIP_SENDER_MAIN, 605);
            player->ADD_GOSSIP_ITEM(5, "菲拉斯",                GOSSIP_SENDER_MAIN, 606);
            player->ADD_GOSSIP_ITEM(5, "希利苏斯",               GOSSIP_SENDER_MAIN, 607);
            player->ADD_GOSSIP_ITEM(5, "石爪山脉",   GOSSIP_SENDER_MAIN, 608);
            player->ADD_GOSSIP_ITEM(5, "塔纳利斯",                GOSSIP_SENDER_MAIN, 609);
            player->ADD_GOSSIP_ITEM(5, "贫瘠之地",            GOSSIP_SENDER_MAIN, 610);
            player->ADD_GOSSIP_ITEM(5, "千针石林",       GOSSIP_SENDER_MAIN, 611);
            player->ADD_GOSSIP_ITEM(5, "冬泉谷",           GOSSIP_SENDER_MAIN, 612);
            player->ADD_GOSSIP_ITEM(7, "<-[主菜单]",          GOSSIP_SENDER_MAIN, 100);

            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            break;
        case 6020: // Eastern Kingdoms [PAGE 1]
            player->ADD_GOSSIP_ITEM(5, "阿拉希高地",     GOSSIP_SENDER_MAIN, 613);
            player->ADD_GOSSIP_ITEM(5, "荒芜之地",             GOSSIP_SENDER_MAIN, 614);
            player->ADD_GOSSIP_ITEM(5, "丹莫罗",           GOSSIP_SENDER_MAIN, 615);
            player->ADD_GOSSIP_ITEM(5, "暮色森林",             GOSSIP_SENDER_MAIN, 616);
            player->ADD_GOSSIP_ITEM(5, "东瘟疫之地",  GOSSIP_SENDER_MAIN, 617);
            player->ADD_GOSSIP_ITEM(5, "艾尔文森林",        GOSSIP_SENDER_MAIN, 618);
            player->ADD_GOSSIP_ITEM(5, "希尔斯布莱德丘陵",  GOSSIP_SENDER_MAIN, 619);
            player->ADD_GOSSIP_ITEM(5, "赤脊山",   GOSSIP_SENDER_MAIN, 620);
            player->ADD_GOSSIP_ITEM(5, "银松森林",    GOSSIP_SENDER_MAIN, 621);
            player->ADD_GOSSIP_ITEM(7, "[更多] ->",            GOSSIP_SENDER_MAIN, 6021);
            player->ADD_GOSSIP_ITEM(7, "<-[主菜单]",        GOSSIP_SENDER_MAIN, 100);

            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            break;
        case 6021: // Eastern Kingdoms [PAGE 2]
            player->ADD_GOSSIP_ITEM(5, "荆棘谷",   GOSSIP_SENDER_MAIN, 622);
            player->ADD_GOSSIP_ITEM(5, "悲伤沼泽",     GOSSIP_SENDER_MAIN, 623);
            player->ADD_GOSSIP_ITEM(5, "辛特兰",      GOSSIP_SENDER_MAIN, 624);
            player->ADD_GOSSIP_ITEM(5, "提瑞斯法林地",      GOSSIP_SENDER_MAIN, 625);
            player->ADD_GOSSIP_ITEM(5, "西部荒野",             GOSSIP_SENDER_MAIN, 626);
            player->ADD_GOSSIP_ITEM(5, "湿地",             GOSSIP_SENDER_MAIN, 627);
            player->ADD_GOSSIP_ITEM(7, "<- [后退]",            GOSSIP_SENDER_MAIN, 6020);
            player->ADD_GOSSIP_ITEM(7, "<-[主菜单]",        GOSSIP_SENDER_MAIN, 100);

            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            break;

// ----### CITIES ###----

// ### HORDE ###

        case 20: // Orgrimmar
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_KALIMDOR, 1437.0f, -4421.0f, 25.24f, 1.65f);
            break;
        case 21: // Undercity
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_EASTERN_KINGDOMS, 1822.0999f, 238.638855f, 60.694809f, 0.0f);
            break;
        case 22: // Thunderbluff
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_KALIMDOR, -1272.703735f, 116.886490f, 131.016861f, 0.0f);
            break;

// ### ALLIANCE ###

        case 23: // Stormwind
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_EASTERN_KINGDOMS, -8828.231445f, 627.927490f, 94.055664f, 0.0f);
            break;
        case 24: // Ironforge
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_EASTERN_KINGDOMS, -4917.0f, -955.0f, 502.0f, 0.0f);
            break;
        case 25: // Darnassus
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_KALIMDOR, 9962.712891f, 2280.142822f, 1341.394409f, 0.0f);
            break;

// ----### STARTING PLACES ####----

// ### HORDE ###

        case 40: // Shadow Grave
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_EASTERN_KINGDOMS, 1663.517f, 1678.187744f, 120.5303f, 0.0f);
            break;
        case 41: // Valley of Trials
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_KALIMDOR, -602.1253f, -4262.4208f, 38.956341f, 0.0f);
            break;
        case 42: // Camp Narache
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_KALIMDOR, -2914.16992f, -266.061798f, 53.658211f, 0.0f);
            break;

// ### ALLIANCE ###

        case 43: // Nortshire Valley
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_EASTERN_KINGDOMS, -8943.133789f, -132.934921f, 83.704269f, 0.0f);
            break;
        case 44: // Coldridge Valley
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_EASTERN_KINGDOMS, -6231.106445f, 332.270477f, 383.153931f, 0.0f);
            break;
        case 45: // Shadowglen
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_KALIMDOR, 10329.918945f, 833.500305f, 1326.260620f, 0.0f);
            break;

// ----### INSTANCES ###----

        case 50: // Dire Maul
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_KALIMDOR, -3762.340820f, 1216.537598f, 127.434608f, 0.0f);
            break;
        case 51: // Blackrock Spire
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_EASTERN_KINGDOMS, -7528.554688f, -1222.907227f, 285.732941f, 0.0f);
            break;
        case 52: // Zul'Gurub
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_EASTERN_KINGDOMS, -11916.179688f, -1190.977051f, 85.137901f, 0.0f);
            break;
        case 53: // Onyxia's Lair
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_KALIMDOR, -4682.391602f, -3709.857422f, 46.792862f, 0.0f);
            break;
        case 54: // Searing Gorge (Moltencore, Blackwinglair)
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_EASTERN_KINGDOMS, -7342.270020f, -1096.863892f, 277.06930f, 0.0f);
            break;
        case 55: // Naxxramas
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_EASTERN_KINGDOMS, 3121.061768f, -3689.973389f, 133.458786f, 0.0f);
            break;
        case 56: // Stratholme Backdoor Entrance
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_EASTERN_KINGDOMS, 3160.416992f, -4038.750244f, 104.177376f, 0.0f);
            break;
        case 57: // Stratholme Main Entrance
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_EASTERN_KINGDOMS, 3357.214355f, -3379.713135f, 144.780853f, 0.0f);
            break;
        case 58: // Scholomance
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_EASTERN_KINGDOMS, 1252.319824f, -2587.151123f, 92.886772f, 0.0f);
            break;

// ---### ZONES ###---

        case 70: // Silithus
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_KALIMDOR, -7430.070313f, 1002.554565f, 1.249787f, 0.0f);
            break;
        case 71: // Durotar
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_KALIMDOR, 1006.426819f, -4439.258789f, 11.352882f, 0.0f);
            break;
        case 72: // Ashenvale
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_KALIMDOR, 1922.842651f, -2169.429688f, 94.327400f, 0.0f);
            break;
        case 73: // Tanaris
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_KALIMDOR, -7180.401367f, -3773.328369f, 8.728320f, 0.0f);
            break;
        case 74: // Pretbc Mall
            //player->CLOSE_GOSSIP_MENU();
            //if(player->GetMoney() < travelboots)
            //{
            //    player->GetSession()->SendNotification(costprice.c_str());
            //    break;
            //}
            //player->ModifyMoney(-travelboots);
            //player->TeleportTo(MAP_KALIMDOR, 16201.107422f, 16205.1875f, 0.140072f, 1.630427f);
            break;
        case 4015:// Gurubashi
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_EASTERN_KINGDOMS, -13261.3f, 168.294f, 35.0792f, 1.00688f);
            break;
        case 4017:// Razor Hill
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_KALIMDOR, 315.721f, -4743.4f, 10.4867f, 0.0f);
            break;
        case 4018:// Goldshire
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_EASTERN_KINGDOMS, -9464.0f, 62.0f, 56.0f, 0.0f);
            break;
        case 1249:// Teleport player to the Wailing Caverns
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_KALIMDOR, -722.53f, -2226.30f, 16.94f, 2.71f);
            break;
        case 1250:// Teleport player to the Deadmines
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_EASTERN_KINGDOMS, -11212.04f, 1658.58f, 25.67f, 1.45f);
            break;
        case 1251:// Teleport player to Shadowfang Keep
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_EASTERN_KINGDOMS, -254.47f, 1524.68f, 76.89f, 1.56f);
            break;
        case 1252:// Teleport player to Blackfathom Deeps
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_KALIMDOR, 4254.58f, 664.74f, -29.04f, 1.97f);
            break;
        case 1254:// Teleport player to Razorfen Kraul
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_KALIMDOR, -4484.04f, -1739.40f, 86.47f, 1.23f);
            break;
        case 1256:// Teleport player to Razorfen Downs
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_KALIMDOR, -4645.08f, -2470.85f, 85.53f, 4.39f);
            break;
        case 1257:// Teleport player to the Scarlet Monastery
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_EASTERN_KINGDOMS, 2843.89f, -693.74f, 139.32f, 5.11f);
            break;
        case 1258:// Teleport player to Uldaman
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_EASTERN_KINGDOMS, -6119.70f, -2957.30f, 204.11f, 0.03f);
            break;
        case 1259:// Teleport player to Zul'Farrak
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_KALIMDOR, -6839.39f, -2911.03f, 8.87f, 0.41f);
            break;
        case 1260:// Teleport player to Maraudon
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_KALIMDOR, -1433.33f, 2955.34f, 96.21f, 4.82f);
            break;
        case 1261:// Teleport player to the Sunken Temple
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_EASTERN_KINGDOMS, -10346.92f, -3851.90f, -43.41f, 6.09f);
            break;
        case 1262:// Teleport player to Blackrock Depths
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_EASTERN_KINGDOMS, -7301.03f, -913.19f, 165.37f, 0.08f);
            break;
        case 1263:// Teleport player to Dire Maul
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_KALIMDOR, -3982.47f, 1127.79f, 161.02f, 0.05f);
            break;
        case 1264:// Teleport player to Blackrock Spire
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_EASTERN_KINGDOMS, -7535.43f, -1212.04f, 285.45f, 5.29f);
            break;
        case 1265:// Teleport player to Stratholme
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_EASTERN_KINGDOMS, 3263.54f, -3379.46f, 143.59f, 0.00f);
            break;
        case 1266:// Teleport player to Scholomance
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_EASTERN_KINGDOMS, 1219.01f, -2604.66f, 85.61f, 0.50f);
            break;
        case 1267:// Teleport player to StormwindVault
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_EASTERN_KINGDOMS, -9362.088867f, 539.202637f, 47.111515f, 0.00f);
            break;
        case 1268:// Teleport player to CavernsOfTime
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_KALIMDOR, -8510.25f, -4391.74f, -218.636f, 0.00f);
            break;
        case 1269:// Teleport player to Karazahn
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_EASTERN_KINGDOMS, -11120.826172f, -2012.403687f, 47.094982f, 0.00f);
            break;
        case 1270:// Teleport player to EmeraldSanctum
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_KALIMDOR, 7815.447266f, -2857.259766f, 459.636658f, 0.00f);
            break;
        case 1271:// Teleport player to Hateforge
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_EASTERN_KINGDOMS, -8149.071289f, -3020.921631f, 134.421799f, 0.00f);
            break;
        case 1272:// Teleport player to Winterveil
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_KALIMDOR, 6723.171387f, -5282.243652f, 779.779480f, 0.00f);
            break;
        case 1273:// Teleport player to Yharnam
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_EASTERN_KINGDOMS, -733.396729f, 1536.514160f, 16.620735f, 0.00f);
            break;
        case 1274:// Teleport player to DesolateMountain
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_KALIMDOR, 2948.08f, -4261.04f, 103.785f, 0.00f);
            break;
        case 1275:// Teleport player to Monastery
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_EASTERN_KINGDOMS, 2875.06f, -633.725f, 137.839f, 0.00f);
            break;
        case 1276:// Teleport player to Draenor
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_EASTERN_KINGDOMS, -11865.1f, -3203.32f, -22.8171f, 0.00f);
            break;
        case 1277:// Teleport player to BloodRing
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_EASTERN_KINGDOMS, -492.673553f, -1570.729370f, 52.666183f, 0.00f);
            break;
        case 1278:// Teleport player to OldIronforge
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_EASTERN_KINGDOMS, -5618.981934, -830.361633, 483.534393, 0.00f);
            break;
        case 1279:// Teleport player to StardewValley
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_KALIMDOR, -6560.617188f, -545.094299f, -254.334824f, 0.00f);
            break;
        case 1280:// Teleport player to CrescentGrove
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_EASTERN_KINGDOMS, -213.140915f, -2522.304688f, 118.503098f, 0.00f);
            break;
        case 4000:// Teleport to Zul'Gurub
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_EASTERN_KINGDOMS, -11916.7f, -1212.82f, 92.2868f, 4.6095f);
            break;
        case 4001:// Teleport to Onyxia's Lair
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_KALIMDOR, -4707.44f, -3726.82f, 54.6723f, 3.8f);
            break;
        case 4002:// Teleport to Molten Core
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(230, 1121.451172f, -454.316772f, -101.329536f, 3.5f);
            break;
        case 4003:// Teleport to Blackwing Lair
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(469, -7665.55f, -1102.49f, 400.679f, 0.0f);
            break;
        case 4004:// Ruins of Ahn'Qiraj
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_KALIMDOR, -8409.032227f, 1498.830933f, 27.361542f, 2.497567f);
            break;
        case 4005:// Temple of Ahn'Qiraj
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_KALIMDOR, -8245.837891f, 1983.736206f, 129.071686f, 0.936195f);
            break;
        case 4006:// Naxxramas
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_EASTERN_KINGDOMS, 3081.08f, -3777.97f, 129.12f, 0.497555f);
            break;
        case 601: // Kalimdor -> Ashenvale
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_KALIMDOR, 3469.43f, 847.62f, 6.36476f, 0.0f);
            break;
        case 602: // Kalimdor -> Darkshore
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_KALIMDOR, 6207.5f, -152.833f, 80.8185f, 0.0f);
            break;
        case 603: // Kalimdor -> Desolace
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_KALIMDOR, -93.1614f, 1691.15f, 90.0649f, 0.0f);
            break;
        case 604: // Kalimdor -> Durotar
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_KALIMDOR, 341.42f, -4684.7f, 31.9493f, 0.0f);
            break;
        case 605: // Kalimdor -> Duswallow Marsh
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_KALIMDOR, -3463.26f, -4123.13f, 18.1043f, 0.0f);
            break;
        case 606: // Kalimdor -> Ferelas
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_KALIMDOR, -4458.93f, 243.415f, 65.6136f, 0.0f);
            break;
        case 607: // Kalimdor -> Silithus
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_KALIMDOR, -6824.15f, 821.273f, 50.6675f, 0.0f);
            break;
        case 608: // Kalimdor -> Stonetalon Mountains
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_KALIMDOR, 1145.00f, 85.664f, -6.64f, 0.0f);
            break;
        case 609: // Kalimdor -> Tanaris
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_KALIMDOR, -7373.69f, -2950.2f, 11.7598f, 0.0f);
            break;
        case 610: // Kalimdor -> The Barrens
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_KALIMDOR, -456.263f, -2652.7f, 96.615f, 0.0f);
            break;
        case 611: // Kalimdor -> Thousand Needles
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_KALIMDOR, -4941.66f, -1595.42f, -33.07f, 0.0f);
            break;
        case 612: // Kalimdor -> Winterspring
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_KALIMDOR, 6107.62f, -4181.6f, 853.322f, 0.0f);
            break;
        case 613: // Eastern Kingdoms -> Arathi Highlands
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_EASTERN_KINGDOMS, -1544.93f, -2495.01f, 54.11f, 0.0f);
            break;
        case 614: // Eastern Kingdoms -> Badlands
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_EASTERN_KINGDOMS, -6084.95f, -3328.44f, 253.76f, 0.0f);
            break;
        case 615: // Eastern Kingdoms -> Dun Morogh
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_EASTERN_KINGDOMS, -5660.33f, 755.299f, 390.605f, 0.0f);
            break;
        case 616: // Eastern Kingdoms -> Duskwood
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_EASTERN_KINGDOMS, -10879.85f, -327.06f, 37.78f, 0.0f);
            break;
        case 617: // Eastern Kingdoms -> Eastern Plaguelands
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_EASTERN_KINGDOMS, 2280.12f, -5313.16f, 87.74f, 0.0f);
            break;
        case 618: // Eastern Kingdoms -> Elwynn Forest
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_EASTERN_KINGDOMS, -9545.78f, -51.81f, 56.72f, 0.0f);
            break;
        case 619: // Eastern Kingdoms -> Hillsbrad Foothills
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_EASTERN_KINGDOMS, -436.03f, -583.27f, 53.58f, 0.0f);
            break;
        case 620: // Eastern Kingdoms -> Reridge Mountains
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_EASTERN_KINGDOMS, -9633.80f, -1875.09f, 68.39f, 0.0f);
            break;
        case 621: // Eastern Kingdoms -> Silverpine Forest
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_EASTERN_KINGDOMS, 641.48f, 1297.84f, 85.45f, 0.0f);
            break;
        case 622: // Eastern Kingdoms -> Stranglethorn Vale
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_EASTERN_KINGDOMS, -11393.77f, -288.94f, 58.99f, 0.0f);
            break;
        case 623: // Eastern Kingdoms -> Swamp of Sorrows
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_EASTERN_KINGDOMS, -10522.55f, -3028.30f, 21.79f, 0.0f);
            break;
        case 624: // Eastern Kingdoms -> The Hinterlands
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_EASTERN_KINGDOMS, 155.14f, -2014.95f, 122.55f, 0.0f);
            break;
        case 625: // Eastern Kingdoms -> Tirishfal Glades
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_EASTERN_KINGDOMS, 2255.5f, 288.511f, 35.1138f, 0.0f);
            break;
        case 626: // Eastern Kingdoms -> Westfall
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_EASTERN_KINGDOMS, -10919.09f, 998.47f, 35.47f, 0.0f);
            break;
        case 627: // Eastern Kingdoms -> Wetlands
            player->CLOSE_GOSSIP_MENU();
            if(player->GetMoney() < travelboots)
            {
                player->GetSession()->SendNotification(costprice.c_str());
                break;
            }
            player->ModifyMoney(-travelboots);
            player->TeleportTo(MAP_EASTERN_KINGDOMS, -4086.36f, -2610.95f, 47.0143f, 0.0f);
            break;

        case 100: // Main Menu
            // HORDE
            if (player->GetTeam() == HORDE)
            {
                //player->ADD_GOSSIP_ITEM(5, "PreTBC Mall",             GOSSIP_SENDER_MAIN, 74);
                player->ADD_GOSSIP_ITEM(5, "部落主城",              GOSSIP_SENDER_MAIN, 1);
                player->ADD_GOSSIP_ITEM(5, "种族出生地",            GOSSIP_SENDER_MAIN, 3);
                player->ADD_GOSSIP_ITEM(5, "地下城",                 GOSSIP_SENDER_MAIN, 5);
                player->ADD_GOSSIP_ITEM(5, "团队副本",                     GOSSIP_SENDER_MAIN, 101);
                player->ADD_GOSSIP_ITEM(5, "古拉巴什竞技场",           GOSSIP_SENDER_MAIN, 4015);
                player->ADD_GOSSIP_ITEM(5, "卡利姆多区域",          GOSSIP_SENDER_MAIN, 6010);
                player->ADD_GOSSIP_ITEM(5, "东部王国区域",  GOSSIP_SENDER_MAIN, 6020);

                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            }
            // ALLIANCE
            else
            {
                //player->ADD_GOSSIP_ITEM(5, "PreTBC Mall",             GOSSIP_SENDER_MAIN, 74);
                player->ADD_GOSSIP_ITEM(5, "联盟主城",              GOSSIP_SENDER_MAIN, 2);
                player->ADD_GOSSIP_ITEM(5, "种族出生地",            GOSSIP_SENDER_MAIN, 4);
                player->ADD_GOSSIP_ITEM(5, "地下城",                 GOSSIP_SENDER_MAIN, 5);
                player->ADD_GOSSIP_ITEM(5, "团队副本",                     GOSSIP_SENDER_MAIN, 101);
                player->ADD_GOSSIP_ITEM(5, "古拉巴什竞技场",           GOSSIP_SENDER_MAIN, 4015);
                player->ADD_GOSSIP_ITEM(5, "卡利姆多区域",          GOSSIP_SENDER_MAIN, 6010);
                player->ADD_GOSSIP_ITEM(5, "东部王国区域",  GOSSIP_SENDER_MAIN, 6020);

                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            }
            break;
    }
}
bool GossipSelect_TeleportNPC(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
    // Main menu
    if (sender == GOSSIP_SENDER_MAIN)
        SendDefaultMenu_TeleportNPC(player, _Creature, action);

    return true;
}

bool GossipHello_Chromie(Player *player, Creature *_Creature)   
{
    player->ADD_GOSSIP_ITEM(7, "黑暗力量已经渗透了时光之穴，尝试着改变过去、现在和未来的走向。时间的平衡危在旦夕，如果过去的历史无法被拯救……艾泽拉斯将不再有未来。",               GOSSIP_SENDER_MAIN, 1);
    player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
    return true;
}
void SendDefaultMenu_Chromie(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case 1:
            player->ADD_GOSSIP_ITEM(5, "传送：黑色沼泽",               GOSSIP_SENDER_MAIN, 2);
            player->ADD_GOSSIP_ITEM(5, "传送：旧希尔斯布莱德丘陵",             GOSSIP_SENDER_MAIN, 3);
            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            break;
        case 2:
            player->CLOSE_GOSSIP_MENU();
            if(player->GetLevel() < 60)
            {
                player->GetSession()->SendNotification("You must be at least level 60 to enter.");
                break;
            }
            player->TeleportTo(269, -2001.74f, 6576.61f, -154.822f, 0.0f);
            break;
        case 3:
            player->CLOSE_GOSSIP_MENU();
            if(player->GetLevel() < 60)
            {
                player->GetSession()->SendNotification("You must be at least level 60 to enter.");
                break;
            }
            player->TeleportTo(269, 2370.611f, 1167.000f, 64.1f, 0.0f);
            break;
    }
}
bool GossipSelect_Chromie(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
    // Main menu
    if (sender == GOSSIP_SENDER_MAIN)
        SendDefaultMenu_Chromie(player, _Creature, action);

    return true;
}

bool GossipHello_Black_Knight(Player *player, Creature *_Creature)   
{
    if (player->GetMapId() == 549 || player->GetMapId() == 541)
    {
        player->ADD_GOSSIP_ITEM(5, "离开副本",               GOSSIP_SENDER_MAIN, 1);
    }
    else
    {
        player->ADD_GOSSIP_ITEM(7, "卡拉赞曾属于艾泽拉斯大陆上最强的人：星界法师麦迪文。这里只有一条真理：进去以后，你或许永远也无法出来……",               GOSSIP_SENDER_MAIN, 2);
    }
    player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
    return true;
}
void SendDefaultMenu_Black_Knight(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case 1:
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(MAP_EASTERN_KINGDOMS, -11120.826172f, -2012.403687f, 47.094982f, 0.0f);
            break;
        case 2:
            player->ADD_GOSSIP_ITEM(5, "传送：卡拉赞之塔",               GOSSIP_SENDER_MAIN, 3);
            player->ADD_GOSSIP_ITEM(5, "传送：卡拉赞下层",               GOSSIP_SENDER_MAIN, 4);
            player->ADD_GOSSIP_ITEM(5, "传送：卡拉赞墓穴",             GOSSIP_SENDER_MAIN, 5);
            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            break;
        case 3:
            player->CLOSE_GOSSIP_MENU();
            if(player->GetLevel() < 60)
            {
                player->GetSession()->SendNotification("You must be at least level 60 to enter.");
                break;
            }
            player->TeleportTo(549, -11039.6f, -1997.65f, 94.0802f, 0.0f);
            break;
        case 4:
            player->CLOSE_GOSSIP_MENU();
            if(player->GetLevel() < 60)
            {
                player->GetSession()->SendNotification("You must be at least level 60 to enter.");
                break;
            }
            player->TeleportTo(549, -11101.692f, -1997.510f, 49.893f, 0.0f);
            break;
        case 5:
            player->CLOSE_GOSSIP_MENU();
            if(player->GetLevel() < 60)
            {
                player->GetSession()->SendNotification("You must be at least level 60 to enter.");
                break;
            }
            player->TeleportTo(541, -11068.1f, -1806.4f, 52.7f, 0.0f);
            break;
    }
}
bool GossipSelect_Black_Knight(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
    // Main menu
    if (sender == GOSSIP_SENDER_MAIN)
        SendDefaultMenu_Black_Knight(player, _Creature, action);

    return true;
}

bool GossipHello_Elven_Wisp(Player *player, Creature *_Creature)   
{
    if (player->GetMapId() == 542)
    {
        player->ADD_GOSSIP_ITEM(5, "离开副本",               GOSSIP_SENDER_MAIN, 1);
    }
    else
    {
        player->ADD_GOSSIP_ITEM(7, "在上一次冥想中进入翡翠梦境之后，玛法里奥迟迟未能醒来。德鲁伊们推断，某种可怕的东西已经越过绿龙的守护进入了翡翠圣所。",               GOSSIP_SENDER_MAIN, 2);
    }
    player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
    return true;
}
void SendDefaultMenu_Elven_Wisp(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case 1:
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(MAP_KALIMDOR, 7815.447266f, -2857.259766f, 459.636658f, 0.0f);
            break;
        case 2:
            player->ADD_GOSSIP_ITEM(5, "传送：翡翠圣所",               GOSSIP_SENDER_MAIN, 3);
            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            break;
        case 3:
            player->CLOSE_GOSSIP_MENU();
            if(player->GetLevel() < 60)
            {
                player->GetSession()->SendNotification("You must be at least level 60 to enter.");
                break;
            }
            player->TeleportTo(542, 2762.25f, 2972.77f, 26.903f, 0.0f);
            break;
    }
}
bool GossipSelect_Elven_Wisp(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
    // Main menu
    if (sender == GOSSIP_SENDER_MAIN)
        SendDefaultMenu_Elven_Wisp(player, _Creature, action);

    return true;
}

bool GossipHello_Twilight_Disciple(Player *player, Creature *_Creature)   
{
    if (player->GetMapId() == 543)
    {
        player->ADD_GOSSIP_ITEM(5, "离开副本",               GOSSIP_SENDER_MAIN, 1);
    }
    else
    {
        player->ADD_GOSSIP_ITEM(7, "巅峰产生虚伪的拥护，黄昏见证真正的使徒。上古之神归来，暮光审判将至。",               GOSSIP_SENDER_MAIN, 2);
    }
    player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
    return true;
}
void SendDefaultMenu_Twilight_Disciple(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case 1:
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(MAP_EASTERN_KINGDOMS, -8149.071289f, -3020.921631f, 134.421799f, 0.0f);
            break;
        case 2:
            player->ADD_GOSSIP_ITEM(5, "传送：仇恨熔炉",               GOSSIP_SENDER_MAIN, 3);
            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            break;
        case 3:
            player->CLOSE_GOSSIP_MENU();
            if(player->GetLevel() < 60)
            {
                player->GetSession()->SendNotification("You must be at least level 60 to enter.");
                break;
            }
            player->TeleportTo(543, -8170.91f, -3125.6f, 199.593f, 0.0f);
            break;
    }
}
bool GossipSelect_Twilight_Disciple(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
    // Main menu
    if (sender == GOSSIP_SENDER_MAIN)
        SendDefaultMenu_Twilight_Disciple(player, _Creature, action);

    return true;
}

bool GossipHello_Winterfall_Ursa(Player *player, Creature *_Creature)   
{
    if (player->GetMapId() == 544)
    {
        player->ADD_GOSSIP_ITEM(5, "离开副本",               GOSSIP_SENDER_MAIN, 1);
    }
    else
    {
        player->ADD_GOSSIP_ITEM(7, "欢迎来到冬幕谷，冒险者。冬天爷爷为大家准备了冬幕节礼物。",               GOSSIP_SENDER_MAIN, 2);
    }
    player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
    return true;
}
void SendDefaultMenu_Winterfall_Ursa(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case 1:
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(MAP_KALIMDOR, 6723.171387f, -5282.243652f, 779.779480f, 0.0f);
            break;
        case 2:
            player->ADD_GOSSIP_ITEM(5, "传送：冬幕谷",               GOSSIP_SENDER_MAIN, 3);
            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            break;
        case 3:
            player->CLOSE_GOSSIP_MENU();
            if(player->GetLevel() < 60)
            {
                player->GetSession()->SendNotification("You must be at least level 60 to enter.");
                break;
            }
            player->TeleportTo(544, -2653.06f, 1117.36f, 54.9084f, 0.0f);
            break;
    }
}
bool GossipSelect_Winterfall_Ursa(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
    // Main menu
    if (sender == GOSSIP_SENDER_MAIN)
        SendDefaultMenu_Winterfall_Ursa(player, _Creature, action);

    return true;
}

bool GossipHello_Yarntown(Player *player, Creature *_Creature)   
{
    if (player->GetMapId() == 545)
    {
        player->ADD_GOSSIP_ITEM(5, "离开梦境",               GOSSIP_SENDER_MAIN, 1);
    }
    else
    {
        player->ADD_GOSSIP_ITEM(7, "民风淳朴亚楠镇，热情好客不死街。美丽富饶苇名城，勤劳勇敢水生村。",               GOSSIP_SENDER_MAIN, 2);
    }
    player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
    return true;
}
void SendDefaultMenu_Yarntown(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case 1:
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(MAP_EASTERN_KINGDOMS, -733.396729f, 1536.514160f, 16.620735f, 0.0f);
            break;
        case 2:
            player->ADD_GOSSIP_ITEM(5, "传送：亚楠镇",               GOSSIP_SENDER_MAIN, 3);
            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            break;
        case 3:
            player->CLOSE_GOSSIP_MENU();
            if(player->GetLevel() < 60)
            {
                player->GetSession()->SendNotification("You must be at least level 60 to enter.");
                break;
            }
            player->TeleportTo(545, -1095.44f, 2234.75f, 182.862f, 0.0f);
            break;
    }
}
bool GossipSelect_Yarntown(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
    // Main menu
    if (sender == GOSSIP_SENDER_MAIN)
        SendDefaultMenu_Yarntown(player, _Creature, action);

    return true;
}

bool GossipHello_Elder_Timbermaw(Player *player, Creature *_Creature)   
{
    if (player->GetMapId() == 547)
    {
        player->ADD_GOSSIP_ITEM(5, "离开凄凉山",               GOSSIP_SENDER_MAIN, 1);
    }
    else
    {
        player->ADD_GOSSIP_ITEM(7, "醉卧沙场君莫笑，古来征战几人回？",               GOSSIP_SENDER_MAIN, 2);
    }
    player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
    return true;
}
void SendDefaultMenu_Elder_Timbermaw(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case 1:
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(MAP_KALIMDOR, 2948.08f, -4261.04f, 103.785f, 0.0f);
            break;
        case 2:
            player->ADD_GOSSIP_ITEM(5, "传送：凄凉山",               GOSSIP_SENDER_MAIN, 3);
            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            break;
        case 3:
            player->CLOSE_GOSSIP_MENU();
            if(player->GetLevel() < 60)
            {
                player->GetSession()->SendNotification("You must be at least level 60 to enter.");
                break;
            }
            player->TeleportTo(547, 322.27f, 170.297f, 234.934f, 0.0f);
            break;
    }
}
bool GossipSelect_Elder_Timbermaw(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
    // Main menu
    if (sender == GOSSIP_SENDER_MAIN)
        SendDefaultMenu_Elder_Timbermaw(player, _Creature, action);

    return true;
}

bool GossipHello_Scarlet_Traitor(Player *player, Creature *_Creature)   
{
    if (player->GetMapId() == 548)
    {
        player->ADD_GOSSIP_ITEM(5, "离开修道院",               GOSSIP_SENDER_MAIN, 1);
    }
    else
    {
        player->ADD_GOSSIP_ITEM(7, "黑厂，快跑！",               GOSSIP_SENDER_MAIN, 2);
    }
    player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
    return true;
}
void SendDefaultMenu_Scarlet_Traitor(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case 1:
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(MAP_EASTERN_KINGDOMS, 2875.06f, -633.725f, 137.839f, 0.0f);
            break;
        case 2:
            player->ADD_GOSSIP_ITEM(5, "传送：修道院",               GOSSIP_SENDER_MAIN, 3);
            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            break;
        case 3:
            player->CLOSE_GOSSIP_MENU();
            if(player->GetLevel() < 60)
            {
                player->GetSession()->SendNotification("You must be at least level 60 to enter.");
                break;
            }
            player->TeleportTo(548, 78.3392f, -0.845785f, 18.6771f, 0.0f);
            break;
    }
}
bool GossipSelect_Scarlet_Traitor(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
    // Main menu
    if (sender == GOSSIP_SENDER_MAIN)
        SendDefaultMenu_Scarlet_Traitor(player, _Creature, action);

    return true;
}

bool GossipHello_Tirion_Fordring_Outland(Player *player, Creature *_Creature)   
{
    if (player->GetMapId() == 546)
    {
        player->ADD_GOSSIP_ITEM(5, "离开德拉诺",               GOSSIP_SENDER_MAIN, 1);
    }
    else
    {
        player->ADD_GOSSIP_ITEM(7, "勇士们，穿越黑暗之门，进攻！",               GOSSIP_SENDER_MAIN, 2);
    }
    player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
    return true;
}
void SendDefaultMenu_Tirion_Fordring_Outland(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case 1:
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(MAP_EASTERN_KINGDOMS, -11865.1f, -3203.32f, -22.8171f, 0.0f);
            break;
        case 2:
            player->ADD_GOSSIP_ITEM(5, "传送：德拉诺",               GOSSIP_SENDER_MAIN, 3);
            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            break;
        case 3:
            player->CLOSE_GOSSIP_MENU();
            if(player->GetLevel() < 60)
            {
                player->GetSession()->SendNotification("You must be at least level 60 to enter.");
                break;
            }
            player->TeleportTo(546, -6080.821f, -2356.988f, 56.089f, 0.0f);
            break;
    }
}
bool GossipSelect_Tirion_Fordring_Outland(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
    // Main menu
    if (sender == GOSSIP_SENDER_MAIN)
        SendDefaultMenu_Tirion_Fordring_Outland(player, _Creature, action);

    return true;
}

bool GossipHello_Syndicate_Onlookers(Player *player, Creature *_Creature)   
{
    if (player->GetMapId() == 550)
    {
        player->ADD_GOSSIP_ITEM(5, "离开副本",               GOSSIP_SENDER_MAIN, 1);
    }
    else
    {
        player->ADD_GOSSIP_ITEM(7, "欢迎加入勇敢者的游戏。Make Arena Great Again!",               GOSSIP_SENDER_MAIN, 2);
    }
    player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
    return true;
}
void SendDefaultMenu_Syndicate_Onlookers(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case 1:
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(MAP_EASTERN_KINGDOMS, -492.673553f, -1570.729370f, 52.666183f, 0.0f);
            break;
        case 2:
            player->ADD_GOSSIP_ITEM(5, "传送：血环竞技场",               GOSSIP_SENDER_MAIN, 3);
            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            break;
        case 3:
            player->CLOSE_GOSSIP_MENU();
            if(player->GetLevel() < 60)
            {
                player->GetSession()->SendNotification("You must be at least level 60 to enter.");
                break;
            }
            player->TeleportTo(550, 15672.334961f, 16796.822266f, 2.957636f, 0.0f);
            break;
    }
}
bool GossipSelect_Syndicate_Onlookers(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
    // Main menu
    if (sender == GOSSIP_SENDER_MAIN)
        SendDefaultMenu_Syndicate_Onlookers(player, _Creature, action);

    return true;
}

bool GossipHello_Foggy_Zoltan(Player *player, Creature *_Creature)   
{
    if (player->GetMapId() == 552)
    {
        player->ADD_GOSSIP_ITEM(5, "离开副本",               GOSSIP_SENDER_MAIN, 1);
    }
    else
    {
        player->ADD_GOSSIP_ITEM(7, "嗝~再给我一杯酒……还有丝绸！",               GOSSIP_SENDER_MAIN, 2);
    }
    player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
    return true;
}
void SendDefaultMenu_Foggy_Zoltan(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case 1:
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(MAP_EASTERN_KINGDOMS, -5618.981934, -830.361633, 483.534393, 0.0f);
            break;
        case 2:
            player->ADD_GOSSIP_ITEM(5, "传送：旧铁炉堡",               GOSSIP_SENDER_MAIN, 3);
            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            break;
        case 3:
            player->CLOSE_GOSSIP_MENU();
            if(player->GetLevel() < 60)
            {
                player->GetSession()->SendNotification("You must be at least level 60 to enter.");
                break;
            }
            player->TeleportTo(552, -4981.924805f, -881.592896f, 501.659760f, 0.0f);
            break;
    }
}
bool GossipSelect_Foggy_Zoltan(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
    // Main menu
    if (sender == GOSSIP_SENDER_MAIN)
        SendDefaultMenu_Foggy_Zoltan(player, _Creature, action);

    return true;
}

bool GossipHello_Brave_Cow(Player *player, Creature *_Creature)   
{
    if (player->GetMapId() == 553)
    {
        player->ADD_GOSSIP_ITEM(5, "离开副本",               GOSSIP_SENDER_MAIN, 1);
    }
    else
    {
        player->ADD_GOSSIP_ITEM(7, "略略略！我什么都不知道，因为我只是一头奶牛。",               GOSSIP_SENDER_MAIN, 2);
    }
    player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
    return true;
}
void SendDefaultMenu_Brave_Cow(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case 1:
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(MAP_KALIMDOR, -6560.617188f, -545.094299f, -254.334824f, 0.0f);
            break;
        case 2:
            player->ADD_GOSSIP_ITEM(5, "传送：星露谷",               GOSSIP_SENDER_MAIN, 3);
            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            break;
        case 3:
            player->CLOSE_GOSSIP_MENU();
            if(player->GetLevel() < 60)
            {
                player->GetSession()->SendNotification("You must be at least level 60 to enter.");
                break;
            }
            player->TeleportTo(553, 16637.523438f, 16783.306641f, 70.350830f, 0.0f);
            break;
    }
}
bool GossipSelect_Brave_Cow(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
    // Main menu
    if (sender == GOSSIP_SENDER_MAIN)
        SendDefaultMenu_Brave_Cow(player, _Creature, action);

    return true;
}

bool GossipHello_Luke_Skywalker(Player *player, Creature *_Creature)   
{
    if (player->GetMapId() == 554)
    {
        player->ADD_GOSSIP_ITEM(5, "离开副本",               GOSSIP_SENDER_MAIN, 1);
    }
    else
    {
        player->ADD_GOSSIP_ITEM(7, "我以前和你一样也是个冒险家，直到我的膝盖中了一箭。",               GOSSIP_SENDER_MAIN, 2);
    }
    player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
    return true;
}
void SendDefaultMenu_Luke_Skywalker(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case 1:
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(MAP_EASTERN_KINGDOMS, -213.140915f, -2522.304688f, 118.503098f, 0.0f);
            break;
        case 2:
            player->ADD_GOSSIP_ITEM(5, "传送：新月林地",               GOSSIP_SENDER_MAIN, 3);
            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            break;
        case 3:
            player->CLOSE_GOSSIP_MENU();
            if(player->GetLevel() < 60)
            {
                player->GetSession()->SendNotification("You must be at least level 60 to enter.");
                break;
            }
            player->TeleportTo(554, 560.769409f, 86.339394f, 273.202637f, 0.0f);
            break;
    }
}
bool GossipSelect_Luke_Skywalker(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
    // Main menu
    if (sender == GOSSIP_SENDER_MAIN)
        SendDefaultMenu_Luke_Skywalker(player, _Creature, action);

    return true;
}

bool GossipHello_Gwyn(Player *player, Creature *_Creature)   
{
    player->ADD_GOSSIP_ITEM(7, "火已渐熄，位不见王影，而无火的余灰们将纷沓而至。那是无名，成不了薪，且被诅咒的不死人。但正因为如此，灰烬才会如此渴求余火吧。",  GOSSIP_SENDER_MAIN, 1);
    player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
    return true;
}
void SendDefaultMenu_Gwyn(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case 1:
            player->ADD_GOSSIP_ITEM(7, "薪王不肯回到王位，那么，将柴薪拿回来就行。",    GOSSIP_SENDER_MAIN, 2);
            if (player->HasItemCount(26158, 1) && player->HasItemCount(26159, 1) && player->HasItemCount(26160, 1) && player->HasItemCount(26161, 1) && player->HasItemCount(26162, 1) && player->HasItemCount(26163, 1) && player->HasItemCount(26164, 1))
            {
                if (player->HasItemWithIdEquipped(26010, 1))
                    player->ADD_GOSSIP_ITEM(5, "燃烧薪王柴薪，用初始之火锻造：武林之豪",    GOSSIP_SENDER_MAIN, 3);
                if (player->HasItemWithIdEquipped(26020, 1))
                    player->ADD_GOSSIP_ITEM(5, "燃烧薪王柴薪，用初始之火锻造：埃辛诺斯战刃",    GOSSIP_SENDER_MAIN, 4);
                if (player->HasItemWithIdEquipped(26021, 1))
                    player->ADD_GOSSIP_ITEM(5, "燃烧薪王柴薪，用初始之火锻造：埃辛诺斯战刃",    GOSSIP_SENDER_MAIN, 5);
                if (player->HasItemWithIdEquipped(26022, 1))
                    player->ADD_GOSSIP_ITEM(5, "燃烧薪王柴薪，用初始之火锻造：灰烬使者",    GOSSIP_SENDER_MAIN, 6);
                if (player->HasItemWithIdEquipped(26023, 1))
                    player->ADD_GOSSIP_ITEM(5, "燃烧薪王柴薪，用初始之火锻造：金箍棒",    GOSSIP_SENDER_MAIN, 7);
                if (player->HasItemWithIdEquipped(26024, 1))
                    player->ADD_GOSSIP_ITEM(5, "燃烧薪王柴薪，用初始之火锻造：凤凰",    GOSSIP_SENDER_MAIN, 8);
                if (player->HasItemWithIdEquipped(26027, 1))
                    player->ADD_GOSSIP_ITEM(5, "燃烧薪王柴薪，用初始之火锻造：不朽之守护",    GOSSIP_SENDER_MAIN, 9);
                if (player->HasItemWithIdEquipped(26028, 1))
                    player->ADD_GOSSIP_ITEM(5, "燃烧薪王柴薪，用初始之火锻造：审判之轮",    GOSSIP_SENDER_MAIN, 10);
                if (player->HasItemWithIdEquipped(26029, 1))
                    player->ADD_GOSSIP_ITEM(5, "燃烧薪王柴薪，用初始之火锻造：阿哈利姆神杖",    GOSSIP_SENDER_MAIN, 11);
                if (player->HasItemWithIdEquipped(26032, 1))
                    player->ADD_GOSSIP_ITEM(5, "燃烧薪王柴薪，用初始之火锻造：死亡拨弦",    GOSSIP_SENDER_MAIN, 12);
                if (player->HasItemWithIdEquipped(26034, 1))
                    player->ADD_GOSSIP_ITEM(5, "燃烧薪王柴薪，用初始之火锻造：巴特克的猛击",    GOSSIP_SENDER_MAIN, 13);
                if (player->HasItemWithIdEquipped(26035, 1))
                    player->ADD_GOSSIP_ITEM(5, "燃烧薪王柴薪，用初始之火锻造：赫拉森的庇护",    GOSSIP_SENDER_MAIN, 14);
                if (player->HasItemWithIdEquipped(26036, 1))
                    player->ADD_GOSSIP_ITEM(5, "燃烧薪王柴薪，用初始之火锻造：洗礼圣契",    GOSSIP_SENDER_MAIN, 15);
                if (player->HasItemWithIdEquipped(26037, 1))
                    player->ADD_GOSSIP_ITEM(5, "燃烧薪王柴薪，用初始之火锻造：月夜枭兽神像",    GOSSIP_SENDER_MAIN, 16);
                if (player->HasItemWithIdEquipped(26038, 1))
                    player->ADD_GOSSIP_ITEM(5, "燃烧薪王柴薪，用初始之火锻造：雷云图腾",    GOSSIP_SENDER_MAIN, 17);
                if (player->HasItemWithIdEquipped(26044, 1))
                    player->ADD_GOSSIP_ITEM(5, "燃烧薪王柴薪，用初始之火锻造：命定之死",    GOSSIP_SENDER_MAIN, 18);
                if (player->HasItemWithIdEquipped(26045, 1))
                    player->ADD_GOSSIP_ITEM(5, "燃烧薪王柴薪，用初始之火锻造：猎杀指头刀",    GOSSIP_SENDER_MAIN, 19);
                if (player->HasItemWithIdEquipped(26046, 1))
                    player->ADD_GOSSIP_ITEM(5, "燃烧薪王柴薪，用初始之火锻造：群星",    GOSSIP_SENDER_MAIN, 20);
                if (player->HasItemWithIdEquipped(26047, 1))
                    player->ADD_GOSSIP_ITEM(5, "燃烧薪王柴薪，用初始之火锻造：猩红腐败",    GOSSIP_SENDER_MAIN, 21);
                if (player->HasItemWithIdEquipped(26049, 1))
                    player->ADD_GOSSIP_ITEM(5, "燃烧薪王柴薪，用初始之火锻造：先锋盾",    GOSSIP_SENDER_MAIN, 22);
                if (player->HasItemWithIdEquipped(26050, 1))
                    player->ADD_GOSSIP_ITEM(5, "燃烧薪王柴薪，用初始之火锻造：雷神之锤",    GOSSIP_SENDER_MAIN, 23);
            }
            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            break;
        case 2:
            player->CLOSE_GOSSIP_MENU();
            break;
        case 3:
            if (player->AddItem(26137))
            {
                player->DestroyItemCount(26010, 1, true);
                player->DestroyItemCount(26158, 1, true);
                player->DestroyItemCount(26159, 1, true);
                player->DestroyItemCount(26160, 1, true);
                player->DestroyItemCount(26161, 1, true);
                player->DestroyItemCount(26162, 1, true);
                player->DestroyItemCount(26163, 1, true);
                player->DestroyItemCount(26164, 1, true);
            }
            player->CLOSE_GOSSIP_MENU();
            break;
        case 4:
            if (player->AddItem(26138))
            {
                player->DestroyItemCount(26020, 1, true);
                player->DestroyItemCount(26158, 1, true);
                player->DestroyItemCount(26159, 1, true);
                player->DestroyItemCount(26160, 1, true);
                player->DestroyItemCount(26161, 1, true);
                player->DestroyItemCount(26162, 1, true);
                player->DestroyItemCount(26163, 1, true);
                player->DestroyItemCount(26164, 1, true);
            }
            player->CLOSE_GOSSIP_MENU();
            break;
        case 5:
            if (player->AddItem(26139))
            {
                player->DestroyItemCount(26021, 1, true);
                player->DestroyItemCount(26158, 1, true);
                player->DestroyItemCount(26159, 1, true);
                player->DestroyItemCount(26160, 1, true);
                player->DestroyItemCount(26161, 1, true);
                player->DestroyItemCount(26162, 1, true);
                player->DestroyItemCount(26163, 1, true);
                player->DestroyItemCount(26164, 1, true);
            }
            player->CLOSE_GOSSIP_MENU();
            break;
        case 6:
            if (player->AddItem(26140))
            {
                player->DestroyItemCount(26022, 1, true);
                player->DestroyItemCount(26158, 1, true);
                player->DestroyItemCount(26159, 1, true);
                player->DestroyItemCount(26160, 1, true);
                player->DestroyItemCount(26161, 1, true);
                player->DestroyItemCount(26162, 1, true);
                player->DestroyItemCount(26163, 1, true);
                player->DestroyItemCount(26164, 1, true);
            }
            player->CLOSE_GOSSIP_MENU();
            break;
        case 7:
            if (player->AddItem(26141))
            {
                player->DestroyItemCount(26023, 1, true);
                player->DestroyItemCount(26158, 1, true);
                player->DestroyItemCount(26159, 1, true);
                player->DestroyItemCount(26160, 1, true);
                player->DestroyItemCount(26161, 1, true);
                player->DestroyItemCount(26162, 1, true);
                player->DestroyItemCount(26163, 1, true);
                player->DestroyItemCount(26164, 1, true);
            }
            player->CLOSE_GOSSIP_MENU();
            break;
        case 8:
            if (player->AddItem(26142))
            {
                player->DestroyItemCount(26024, 1, true);
                player->DestroyItemCount(26158, 1, true);
                player->DestroyItemCount(26159, 1, true);
                player->DestroyItemCount(26160, 1, true);
                player->DestroyItemCount(26161, 1, true);
                player->DestroyItemCount(26162, 1, true);
                player->DestroyItemCount(26163, 1, true);
                player->DestroyItemCount(26164, 1, true);
            }
            player->CLOSE_GOSSIP_MENU();
            break;
        case 9:
            if (player->AddItem(26143))
            {
                player->DestroyItemCount(26027, 1, true);
                player->DestroyItemCount(26158, 1, true);
                player->DestroyItemCount(26159, 1, true);
                player->DestroyItemCount(26160, 1, true);
                player->DestroyItemCount(26161, 1, true);
                player->DestroyItemCount(26162, 1, true);
                player->DestroyItemCount(26163, 1, true);
                player->DestroyItemCount(26164, 1, true);
            }
            player->CLOSE_GOSSIP_MENU();
            break;
        case 10:
            if (player->AddItem(26144))
            {
                player->DestroyItemCount(26028, 1, true);
                player->DestroyItemCount(26158, 1, true);
                player->DestroyItemCount(26159, 1, true);
                player->DestroyItemCount(26160, 1, true);
                player->DestroyItemCount(26161, 1, true);
                player->DestroyItemCount(26162, 1, true);
                player->DestroyItemCount(26163, 1, true);
                player->DestroyItemCount(26164, 1, true);
            }
            player->CLOSE_GOSSIP_MENU();
            break;
        case 11:
            if (player->AddItem(26145))
            {
                player->DestroyItemCount(26029, 1, true);
                player->DestroyItemCount(26158, 1, true);
                player->DestroyItemCount(26159, 1, true);
                player->DestroyItemCount(26160, 1, true);
                player->DestroyItemCount(26161, 1, true);
                player->DestroyItemCount(26162, 1, true);
                player->DestroyItemCount(26163, 1, true);
                player->DestroyItemCount(26164, 1, true);
            }
            player->CLOSE_GOSSIP_MENU();
            break;
        case 12:
            if (player->AddItem(26146))
            {
                player->DestroyItemCount(26032, 1, true);
                player->DestroyItemCount(26158, 1, true);
                player->DestroyItemCount(26159, 1, true);
                player->DestroyItemCount(26160, 1, true);
                player->DestroyItemCount(26161, 1, true);
                player->DestroyItemCount(26162, 1, true);
                player->DestroyItemCount(26163, 1, true);
                player->DestroyItemCount(26164, 1, true);
            }
            player->CLOSE_GOSSIP_MENU();
            break;
        case 13:
            if (player->AddItem(26147))
            {
                player->DestroyItemCount(26034, 1, true);
                player->DestroyItemCount(26158, 1, true);
                player->DestroyItemCount(26159, 1, true);
                player->DestroyItemCount(26160, 1, true);
                player->DestroyItemCount(26161, 1, true);
                player->DestroyItemCount(26162, 1, true);
                player->DestroyItemCount(26163, 1, true);
                player->DestroyItemCount(26164, 1, true);
            }
            player->CLOSE_GOSSIP_MENU();
            break;
        case 14:
            if (player->AddItem(26148))
            {
                player->DestroyItemCount(26035, 1, true);
                player->DestroyItemCount(26158, 1, true);
                player->DestroyItemCount(26159, 1, true);
                player->DestroyItemCount(26160, 1, true);
                player->DestroyItemCount(26161, 1, true);
                player->DestroyItemCount(26162, 1, true);
                player->DestroyItemCount(26163, 1, true);
                player->DestroyItemCount(26164, 1, true);
            }
            player->CLOSE_GOSSIP_MENU();
            break;
        case 15:
            if (player->AddItem(26149))
            {
                player->DestroyItemCount(26036, 1, true);
                player->DestroyItemCount(26158, 1, true);
                player->DestroyItemCount(26159, 1, true);
                player->DestroyItemCount(26160, 1, true);
                player->DestroyItemCount(26161, 1, true);
                player->DestroyItemCount(26162, 1, true);
                player->DestroyItemCount(26163, 1, true);
                player->DestroyItemCount(26164, 1, true);
            }
            player->CLOSE_GOSSIP_MENU();
            break;
        case 16:
            if (player->AddItem(26150))
            {
                player->DestroyItemCount(26037, 1, true);
                player->DestroyItemCount(26158, 1, true);
                player->DestroyItemCount(26159, 1, true);
                player->DestroyItemCount(26160, 1, true);
                player->DestroyItemCount(26161, 1, true);
                player->DestroyItemCount(26162, 1, true);
                player->DestroyItemCount(26163, 1, true);
                player->DestroyItemCount(26164, 1, true);
            }
            player->CLOSE_GOSSIP_MENU();
            break;
        case 17:
            if (player->AddItem(26151))
            {
                player->DestroyItemCount(26038, 1, true);
                player->DestroyItemCount(26158, 1, true);
                player->DestroyItemCount(26159, 1, true);
                player->DestroyItemCount(26160, 1, true);
                player->DestroyItemCount(26161, 1, true);
                player->DestroyItemCount(26162, 1, true);
                player->DestroyItemCount(26163, 1, true);
                player->DestroyItemCount(26164, 1, true);
            }
            player->CLOSE_GOSSIP_MENU();
            break;
        case 18:
            if (player->AddItem(26152))
            {
                player->DestroyItemCount(26044, 1, true);
                player->DestroyItemCount(26158, 1, true);
                player->DestroyItemCount(26159, 1, true);
                player->DestroyItemCount(26160, 1, true);
                player->DestroyItemCount(26161, 1, true);
                player->DestroyItemCount(26162, 1, true);
                player->DestroyItemCount(26163, 1, true);
                player->DestroyItemCount(26164, 1, true);
            }
            player->CLOSE_GOSSIP_MENU();
            break;
        case 19:
            if (player->AddItem(26153))
            {
                player->DestroyItemCount(26045, 1, true);
                player->DestroyItemCount(26158, 1, true);
                player->DestroyItemCount(26159, 1, true);
                player->DestroyItemCount(26160, 1, true);
                player->DestroyItemCount(26161, 1, true);
                player->DestroyItemCount(26162, 1, true);
                player->DestroyItemCount(26163, 1, true);
                player->DestroyItemCount(26164, 1, true);
            }
            player->CLOSE_GOSSIP_MENU();
            break;
        case 20:
            if (player->AddItem(26154))
            {
                player->DestroyItemCount(26046, 1, true);
                player->DestroyItemCount(26158, 1, true);
                player->DestroyItemCount(26159, 1, true);
                player->DestroyItemCount(26160, 1, true);
                player->DestroyItemCount(26161, 1, true);
                player->DestroyItemCount(26162, 1, true);
                player->DestroyItemCount(26163, 1, true);
                player->DestroyItemCount(26164, 1, true);
            }
            player->CLOSE_GOSSIP_MENU();
            break;
        case 21:
            if (player->AddItem(26155))
            {
                player->DestroyItemCount(26047, 1, true);
                player->DestroyItemCount(26158, 1, true);
                player->DestroyItemCount(26159, 1, true);
                player->DestroyItemCount(26160, 1, true);
                player->DestroyItemCount(26161, 1, true);
                player->DestroyItemCount(26162, 1, true);
                player->DestroyItemCount(26163, 1, true);
                player->DestroyItemCount(26164, 1, true);
            }
            player->CLOSE_GOSSIP_MENU();
            break;
        case 22:
            if (player->AddItem(26156))
            {
                player->DestroyItemCount(26049, 1, true);
                player->DestroyItemCount(26158, 1, true);
                player->DestroyItemCount(26159, 1, true);
                player->DestroyItemCount(26160, 1, true);
                player->DestroyItemCount(26161, 1, true);
                player->DestroyItemCount(26162, 1, true);
                player->DestroyItemCount(26163, 1, true);
                player->DestroyItemCount(26164, 1, true);
            }
            player->CLOSE_GOSSIP_MENU();
            break;
        case 23:
            if (player->AddItem(26157))
            {
                player->DestroyItemCount(26050, 1, true);
                player->DestroyItemCount(26158, 1, true);
                player->DestroyItemCount(26159, 1, true);
                player->DestroyItemCount(26160, 1, true);
                player->DestroyItemCount(26161, 1, true);
                player->DestroyItemCount(26162, 1, true);
                player->DestroyItemCount(26163, 1, true);
                player->DestroyItemCount(26164, 1, true);
            }
            player->CLOSE_GOSSIP_MENU();
            break;
    }
}
bool GossipSelect_Gwyn(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
    // Main menu
    if (sender == GOSSIP_SENDER_MAIN)
        SendDefaultMenu_Gwyn(player, _Creature, action);

    return true;
}

bool GossipHello_TransmogNPC(Player* player, Creature* creature)
{
    player->ADD_GOSSIP_ITEM(5, "头部",      GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_HEAD);
    player->ADD_GOSSIP_ITEM(5, "肩部",      GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_SHOULDERS);
    player->ADD_GOSSIP_ITEM(5, "胸部",      GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_CHEST);
    player->ADD_GOSSIP_ITEM(5, "腰部",    GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_WAIST);
    player->ADD_GOSSIP_ITEM(5, "腿部",    GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_LEGS);
    player->ADD_GOSSIP_ITEM(5, "脚部",      GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_FEET);
    player->ADD_GOSSIP_ITEM(5, "手腕",    GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_WRISTS);
    player->ADD_GOSSIP_ITEM(5, "手部",     GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_HANDS);
    player->ADD_GOSSIP_ITEM(5, "背部",   GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_BACK);
    player->ADD_GOSSIP_ITEM(5, "主手",   GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_MAINHAND);
    player->ADD_GOSSIP_ITEM(5, "副手",    GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_OFFHAND);
    player->ADD_GOSSIP_ITEM(5, "远程武器",    GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_RANGED);

    player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
    return true;
}

bool GossipSelect_TransmogNPC(Player* player, Creature* creature, uint32 sender, uint32 action)
{
    if (sender != GOSSIP_SENDER_MAIN)
        return true;

    Item* item = nullptr;
    Item* item_transmog = nullptr;
    switch (action)
    {
        case EQUIPMENT_SLOT_HEAD:
            item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HEAD);
            break;
        case EQUIPMENT_SLOT_SHOULDERS:
            item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_SHOULDERS);
            break;
        case EQUIPMENT_SLOT_CHEST:
            item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST);
            break;
        case EQUIPMENT_SLOT_WAIST:
            item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WAIST);
            break;
        case EQUIPMENT_SLOT_LEGS:
            item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_LEGS);
            break;
        case EQUIPMENT_SLOT_FEET:
            item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET);
            break;
        case EQUIPMENT_SLOT_WRISTS:
            item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS);
            break;
        case EQUIPMENT_SLOT_HANDS:
            item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS);
            break;
        case EQUIPMENT_SLOT_BACK:
            item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK);
            break;
        case EQUIPMENT_SLOT_MAINHAND:
            item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
            break;
        case EQUIPMENT_SLOT_OFFHAND:
            item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);
            break;
        case EQUIPMENT_SLOT_RANGED:
            item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED);
            break;
    }
    item_transmog = player->GetItemByPos(INVENTORY_SLOT_BAG_0, INVENTORY_SLOT_ITEM_START);

    if (!item || !item_transmog){
        player->GetSession()->SendNotification("幻化部位或行囊首格未检测到装备。");
    }else if(player->GetMoney() < 100 * GOLD){
        player->GetSession()->SendNotification("幻化需要100金币。");
    }else if((item->GetProto()->Class == 2 && item->GetProto()->Class == item_transmog->GetProto()->Class && item->GetProto()->SubClass == item_transmog->GetProto()->SubClass)||(item->GetProto()->Class == 4 && item->GetProto()->Class == item_transmog->GetProto()->Class && item->GetProto()->InventoryType == item_transmog->GetProto()->InventoryType)||item_transmog->GetEntry() == 6948){
        uint64 item_guid = item->GetGUIDLow();
        uint64 item_entry = item_transmog->GetEntry() == 6948 ? item->GetEntry() : item_transmog->GetEntry();
        uint64 character_guid = item->GetOwnerGuid();
        player->ReplaceCharacterTransmog(item_guid, item_entry, character_guid);
        player->ModifyMoney(-100 * GOLD);
        player->GetSession()->SendNotification("幻化成功，重新装备后生效。");
    }
    else{
        player->GetSession()->SendNotification("幻化部位或行囊首格装备类型不同。");
    }
    player->CLOSE_GOSSIP_MENU();
    return true;
}

bool GossipHello_ReforgeNPC(Player* player, Creature* creature)
{
    player->ADD_GOSSIP_ITEM(1, "重铸",      GOSSIP_SENDER_MAIN, 1);

    player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
    return true;
}

bool GossipSelect_ReforgeNPC(Player* player, Creature* creature, uint32 sender, uint32 action)
{
    if (sender != GOSSIP_SENDER_MAIN)
        return true;

    Item* item = nullptr;
    switch (action)
    {
        case 1:
            item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, INVENTORY_SLOT_ITEM_START);
            break;
    }

    if (!item){
        player->GetSession()->SendNotification("行囊首格未检测到装备。");
    }else if(player->GetMoney() < 150 * GOLD){
        player->GetSession()->SendNotification("重铸需要150金币。");
    }else if(item->GetProto()->RandomProperty == 9000 || item->GetProto()->RandomProperty == 9001 || item->GetProto()->RandomProperty == 9002){
        player->GetSession()->SendNotification("行囊首格装备重铸成功。");
        player->DestroyItem(item->GetBagSlot(), item->GetSlot(), true);
        player->AddItem(item->GetProto()->ItemId);
        player->ModifyMoney(-150 * GOLD);
    }
    else{
        player->GetSession()->SendNotification("行囊首格装备无法重铸。");
    }
    player->CLOSE_GOSSIP_MENU();
    return true;
}

enum Enchants
{
    WEP2H_SUPERIOR_IMPACT = 20,
    WEP2H_AGILITY,
    WEP_CRUSADER,
    WEP_LIFESTEAL,
    WEP_FIERY,
    WEP_ICY,
    WEP_DEMONSLAYING,
    WEP_STEELWEAPONCHAIN,
    WEP1H_AGILITY,
    WEP_SPELLPOWER,
    WEP_HEAL,
    WEP2H_INT,
    WEP2H_SPIRIT,
    OFFHAND_SPIRIT,
    OFFHAND_STAM,
    OFFHAND_FROSTRES,
    OFFHAND_SHIELDSPIKE,
    CHEST_STATS,
    CHEST_HEALTH,
    CLOAK_DODGE,
    CLOAK_SUB,
    CLOAK_ARMOR,
    CLOAK_AGILITY,
    CLOAK_GREATER_RES,
    BRACER_STAM,
    BRACER_STR,
    BRACER_HEAL,
    BRACER_INT,
    BRACER_MP5,
    GLOVES_AGI,
    GLOVES_FIRE,
    GLOVES_FROST,
    GLOVES_SHADOW,
    GLOVES_HEALING,
    BOOTS_AGI,
    BOOTS_SPEED,
    BOOTS_STAM,
    WEP_CRUSADER_OFFHAND,
    WEP_LIFESTEAL_OFFHAND,
    WEP_FIERY_OFFHAND,
    WEP_ICY_OFFHAND,
    WEP_DEMONSLAYING_OFFHAND,
    WEP1H_AGILITY_OFFHAND,
    WEP_SPELLPOWER_OFFHAND,
    WEP_HEAL_OFFHAND,
    WEP_STEELWEAPONCHAIN_OFFHAND,
};

void Enchant(Player* player, Item* item, uint32 enchantid)
{
    if (!item)
    {
        player->GetSession()->SendNotification("附魔部位未检测到装备。");
        return;
    }

    if (!enchantid)
    {
        player->GetSession()->SendNotification("附魔失败。");
        return;
    }

    if(player->GetMoney() < 50 * GOLD)
    {
        player->GetSession()->SendNotification("附魔需要50金币。");
        return;
    }

    item->ClearEnchantment(PERM_ENCHANTMENT_SLOT);
    item->SetEnchantment(PERM_ENCHANTMENT_SLOT, enchantid, 0, 0);
    player->ModifyMoney(-50 * GOLD);
    player->GetSession()->SendNotification("%s 附魔成功", item->GetProto()->Name1);
}

bool GossipHello_EnchantNPC(Player* player, Creature* creature)
{
    player->ADD_GOSSIP_ITEM(5, "胸部",      GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_CHEST);
    player->ADD_GOSSIP_ITEM(5, "背部",      GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_BACK);
    player->ADD_GOSSIP_ITEM(5, "手腕",    GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_WRISTS);
    player->ADD_GOSSIP_ITEM(5, "手部",     GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_HANDS);
    player->ADD_GOSSIP_ITEM(5, "脚部",      GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_FEET);
    player->ADD_GOSSIP_ITEM(5, "主手",   GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_MAINHAND);
    player->ADD_GOSSIP_ITEM(5, "副手",    GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_OFFHAND);

    player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
    return true;
}

bool GossipSelect_EnchantNPC(Player* player, Creature* creature, uint32 sender, uint32 action)
{
    if (sender != GOSSIP_SENDER_MAIN)
        return true;

    if (action < 20)
    {
        switch (action)
        {
        case EQUIPMENT_SLOT_CHEST:
            player->ADD_GOSSIP_ITEM(5, "所有属性+4",      GOSSIP_SENDER_MAIN, CHEST_STATS);
            player->ADD_GOSSIP_ITEM(5, "生命值+100",     GOSSIP_SENDER_MAIN, CHEST_HEALTH);
            break;
        case EQUIPMENT_SLOT_BACK:
            player->ADD_GOSSIP_ITEM(5, "敏捷+3",            GOSSIP_SENDER_MAIN, CLOAK_AGILITY);
            player->ADD_GOSSIP_ITEM(5, "护甲+70",              GOSSIP_SENDER_MAIN, CLOAK_ARMOR);
            player->ADD_GOSSIP_ITEM(5, "躲闪+1%",              GOSSIP_SENDER_MAIN, CLOAK_DODGE);
            player->ADD_GOSSIP_ITEM(5, "仇恨-2%",           GOSSIP_SENDER_MAIN, CLOAK_SUB);
            player->ADD_GOSSIP_ITEM(5, "所有抗性+5", GOSSIP_SENDER_MAIN, CLOAK_GREATER_RES);
        break;
        case EQUIPMENT_SLOT_WRISTS:
            player->ADD_GOSSIP_ITEM(5, "耐力+9",            GOSSIP_SENDER_MAIN, BRACER_STAM);
            player->ADD_GOSSIP_ITEM(5, "力量+9",           GOSSIP_SENDER_MAIN, BRACER_STR);
            player->ADD_GOSSIP_ITEM(5, "治疗法术+24",            GOSSIP_SENDER_MAIN, BRACER_HEAL);
            player->ADD_GOSSIP_ITEM(5, "智力+7",          GOSSIP_SENDER_MAIN, BRACER_INT);
            player->ADD_GOSSIP_ITEM(5, "每5秒回复4点法力值",                GOSSIP_SENDER_MAIN, BRACER_MP5);
            break;
        case EQUIPMENT_SLOT_HANDS:
            player->ADD_GOSSIP_ITEM(5, "敏捷+15",            GOSSIP_SENDER_MAIN, GLOVES_AGI);
            player->ADD_GOSSIP_ITEM(5, "火焰伤害+20",         GOSSIP_SENDER_MAIN, GLOVES_FIRE);
            player->ADD_GOSSIP_ITEM(5, "冰霜伤害+20",        GOSSIP_SENDER_MAIN, GLOVES_FROST);
            player->ADD_GOSSIP_ITEM(5, "暗影伤害+20",       GOSSIP_SENDER_MAIN, GLOVES_SHADOW);
            player->ADD_GOSSIP_ITEM(5, "治疗法术+30",            GOSSIP_SENDER_MAIN, GLOVES_HEALING);
            break;
        case EQUIPMENT_SLOT_FEET:
            player->ADD_GOSSIP_ITEM(5, "耐力+7",            GOSSIP_SENDER_MAIN, BOOTS_STAM);
            player->ADD_GOSSIP_ITEM(5, "移动速度+8%",        GOSSIP_SENDER_MAIN, BOOTS_SPEED);
            player->ADD_GOSSIP_ITEM(5, "敏捷+5",            GOSSIP_SENDER_MAIN, BOOTS_AGI);
            break;
        case EQUIPMENT_SLOT_MAINHAND:
            player->ADD_GOSSIP_ITEM(5, "十字军",           GOSSIP_SENDER_MAIN, WEP_CRUSADER);
            player->ADD_GOSSIP_ITEM(5, "单手武器 敏捷+15",         GOSSIP_SENDER_MAIN, WEP1H_AGILITY);
            player->ADD_GOSSIP_ITEM(5, "双手武器 敏捷+25",         GOSSIP_SENDER_MAIN, WEP2H_AGILITY);
            player->ADD_GOSSIP_ITEM(5, "双手武器 智力+22",             GOSSIP_SENDER_MAIN, WEP2H_INT);
            player->ADD_GOSSIP_ITEM(5, "双手武器 精神+20",          GOSSIP_SENDER_MAIN, WEP2H_SPIRIT);
            player->ADD_GOSSIP_ITEM(5, "法术伤害+30",         GOSSIP_SENDER_MAIN, WEP_SPELLPOWER);
            player->ADD_GOSSIP_ITEM(5, "治疗法术+55",            GOSSIP_SENDER_MAIN, WEP_HEAL);
            player->ADD_GOSSIP_ITEM(5, "生命偷取",          GOSSIP_SENDER_MAIN, WEP_LIFESTEAL);
            player->ADD_GOSSIP_ITEM(5, "灼热武器",              GOSSIP_SENDER_MAIN, WEP_FIERY);
            player->ADD_GOSSIP_ITEM(5, "冰冷武器",                GOSSIP_SENDER_MAIN, WEP_ICY);
            player->ADD_GOSSIP_ITEM(5, "屠魔",       GOSSIP_SENDER_MAIN, WEP_DEMONSLAYING);
            player->ADD_GOSSIP_ITEM(5, "钢质武器链",       GOSSIP_SENDER_MAIN, WEP_STEELWEAPONCHAIN);
            break;
        case EQUIPMENT_SLOT_OFFHAND:
            player->ADD_GOSSIP_ITEM(5, "盾牌：精神+9",             GOSSIP_SENDER_MAIN, OFFHAND_SPIRIT);
            player->ADD_GOSSIP_ITEM(5, "盾牌：耐力+7",            GOSSIP_SENDER_MAIN, OFFHAND_STAM);
            player->ADD_GOSSIP_ITEM(5, "盾牌：冰霜抗性+8",   GOSSIP_SENDER_MAIN, OFFHAND_FROSTRES);
            player->ADD_GOSSIP_ITEM(5, "盾牌：瑟银盾刺(20-30)",       GOSSIP_SENDER_MAIN, OFFHAND_SHIELDSPIKE);
            player->ADD_GOSSIP_ITEM(5, "武器：十字军",       GOSSIP_SENDER_MAIN, WEP_CRUSADER_OFFHAND);
            player->ADD_GOSSIP_ITEM(5, "武器：生命偷取",       GOSSIP_SENDER_MAIN, WEP_LIFESTEAL_OFFHAND);
            player->ADD_GOSSIP_ITEM(5, "武器：灼热武器",       GOSSIP_SENDER_MAIN, WEP_FIERY_OFFHAND);
            player->ADD_GOSSIP_ITEM(5, "武器：冰冷武器",       GOSSIP_SENDER_MAIN, WEP_ICY_OFFHAND);
            player->ADD_GOSSIP_ITEM(5, "武器：屠魔",       GOSSIP_SENDER_MAIN, WEP_DEMONSLAYING_OFFHAND);
            player->ADD_GOSSIP_ITEM(5, "武器：敏捷+15",       GOSSIP_SENDER_MAIN, WEP1H_AGILITY_OFFHAND);
            player->ADD_GOSSIP_ITEM(5, "武器：法术伤害+30",       GOSSIP_SENDER_MAIN, WEP_SPELLPOWER_OFFHAND);
            player->ADD_GOSSIP_ITEM(5, "武器：治疗法术+55",       GOSSIP_SENDER_MAIN, WEP_HEAL_OFFHAND);
            player->ADD_GOSSIP_ITEM(5, "武器：钢质武器链",       GOSSIP_SENDER_MAIN, WEP_STEELWEAPONCHAIN_OFFHAND);
            break;
        }
        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
    }
    else
    {
        Item* item = nullptr;
        uint32 id = 0;
        switch (action)
        {
            case WEP2H_SUPERIOR_IMPACT:
            case WEP2H_AGILITY:
            case WEP2H_INT:
            case WEP2H_SPIRIT:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
                if (item && (action == WEP2H_AGILITY || action == WEP2H_SUPERIOR_IMPACT || action == WEP2H_INT || action == WEP2H_SPIRIT))
                {
                    if (item->GetProto()->SubClass != ITEM_SUBCLASS_WEAPON_AXE2 && item->GetProto()->SubClass != ITEM_SUBCLASS_WEAPON_MACE2
                        && item->GetProto()->SubClass != ITEM_SUBCLASS_WEAPON_SWORD2 && item->GetProto()->SubClass != ITEM_SUBCLASS_WEAPON_POLEARM
                        && item->GetProto()->SubClass != ITEM_SUBCLASS_WEAPON_STAFF)
                    {
                        player->GetSession()->SendNotification("需要双手武器");
                        player->CLOSE_GOSSIP_MENU();
                        return true;
                    }
                }
                if (action == WEP2H_SUPERIOR_IMPACT)
                    id = 1896;
                else if (action == WEP2H_AGILITY)
                    id = 2646;
                else if (action == WEP2H_INT)
                    id = 2568;
                else if (action == WEP2H_SPIRIT)
                    id = 2567;
                break;

            case WEP_CRUSADER:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
                id = 1900;
                break;
            case WEP1H_AGILITY:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
                id = 2564;
                break;
            case WEP_SPELLPOWER:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
                id = 2504;
                break;
            case WEP_HEAL:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
                id = 2505;
                break;
            case WEP_LIFESTEAL:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
                id = 1898;
                break;
            case WEP_ICY:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
                id = 1894;
                break;
            case WEP_FIERY:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
                id = 803;
                break;
            case WEP_DEMONSLAYING:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
                id = 912;
                break;
            case WEP_STEELWEAPONCHAIN:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
                id = 37;
                break;

            case OFFHAND_SPIRIT:
            case OFFHAND_STAM:
            case OFFHAND_FROSTRES:
            case OFFHAND_SHIELDSPIKE:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);
                if (item && item->GetProto()->SubClass != ITEM_SUBCLASS_ARMOR_SHIELD)
                {
                    player->GetSession()->SendNotification("需要盾牌");
                    player->CLOSE_GOSSIP_MENU();
                    return true;
                }
                if (action == OFFHAND_SPIRIT)
                    id = 1890;
                else if (action == OFFHAND_FROSTRES)
                    id = 926;
                else if (action == OFFHAND_STAM)
                    id = 929;
                else if (action == OFFHAND_SHIELDSPIKE)
                    id = 1704;
                break;
            case CHEST_STATS:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST);
                id = 1891;
                break;
            case CHEST_HEALTH:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST);
                id = 1892;
                break;
            case CLOAK_DODGE:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK);
                id = 2622;
                break;
            case CLOAK_SUB:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK);
                id = 2621;
                break;
            case CLOAK_ARMOR:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK);
                id = 1889;
                break;
            case CLOAK_AGILITY:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK);
                id = 849;
                break;
            case CLOAK_GREATER_RES:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK);
                id = 1888;
                break;
            case BRACER_STAM:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS);
                id = 1886;
                break;
            case BRACER_STR:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS);
                id = 1885;
                break;
            case BRACER_HEAL:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS);
                id = 2566;
                break;
            case BRACER_INT:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS);
                id = 1883;
                break;
            case BRACER_MP5:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS);
                id = 2565;
                break;
            case GLOVES_AGI:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS);
                id = 2564;
                break;
            case GLOVES_FIRE:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS);
                id = 2616;
                break;
            case GLOVES_FROST:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS);
                id = 2615;
                break;
            case GLOVES_SHADOW:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS);
                id = 2614;
                break;
            case GLOVES_HEALING:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS);
                id = 2617;
                break;
            case BOOTS_AGI:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET);
                id = 904;
                break;
            case BOOTS_SPEED:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET);
                id = 911;
                break;
            case BOOTS_STAM:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET);
                id = 929;
                break;
            case WEP_CRUSADER_OFFHAND:
            case WEP_LIFESTEAL_OFFHAND:
            case WEP_FIERY_OFFHAND:
            case WEP_ICY_OFFHAND:
            case WEP_DEMONSLAYING_OFFHAND:
            case WEP1H_AGILITY_OFFHAND:
            case WEP_SPELLPOWER_OFFHAND:
            case WEP_HEAL_OFFHAND:
            case WEP_STEELWEAPONCHAIN_OFFHAND:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);
                if (item && item->GetProto()->Class != ITEM_CLASS_WEAPON)
                {
                    player->GetSession()->SendNotification("需要武器");
                    player->CLOSE_GOSSIP_MENU();
                    return true;
                }
                if (action == WEP_CRUSADER_OFFHAND)
                    id = 1900;
                else if (action == WEP_LIFESTEAL_OFFHAND)
                    id = 1898;
                else if (action == WEP_FIERY_OFFHAND)
                    id = 803;
                else if (action == WEP_ICY_OFFHAND)
                    id = 1894;
                else if (action == WEP_DEMONSLAYING_OFFHAND)
                    id = 912;
                else if (action == WEP1H_AGILITY_OFFHAND)
                    id = 2564;
                else if (action == WEP_SPELLPOWER_OFFHAND)
                    id = 2504;
                else if (action == WEP_HEAL_OFFHAND)
                    id = 2505;
                else if (action == WEP_STEELWEAPONCHAIN_OFFHAND)
                    id = 37;
                break;
        }
        Enchant(player, item, id);
        player->CLOSE_GOSSIP_MENU();
    }
    return true;
}

void LearnSkillRecipesHelper(Player *player, uint32 skill_id)
{
    uint32 classmask = player->GetClassMask();

    for (uint32 j = 0; j < sObjectMgr.GetMaxSkillLineAbilityId(); ++j)
    {
        SkillLineAbilityEntry const *skillLine = sObjectMgr.GetSkillLineAbility(j);
        if (!skillLine)
            continue;

        // wrong skill
        if (skillLine->skillId != skill_id)
            continue;

        // not high rank
        if (skillLine->forward_spellid)
            continue;

        // skip racial skills
        if (skillLine->racemask != 0)
            continue;

        // skip wrong class skills
        if (skillLine->classmask && (skillLine->classmask & classmask) == 0)
            continue;

        SpellEntry const* spellEntry = sSpellMgr.GetSpellEntry(skillLine->spellId);
        if (!spellEntry || !SpellMgr::IsSpellValid(spellEntry, player, false))
            continue;

        player->LearnSpell(skillLine->spellId, false);
    }
}

bool LearnAllRecipesInProfession(Player *pPlayer, SkillType skill)
{
    char* skill_name;

    SkillLineEntry const *SkillInfo = sSkillLineStore.LookupEntry(skill);
    skill_name = SkillInfo->name[sWorld.GetDefaultDbcLocale()];

    if (!SkillInfo)
    {
        sLog.Out(LOG_SCRIPTS, LOG_LVL_ERROR, "Profession NPC: received non-valid skill ID");
        return false;
    }

    pPlayer->SetSkill(SkillInfo->id, 300, 300);
    LearnSkillRecipesHelper(pPlayer, SkillInfo->id);
    pPlayer->GetSession()->SendNotification("All recipes for %s learned", skill_name);
    return true;
}

bool GossipHello_ProfessionNPC(Player* player, Creature* creature)
{

    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Alchemy",              GOSSIP_SENDER_MAIN, 1);
    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Blacksmithing",        GOSSIP_SENDER_MAIN, 2);
    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Leatherworking",       GOSSIP_SENDER_MAIN, 3);
    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Tailoring",            GOSSIP_SENDER_MAIN, 4);
    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Engineering",          GOSSIP_SENDER_MAIN, 5);
    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Enchanting",           GOSSIP_SENDER_MAIN, 6);
    //player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Jewelcrafting",      GOSSIP_SENDER_MAIN, 7);
    //player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Inscription",        GOSSIP_SENDER_MAIN, 8);
    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Herbalism",            GOSSIP_SENDER_MAIN, 9);
    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Skinning",             GOSSIP_SENDER_MAIN, 10);
    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Mining",               GOSSIP_SENDER_MAIN, 11);

    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "First Aid",            GOSSIP_SENDER_MAIN, 12);
    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Fishing",              GOSSIP_SENDER_MAIN, 13);
    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Cooking",              GOSSIP_SENDER_MAIN, 14);

    player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
    return true;
}

void CompleteLearnProfession(Player *pPlayer, Creature *pCreature, SkillType skill)
{
    if (pPlayer->GetFreePrimaryProfessionPoints() == 0 && !(skill == SKILL_COOKING || skill == SKILL_FIRST_AID))
    {
        pPlayer->GetSession()->SendNotification("You already know two primary professions.");
    }
    else
    {
        if (!LearnAllRecipesInProfession(pPlayer, skill))
            pPlayer->GetSession()->SendNotification("Internal error.");
    }
}

bool GossipSelect_ProfessionNPC(Player* player, Creature* creature, uint32 sender, uint32 action)
{
    switch (action)
    {
    case 1:
        if (!player->HasSkill(SKILL_ALCHEMY))
            CompleteLearnProfession(player, creature, SKILL_ALCHEMY);
        break;
    case 2:
        if (!player->HasSkill(SKILL_BLACKSMITHING))
            CompleteLearnProfession(player, creature, SKILL_BLACKSMITHING);
        break;
    case 3:
        if (!player->HasSkill(SKILL_LEATHERWORKING))
            CompleteLearnProfession(player, creature, SKILL_LEATHERWORKING);
        break;
    case 4:
        if (!player->HasSkill(SKILL_TAILORING))
            CompleteLearnProfession(player, creature, SKILL_TAILORING);
        break;
    case 5:
        if (!player->HasSkill(SKILL_ENGINEERING))
            CompleteLearnProfession(player, creature, SKILL_ENGINEERING);
        break;
    case 6:
        if (!player->HasSkill(SKILL_ENCHANTING))
            CompleteLearnProfession(player, creature, SKILL_ENCHANTING);
        break;
    case 7:
    case 8:
        break;
    case 9:
        if (!player->HasSkill(SKILL_HERBALISM))
            CompleteLearnProfession(player, creature, SKILL_HERBALISM);
        break;
    case 10:
        if (!player->HasSkill(SKILL_SKINNING))
            CompleteLearnProfession(player, creature, SKILL_SKINNING);
        break;
    case 11:
        if (!player->HasSkill(SKILL_MINING))
            CompleteLearnProfession(player, creature, SKILL_MINING);
        break;
    case 12:
        if (!player->HasSkill(SKILL_FIRST_AID))
            CompleteLearnProfession(player, creature, SKILL_FIRST_AID);
        break;
    case 13:
        if (!player->HasSkill(SKILL_FISHING))
            CompleteLearnProfession(player, creature, SKILL_FISHING);
        break;
    case 14:
        if (!player->HasSkill(SKILL_COOKING))
            CompleteLearnProfession(player, creature, SKILL_COOKING);
        break;
    }

    player->CLOSE_GOSSIP_MENU();
    return true;
}

/*
* Custom premade gear and spec scripts
*/

#define SPELL_LIGHTNING_VISUAL 24240

bool GossipHello_PremadeGearNPC(Player* player, Creature* creature)
{
    for (auto itr : sObjectMgr.GetPlayerPremadeGearTemplates())
    {
        if (itr.second.requiredClass == player->GetClass())
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, itr.second.name.c_str(), GOSSIP_SENDER_MAIN, itr.first);
        }
    }

    player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
    return true;
}

bool GossipSelect_PremadeGearNPC(Player* player, Creature* creature, uint32 sender, uint32 action)
{
    player->SendSpellGo(player, SPELL_LIGHTNING_VISUAL);
    sObjectMgr.ApplyPremadeGearTemplateToPlayer(action, player);
    player->CLOSE_GOSSIP_MENU();
    return true;
}

bool GossipHello_PremadeSpecNPC(Player* player, Creature* creature)
{
    for (auto itr : sObjectMgr.GetPlayerPremadeSpecTemplates())
    {
        if (itr.second.requiredClass == player->GetClass())
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, itr.second.name.c_str(), GOSSIP_SENDER_MAIN, itr.first);
        }
    }

    player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
    return true;
}

bool GossipSelect_PremadeSpecNPC(Player* player, Creature* creature, uint32 sender, uint32 action)
{
    player->SendSpellGo(player, SPELL_LIGHTNING_VISUAL);
    sObjectMgr.ApplyPremadeSpecTemplateToPlayer(action, player);
    player->CLOSE_GOSSIP_MENU();
    return true;
}

/*
* Custom training dummy script
*/

struct npc_training_dummyAI : ScriptedAI
{
    explicit npc_training_dummyAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        npc_training_dummyAI::Reset();
    }

    uint32 m_uiCombatTimer;
    std::unordered_map<ObjectGuid, time_t> attackers;

    void Reset() override
    {
        m_uiCombatTimer = 15000;
        attackers.clear();
    }

    void AttackStart(Unit* /*pWho*/) override {}

    void Aggro(Unit* pWho) override
    {
        SetCombatMovement(false);
    }

    void AddAttackerToList(Unit* pWho)
    {
        auto itr = attackers.find(pWho->GetObjectGuid());
        if (itr != attackers.end())
        {
            itr->second = std::time(nullptr);
        }
        else
        {
            attackers.emplace(pWho->GetObjectGuid(), std::time(nullptr));
        }
    }

    void DamageTaken(Unit* pWho, uint32& /*uiDamage*/) override
    {
        if (pWho)
            AddAttackerToList(pWho);
    }

    void SpellHit(SpellCaster* pWho, SpellEntry const* /*pSpell*/) override
    {
        if (Unit* pAttacker = ToUnit(pWho))
            AddAttackerToList(pAttacker);
    }

    void UpdateAI(uint32 const diff) override
    {
        if (m_creature->IsInCombat())
        {
            if (m_uiCombatTimer <= diff)
            {
                for (auto itr = attackers.begin(); itr != attackers.end();)
                {
                    Unit* pAttacker = m_creature->GetMap()->GetUnit(itr->first);

                    if (!pAttacker || !pAttacker->IsInWorld())
                    {
                        itr = attackers.erase(itr);
                        continue;
                    }
                    if (itr->second + 10 < std::time(nullptr))
                    {
                        m_creature->_removeAttacker(pAttacker);
                        m_creature->GetThreatManager().modifyThreatPercent(pAttacker, -101.0f);
                        itr = attackers.erase(itr);
                        continue;
                    }
                    ++itr;
                }

                if (m_creature->GetThreatManager().isThreatListEmpty())
                    EnterEvadeMode();

                m_uiCombatTimer = 15000;
            }
            else
                m_uiCombatTimer -= diff;
        }
    }
};

CreatureAI* GetAI_npc_training_dummy(Creature* pCreature)
{
    return new npc_training_dummyAI(pCreature);
}

struct npc_summon_debugAI : ScriptedAI
{
    uint32 m_maxSummonCount = 200;
    uint32 m_summonCount = 0;
    Creature *m_summons[200];

    npc_summon_debugAI(Creature *pCreature) : ScriptedAI(pCreature)
    {
        m_summonCount = 0;
        for (uint32 i = 0; i < m_maxSummonCount; ++i)
            m_summons[i] = nullptr;

        Reset();
    }

    void Reset() override
    {
        m_summonCount = 0;
        for (uint32 i = 0; i < m_maxSummonCount; ++i)
        {
            if (m_summons[i])
                ((TemporarySummon*)m_summons[i])->UnSummon();

            m_summons[i] = nullptr;
        }
    }


    void JustDied(Unit* /* killer */) override
    {
        Reset();
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_creature->GetVictim())
            return;

        if (m_summonCount >= m_maxSummonCount)
            return;

        m_summons[m_summonCount++] = m_creature->SummonCreature(12458, m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(), 0);
    }
};

CreatureAI* GetAI_custom_summon_debug(Creature *creature)
{
    return new npc_summon_debugAI(creature);
}

void AddSC_custom_creatures()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "custom_hardcore_reward_npc";
    newscript->pGossipHello = &GossipHello_Hardcore_Reward_NPC;
    newscript->pGossipSelect = &GossipSelect_Hardcore_Reward_NPC;
    newscript->RegisterSelf(false);

    newscript = new Script;
    newscript->Name = "custom_teleport_npc";
    newscript->pGossipHello = &GossipHello_TeleportNPC;
    newscript->pGossipSelect = &GossipSelect_TeleportNPC;
    newscript->RegisterSelf(false);

    newscript = new Script;
    newscript->Name = "npc_chromie";
    newscript->pGossipHello = &GossipHello_Chromie;
    newscript->pGossipSelect = &GossipSelect_Chromie;
    newscript->RegisterSelf(false);

    newscript = new Script;
    newscript->Name = "npc_black_knight";
    newscript->pGossipHello = &GossipHello_Black_Knight;
    newscript->pGossipSelect = &GossipSelect_Black_Knight;
    newscript->RegisterSelf(false);

    newscript = new Script;
    newscript->Name = "npc_elven_wisp";
    newscript->pGossipHello = &GossipHello_Elven_Wisp;
    newscript->pGossipSelect = &GossipSelect_Elven_Wisp;
    newscript->RegisterSelf(false);

    newscript = new Script;
    newscript->Name = "npc_twilight_disciple";
    newscript->pGossipHello = &GossipHello_Twilight_Disciple;
    newscript->pGossipSelect = &GossipSelect_Twilight_Disciple;
    newscript->RegisterSelf(false);

    newscript = new Script;
    newscript->Name = "npc_winterfall_ursa";
    newscript->pGossipHello = &GossipHello_Winterfall_Ursa;
    newscript->pGossipSelect = &GossipSelect_Winterfall_Ursa;
    newscript->RegisterSelf(false);

    newscript = new Script;
    newscript->Name = "npc_yarntown";
    newscript->pGossipHello = &GossipHello_Yarntown;
    newscript->pGossipSelect = &GossipSelect_Yarntown;
    newscript->RegisterSelf(false);

    newscript = new Script;
    newscript->Name = "npc_elder_timbermaw";
    newscript->pGossipHello = &GossipHello_Elder_Timbermaw;
    newscript->pGossipSelect = &GossipSelect_Elder_Timbermaw;
    newscript->RegisterSelf(false);

    newscript = new Script;
    newscript->Name = "npc_scarlet_traitor";
    newscript->pGossipHello = &GossipHello_Scarlet_Traitor;
    newscript->pGossipSelect = &GossipSelect_Scarlet_Traitor;
    newscript->RegisterSelf(false);

    newscript = new Script;
    newscript->Name = "npc_tirion_fordring_outland";
    newscript->pGossipHello = &GossipHello_Tirion_Fordring_Outland;
    newscript->pGossipSelect = &GossipSelect_Tirion_Fordring_Outland;
    newscript->RegisterSelf(false);

    newscript = new Script;
    newscript->Name = "npc_syndicate_onlookers";
    newscript->pGossipHello = &GossipHello_Syndicate_Onlookers;
    newscript->pGossipSelect = &GossipSelect_Syndicate_Onlookers;
    newscript->RegisterSelf(false);

    newscript = new Script;
    newscript->Name = "npc_foggy_zoltan";
    newscript->pGossipHello = &GossipHello_Foggy_Zoltan;
    newscript->pGossipSelect = &GossipSelect_Foggy_Zoltan;
    newscript->RegisterSelf(false);

    newscript = new Script;
    newscript->Name = "npc_brave_cow";
    newscript->pGossipHello = &GossipHello_Brave_Cow;
    newscript->pGossipSelect = &GossipSelect_Brave_Cow;
    newscript->RegisterSelf(false);

    newscript = new Script;
    newscript->Name = "npc_luke_skywalker";
    newscript->pGossipHello = &GossipHello_Luke_Skywalker;
    newscript->pGossipSelect = &GossipSelect_Luke_Skywalker;
    newscript->RegisterSelf(false);

    newscript = new Script;
    newscript->Name = "custom_enchant_npc";
    newscript->pGossipHello = &GossipHello_EnchantNPC;
    newscript->pGossipSelect = &GossipSelect_EnchantNPC;
    newscript->RegisterSelf(false);

    newscript = new Script;
    newscript->Name = "custom_transmog_npc";
    newscript->pGossipHello = &GossipHello_TransmogNPC;
    newscript->pGossipSelect = &GossipSelect_TransmogNPC;
    newscript->RegisterSelf(false);

    newscript = new Script;
    newscript->Name = "custom_reforge_npc";
    newscript->pGossipHello = &GossipHello_ReforgeNPC;
    newscript->pGossipSelect = &GossipSelect_ReforgeNPC;
    newscript->RegisterSelf(false);

    newscript = new Script;
    newscript->Name = "the_lord_of_sunlight_gwyn";
    newscript->pGossipHello = &GossipHello_Gwyn;
    newscript->pGossipSelect = &GossipSelect_Gwyn;
    newscript->RegisterSelf(false);

    newscript = new Script;
    newscript->Name = "custom_professions_npc";
    newscript->pGossipHello = &GossipHello_ProfessionNPC;
    newscript->pGossipSelect = &GossipSelect_ProfessionNPC;
    newscript->RegisterSelf(false);

    newscript = new Script;
    newscript->Name = "custom_premade_gear_npc";
    newscript->pGossipHello = &GossipHello_PremadeGearNPC;
    newscript->pGossipSelect = &GossipSelect_PremadeGearNPC;
    newscript->RegisterSelf(false);

    newscript = new Script;
    newscript->Name = "custom_premade_spec_npc";
    newscript->pGossipHello = &GossipHello_PremadeSpecNPC;
    newscript->pGossipSelect = &GossipSelect_PremadeSpecNPC;
    newscript->RegisterSelf(false);

    newscript = new Script;
    newscript->Name = "custom_npc_training_dummy";
    newscript->GetAI = &GetAI_npc_training_dummy;
    newscript->RegisterSelf(false);

    newscript = new Script;
    newscript->Name = "custom_npc_summon_debugAI";
    newscript->GetAI = &GetAI_custom_summon_debug;
    newscript->RegisterSelf(false);
}
