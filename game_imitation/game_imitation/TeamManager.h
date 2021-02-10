#pragma once
#include "Team.h"
#include "PlayerManager.h"
#include "HeroManager.h"

class TeamManager
{
	PlayerManager player_manager;
	HeroManager hero_manager;
public:
	Team generate_new_team();
	Team generate_new_team(Team first_team);
	TeamManager();
	std::string get_team_info(Team team);
	bool find_player_on_team_by_name(Team team, Player player);
	bool find_player_on_team_by_hero(Team team, Hero hero);
};