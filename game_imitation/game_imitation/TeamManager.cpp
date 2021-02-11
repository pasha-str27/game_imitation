#include "TeamManager.h"
#include "PlayerManager.h"
#include "HeroManager.h"
#include "Player.h"

//генерація першої команди
Team TeamManager::generate_new_team()
{
    Team new_team;

    //генеруємо 5 учасників
    for (int i = 0; i < 5; ++i)
    {
        Player tmp;

        //рандомно обираємо учасників із списку, перевіряючи щоб вони не повторювалися
        do
            tmp = player_manager.create_player();
        while (find_player_on_team_by_player(new_team, tmp));

        //присвоюємо згенерованого учасника
        new_team[i].player_obj=tmp;
    }

    //генеруємо 5 героїв
    for (int i = 0; i < 5; ++i)
    {
        Hero tmp;

        //рандомно обираємо героїв із списку, перевіряючи щоб вони не повторювалися
        do
            tmp = hero_manager.create_hero();
        while (find_player_on_team_by_hero(new_team, tmp));

        //та запам'ятовуємо його
        new_team[i].hero_obj=tmp;
    }

    //повертаємо згенеровану команду
    return new_team;
}

//пошук гравця в команді
bool TeamManager::find_player_on_team_by_player(Team& team, Player& player)
{
    for (int j = 0; j < 5; ++j)
        if (player == team[j].player_obj)
            return true;

    return false;
}

//пошук героя в команді
bool TeamManager::find_player_on_team_by_hero(Team& team, Hero& hero)
{
    for (int j = 0; j < 5; ++j)
        if (hero == team[j].hero_obj)
            return true;

    return false;
}


//генерація другої команди
Team TeamManager::generate_new_team(Team& first_team)
{
    Team new_team;

    //генеруємо 5 учасників
    for (int i = 0; i < 5; ++i)
    {
        Player tmp;

        //рандомно обираємо гравців із списку, перевіряючи щоб вони не повторювалися в другій і першій команді
        do
            tmp = player_manager.create_player();
        while (find_player_on_team_by_player(new_team, tmp)|| find_player_on_team_by_player(first_team, tmp));
       
        //та запам'ятовуємо учасника
        new_team[i].player_obj = tmp;
    }

    //генеруємо 5 героїв
    for (int i = 0; i < 5; ++i)
    {
        Hero tmp;

        //рандомно обираємо героїв із списку, перевіряючи щоб вони не повторювалися в другій і першій команді
        do
            tmp = hero_manager.create_hero();
        while (find_player_on_team_by_hero(new_team, tmp) || find_player_on_team_by_hero(first_team, tmp));
        
        //та запам'ятовуємо героя
        new_team[i].hero_obj = tmp;
    }

    //повертаємо згенеровану команду
    return new_team;
}

//констуктор, копіювання переданих значень
TeamManager::TeamManager(PlayerManager& player_manager,HeroManager& hero_manager)
{
    this->player_manager = player_manager;
    this->hero_manager = hero_manager;
}

//отримання інформації про заданого героя
std::string TeamManager::get_team_info(Team& team)
{
    //формуємо рядок з даними про команду та поветраємо його
    std::string info = team.get_name()+"\n";

    for (int i = 0; i < 5; ++i)
        info += team[i].player_obj.get_info() + "\t" + team[i].hero_obj.get_info() + "\n";

    return info;
}