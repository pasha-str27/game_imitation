#pragma once
#include "Team.h"
#include "PlayerManager.h"
#include "HeroManager.h"

class TeamManager
{
	//зберігаємо дані про гравців і героїв
	PlayerManager player_manager;
	HeroManager hero_manager;
public:
	Team generate_new_team();//генерування першої команди
	Team generate_new_team(Team& first_team);//генерування другої команди
	TeamManager(PlayerManager&, HeroManager&);//констуктор
	std::string get_team_info(Team& team);//отримання інформації про команду
	bool find_player_on_team_by_player(Team& team, Player& player);//пошук гравця в заданій команді
	bool find_player_on_team_by_hero(Team& team, Hero& hero);//пошук героя в заданій команді
};