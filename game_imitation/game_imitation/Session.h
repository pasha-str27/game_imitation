#pragma once
#include "Team.h"
#include "TeamManager.h"
#include "PlayerManager.h"
#include "HeroManager.h"

class Session
{
	int start_time;
	Team team_one;
	Team team_two;
	Team winner;
	TeamManager manag_team;
	std::string info_start_game;
	std::string info_end_game;
public:
	Session(int start_time, PlayerManager&, HeroManager&);
	void calculate_winner(PlayerManager&);
	std::string get_info_before_start_game();
	std::string get_info_finish_game();
};

