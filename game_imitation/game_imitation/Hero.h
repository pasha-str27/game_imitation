#pragma once
#include <iostream>
#include <string>

class Hero
{
	//id героя
	int id;
	//ім'я
	std::string name;
	//життя
	int hp;
	//сила
	int damage;
	//кількість створених гравців
	static int counter;

public:
	Hero(std::string name, int hp,int damage);//конструктор з параметрами
	Hero();//конструктор без параметрів
	int get_id();//геттер для id
	std::string get_name();//геттер для імені
	int get_hp();//геттер для здоров'я
	int get_damage();//геттер для урону
	void set_data(Hero& other);//копіювання значень
	friend bool operator ==(Hero& first, Hero& other);//оператор порівняння
	std::string get_info();//отримання інформації про гравця
};

