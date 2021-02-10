#include "Team.h"

Team::Team()
{
	
}

Team Team::operator=(Team other)
{
	this->name = other.name;
	for (int i = 0; i < 5; ++i)
	{
		this->team_members[i].hero_obj = other.team_members[i].hero_obj;
		this->team_members[i].player_obj = other.team_members[i].player_obj;
	}

	return *this;
}

void Team::set_name(std::string name)
{
	this->name = name;
}

team_member& Team::operator[](int i)
{
	return team_members[i];
}

void Team::set_player(Player player_obj, int index)
{
	this->team_members[index].player_obj = player_obj;
}

void Team::set_hero(Hero hero_obj, int index)
{
	this->team_members[index].hero_obj = hero_obj;
}

bool operator==(Team& first, Team& other)
{
	for (int i = 0; i < 5; ++i)
		if (first.team_members[i].hero_obj == other.team_members[i].hero_obj || first.team_members[i].player_obj == other.team_members[i].player_obj)
			return true;
	return false;
}
