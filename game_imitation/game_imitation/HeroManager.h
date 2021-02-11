#pragma once
#include "Hero.h"
#include <vector>

class HeroManager
{
	std::vector<Hero>heroes;//список гравців
public:
	HeroManager();//конструктор
	Hero& create_hero();//генерація героя
	Hero* get_hero_by_name(std::string name);//отримання героя за іменем
	Hero* get_hero_by_id(int id);//отримання героя за id
	void delete_hero(Hero hero);//видалення героя
	void show_hero_info();//вивід інформації про героїв
	~HeroManager();//деструктор
};