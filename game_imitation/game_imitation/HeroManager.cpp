#include "HeroManager.h"
#include "string"

//конструктор
HeroManager::HeroManager()
{
	//формуємо 10 героїв з примітивним іменем 
	for (int i = 0; i < 10; ++i)
		heroes.push_back(Hero("hero" + std::to_string(i),rand()%100+1,rand()%100+1));
}

//генерація героя
Hero& HeroManager::create_hero()
{
	//повертаємо рандомного героя зі списку
	return heroes[rand()%heroes.size()];
}

//пошук героя за іменем
Hero* HeroManager::get_hero_by_name(std::string name)
{
	//шукаємо героя та повертаємо посилання на нього
	for (int i = 0; i < heroes.size(); ++i)
		if (heroes[i].get_name() == name)
			return &heroes[i];

	//якщо не знаходимо, поветраємо нульовий вказівник
	return nullptr;
}

//пошук гравця за id
Hero* HeroManager::get_hero_by_id(int id)
{
	//якщо такого id не існує, повертаємо нульовий вказвник
	if (id > heroes.size()||id<0)
		return nullptr;

	//інакше повертаємо посилання на героя
	return &heroes[id - 1];
}

//видалення героя
void HeroManager::delete_hero(Hero hero)
{
	//проходимося по усіх героях та шукаємо заданого героя
	for (int i = 0; i < heroes.size(); ++i)
		if (heroes[i] == hero)
		{
			//якщо знайшли, видаляємо його
			heroes.erase(heroes.begin()+i);
			return;
		}
}

//вивід інформації про героїв
void HeroManager::show_hero_info()
{
	//вивід на екран інформації про всіх героїв
	for (int i = 0; i < heroes.size(); ++i)
		std::cout << heroes[i].get_info() << std::endl;
}

//деструктор
HeroManager::~HeroManager()
{
	//очищення пам'яті
	heroes.clear();
}
