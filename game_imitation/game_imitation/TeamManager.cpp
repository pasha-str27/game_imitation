#include "TeamManager.h"
#include "PlayerManager.h"
#include "HeroManager.h"
#include "Player.h"

Team TeamManager::generate_new_team()
{
    Team new_team;

    for (int i = 0; i < 5; ++i)
    {
        Player tmp;
        do
            tmp = player_manager.create_player();
        while (find_player_on_team_by_name(new_team, tmp));
        new_team[i].player_obj = tmp;
    }

    for (int i = 0; i < 5; ++i)
    {
        Hero tmp;
        do
            tmp = hero_manager.create_hero();
        while (find_player_on_team_by_hero(new_team, tmp));
        new_team[i].hero_obj = tmp;
    }
    return new_team;
}

bool TeamManager::find_player_on_team_by_name(Team team, Player player)
{
    for (int j = 0; j < 5; ++j)
        if (player == team[j].player_obj)
            return true;
    return false;
}

bool TeamManager::find_player_on_team_by_hero(Team team, Hero hero)
{
    for (int j = 0; j < 5; ++j)
        if (hero == team[j].hero_obj)
            return true;
    return false;
}

Team TeamManager::generate_new_team(Team first_team)
{
    Team new_team;
    for (int i = 0; i < 5; ++i)
    {
        Player tmp;
        do
            tmp = player_manager.create_player();
        while (find_player_on_team_by_name(new_team, tmp)|| find_player_on_team_by_name(first_team, tmp));
        new_team[i].player_obj = tmp;
    }

    for (int i = 0; i < 5; ++i)
    {
        Hero tmp;
        do
            tmp = hero_manager.create_hero();
        while (find_player_on_team_by_hero(new_team, tmp) || find_player_on_team_by_hero(first_team, tmp));
        new_team[i].hero_obj = tmp;
    }
    return new_team;
}

TeamManager::TeamManager()
{
}

std::string TeamManager::get_team_info(Team team)
{
    std::string info = "";
    for (int i = 0; i < 5; ++i)
        info += team[i].player_obj.get_info() + "\t" + team[i].hero_obj.get_info() + "\n";

    return info;
}


