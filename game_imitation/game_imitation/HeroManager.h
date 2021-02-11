#pragma once
#include "Hero.h"
#include <vector>

class HeroManager
{
	std::vector<Hero>heroes;
public:
	HeroManager();
	Hero& create_hero();
	Hero* get_hero_by_name(std::string name);
	Hero* get_hero_by_id(int id);
	void delete_hero(Hero hero);
	void show_hero_info();
	~HeroManager();
};