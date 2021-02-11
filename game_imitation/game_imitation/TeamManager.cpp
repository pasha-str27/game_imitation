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
        while (find_player_on_team_by_player(new_team, tmp));
        new_team[i].player_obj=tmp;
    }
    for (int i = 0; i < 5; ++i)
    {
        Hero tmp;
        do
            tmp = hero_manager.create_hero();
        while (find_player_on_team_by_hero(new_team, tmp));
        new_team[i].hero_obj=tmp;
    }
    new_team.calculate_hp();
    new_team.calculate_damage();
    std::cout<<new_team.get_info();
    return new_team;
}

bool TeamManager::find_player_on_team_by_player(Team& team, Player& player)
{
    for (int j = 0; j < 5; ++j)
        if (player == team[j].player_obj)
            return true;
    return false;
}

bool TeamManager::find_player_on_team_by_hero(Team& team, Hero& hero)
{
    for (int j = 0; j < 5; ++j)
        if (hero == team[j].hero_obj)
            return true;
    return false;
}

Team TeamManager::generate_new_team(Team& first_team)
{
    Team new_team;
    for (int i = 0; i < 5; ++i)
    {
        Player tmp;
        do
            tmp = player_manager.create_player();
        while (find_player_on_team_by_player(new_team, tmp)|| find_player_on_team_by_player(first_team, tmp));
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

TeamManager::TeamManager(PlayerManager& player_manager,HeroManager& hero_manager)
{
    this->player_manager = player_manager;
    this->hero_manager = hero_manager;
}

std::string TeamManager::get_team_info(Team& team)
{
    std::string info = team.get_name()+"\n";
    for (int i = 0; i < 5; ++i)
        info += team[i].player_obj.get_info() + "\t" + team[i].hero_obj.get_info() + "\n";

    return info;
}


