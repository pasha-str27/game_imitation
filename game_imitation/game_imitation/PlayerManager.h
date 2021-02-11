#pragma once
#include "Player.h"
#include <vector>

class PlayerManager
{
	std::vector<Player> players;
public:
	PlayerManager();
	Player& create_player();
	Player* get_player_by_name(std::string name);
	Player* get_player_by_id(int id);
	void delete_player(Player& player);
	void show_player_info();
	~PlayerManager();
};

