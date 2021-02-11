#pragma once
#include <iostream>
#include <string>

//клас player
class Player
{
	//id гравц€
	int id;
	//≥м'€
	std::string name;
	//ранг
	int rank;
	//к≥льк≥сть створених гравц≥в
	static int counter;

public:
	Player(std::string name, int rank);
	Player();
	int get_id();
	std::string get_name();
	int get_rank();
	void set_rank(int rank);
	friend bool operator ==(Player& first, Player& other);
	bool operator !=(Player& other);
	//Player operator=(Player other);
	std::string get_info();
	void set_data(Player& player);
};