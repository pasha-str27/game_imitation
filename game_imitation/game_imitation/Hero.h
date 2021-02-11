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
	Hero(std::string name, int hp,int damage);
	Hero();
	int get_id();
	std::string get_name();
	int get_hp();
	int get_damage();
	void set_data(Hero& other);
	friend bool operator ==(Hero& first, Hero& other);
	friend bool operator !=(Hero& first, Hero& other);
	//Hero operator=(Hero other);
	std::string get_info();
};

