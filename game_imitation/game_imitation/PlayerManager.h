#pragma once
#include "Player.h"
#include <vector>

class PlayerManager
{
	std::vector<Player> players;//список гравц≥в
public:
	PlayerManager();//конструктор
	Player& create_player();//генерац≥€ гравц€
	Player* get_player_by_name(std::string name);//отриманн€ гравц€ за ≥менем
	Player* get_player_by_id(int id);//отриманн€ гравц€ за id
	void delete_player(Player& player);//видаленн€ гравц€
	void show_players_info();//вив≥д ≥нформац≥њ про гравц≥в
	~PlayerManager();//деструктор
};