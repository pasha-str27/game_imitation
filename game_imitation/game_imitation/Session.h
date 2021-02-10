#pragma once
#include "Team.h"

class Session
{
	int start_time;
	Team team_one;
	Team team_two;
	Team winner;
public:
	Session(int start_time);
	Session();
	void calculate_winner();
};

