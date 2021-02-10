#include "HeroManager.h"
#include "string"

HeroManager::HeroManager()
{
	for (int i = 0; i < 25; ++i)
		heroes.push_back(Hero("hero" + std::to_string(i+1),rand()%100+1,rand()%25+1));
}

Hero HeroManager::create_hero()
{
	return heroes[rand()%heroes.size()];
}

Hero* HeroManager::get_hero_by_name(std::string name)
{
	for (int i = 0; i < heroes.size(); ++i)
		if (heroes[i].get_name() == name)
			return &heroes[i];
	return nullptr;
}

Hero* HeroManager::get_hero_by_id(int id)
{
	if (id > heroes.size()||id<0)
		return nullptr;
	return &heroes[id - 1];
}

void HeroManager::delete_hero(Hero hero)
{
	for (int i = 0; i < heroes.size(); ++i)
		if (heroes[i] == hero)
		{
			heroes.erase(heroes.begin()+i);
			return;
		}
}

void HeroManager::show_hero_info()
{
	for (int i = 0; i < heroes.size(); ++i)
		std::cout << heroes[i].get_info() << std::endl;
}
