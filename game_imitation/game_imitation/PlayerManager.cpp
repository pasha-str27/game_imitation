#include "PlayerManager.h"
#include "string"
#include <iostream>
#include <iomanip>

PlayerManager::PlayerManager()
{
	for (int i = 0; i < 25; ++i)
		players.push_back(Player("player "+std::to_string(i+1), 0));
}

Player PlayerManager::create_player()
{
	return players[rand()%players.size()];
}

Player* PlayerManager::get_player_by_name(std::string name)
{
	for (int i = 0; i < players.size(); ++i)
		if (players[i].get_name() == name)
			return &players[i];
	return nullptr;
}

Player* PlayerManager::get_player_by_id(int id)
{
	for (int i = 0; i < players.size(); ++i)
		if (players[i].get_id() == id)
			return &players[i];
	return nullptr;
}

void PlayerManager::delete_player(Player player)
{
	for (int i = 0; i < players.size(); ++i)
		if (players[i] == player)
		{
			players.erase(players.begin() + i);
			return;
		}
}

void PlayerManager::show_player_info()
{
	for (int i = 0; i < players.size(); ++i)
		std::cout << players[i].get_info() << std::endl;
}
