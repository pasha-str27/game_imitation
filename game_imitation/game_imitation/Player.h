#pragma once
#include <iostream>
#include <string>

class Player
{
	//id гравця
	int id;
	//ім'я
	std::string name;
	//ранг
	int rank;
	//кількість створених гравців
	static int counter;

public:
	Player(std::string name, int rank);//конструктор з параметрами
	Player();//конструктор без параметрів
	int get_id();//геттер для id
	std::string get_name();//геттер для імені
	int get_rank();//геттер для рангу
	void set_rank(int rank);//сеттер для рангу
	friend bool operator ==(Player& first, Player& other);//оператор порівняння
	std::string get_info();//отримання інформації про гравця
	void set_data(Player& player);//копіювання значень
};