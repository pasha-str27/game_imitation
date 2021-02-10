#pragma once
#include "Player.h"
#include "Hero.h"

struct team_member
{
	Player player_obj;
	Hero hero_obj;

	friend bool operator ==(team_member& first, team_member& other)
	{
		return first.player_obj == other.player_obj && first.hero_obj == other.hero_obj;
	}
};

class Team
{
	std::string name;
	team_member team_members[5];
public:
	Team();
	friend bool operator ==(Team& first, Team& other);
	Team operator=(Team other);
	void set_name(std::string name);
	team_member& operator[](int i);
	void set_player(Player player_obj, int index);
	void set_hero(Hero hero_obj, int index);
};

