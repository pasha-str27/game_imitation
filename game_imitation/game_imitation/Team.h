#pragma once
#include "Player.h"
#include "Hero.h"

struct team_member//учасник команди
{
	Player player_obj;//гравець
	Hero hero_obj;//герой
};

class Team//команда
{
	std::string name;//назва
	team_member team_members[5];//учасники пов'язані з героями
public:
	void set_name(std::string name);//сеттер для назви команди
	team_member& operator[](int i);//індексатор, повертає потрібного члена команди
	int get_all_damage();//обрахунок урону
	int get_all_hp();//обрахунок здоров'я
	void set_data(Team other);//присвоєння всіх полів
	std::string get_name();//геттер для імені
};