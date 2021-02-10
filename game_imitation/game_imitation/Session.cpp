#include "Session.h"
#include "TeamManager.h"

Session::Session(int start_time)
{
	this->start_time = start_time;
	TeamManager manag_team;
	this->team_one = manag_team.generate_new_team();
	this->team_one.set_name("team 1");
	this->team_two = manag_team.generate_new_team(team_one);
	this->team_two.set_name("team 2");
}

Session::Session()
{
}

void Session::calculate_winner()
{
}
