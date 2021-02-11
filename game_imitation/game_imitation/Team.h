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
	int all_hp;
	int all_damage;
public:
	friend bool operator ==(Team& first, Team& other);
	//Team operator=(Team& other);
	void set_name(std::string name);
	team_member& operator[](int i);
	void set_player(Player& player_obj, int index);
	void set_hero(Hero& hero_obj, int index);
	int get_all_damage();
	int get_all_hp();
	void set_all_hp(int hp);
	void set_all_damage(int damage);
	void calculate_hp();
	void calculate_damage();
	void set_data(Team other);
	std::string get_info();
	std::string get_name();
};

