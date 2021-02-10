#pragma once
#include "Team.h"
class TeamManager
{
public:
	Team generate_new_team();
	Team generate_new_team(Team first_team);
	TeamManager();
	std::string get_team_info(Team team);
};