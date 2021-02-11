#include "Team.h"

//Team Team::operator=(Team& other)
//{
//	this->name = other.name;
//	for (int i = 0; i < 5; ++i)
//	{
//		this->team_members[i].hero_obj = other.team_members[i].hero_obj;
//		this->team_members[i].player_obj = other.team_members[i].player_obj;
//	}
//
//	return *this;
//}

void Team::set_name(std::string name)
{
	this->name = name;
}

team_member& Team::operator[](int i)
{
	return team_members[i];
}

void Team::set_player(Player& player_obj, int index)
{
	this->team_members[index].player_obj = player_obj;
}

void Team::set_hero(Hero& hero_obj, int index)
{
	this->team_members[index].hero_obj = hero_obj;
	all_hp = 0;
	all_damage = 0;
	for (int i = 0; i < 5; ++i)
	{
		all_hp+=this->team_members[i].hero_obj.get_hp();
		all_damage += this->team_members[i].hero_obj.get_damage();
	}
}

int Team::get_all_damage()
{
	return this->all_damage;
}

int Team::get_all_hp()
{
	return this->all_hp;
}

void Team::set_all_hp(int hp)
{
	this->all_hp = hp;
}

void Team::set_all_damage(int damage)
{
	this->all_damage = damage;
}

void Team::calculate_hp()
{
	all_hp = 0;
	for (int i = 0; i < 5; ++i)
		all_hp += team_members[i].hero_obj.get_hp();
}

void Team::calculate_damage()
{
	all_damage = 0;
	for (int i = 0; i < 5; ++i)
		all_damage += team_members[i].hero_obj.get_damage();
}

void Team::set_data(Team other)
{
	this->name = other.name;
	for (int i = 0; i < 5; ++i)
	{
		this->team_members[i].hero_obj = other.team_members[i].hero_obj;
		this->team_members[i].player_obj = other.team_members[i].player_obj;
	}
}

std::string Team::get_info()
{
	std::string info = name;
	for (int i = 0; i < 5; ++i)
		info += "\n";
	return std::string();
}

std::string Team::get_name()
{
	return name;
}

bool operator==(Team& first, Team& other)
{
	for (int i = 0; i < 5; ++i)
		if (first.team_members[i].hero_obj == other.team_members[i].hero_obj || first.team_members[i].player_obj == other.team_members[i].player_obj)
			return true;
	return false;
}
