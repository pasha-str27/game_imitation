#include "PlayerManager.h"
#include "string"
#include <iostream>
#include <iomanip>

//конструктор
PlayerManager::PlayerManager()
{
	//формуЇмо 10 гравц≥в з прим≥тивним ≥менем 
	for (int i = 0; i <10; ++i)
		players.push_back(Player("player"+std::to_string(i), 0));
}

//генерац≥€ гравц€
Player& PlayerManager::create_player()
{
	//повертаЇмо рандомного гравц€ з≥ списку
	return players[rand() % players.size()];
}

//пошук гравц€ за ≥менем
Player* PlayerManager::get_player_by_name(std::string name)
{
	//шукаЇмо гравц€ та повертаЇмо посиланн€ на нього
	for (int i = 0; i < players.size(); ++i)
		if (players[i].get_name() == name)
			return &players[i];

	//€кщо не знаходимо, поветраЇмо нульовий вказ≥вник
	return nullptr;
}

//пошук гравц€ за id
Player* PlayerManager::get_player_by_id(int id)
{
	//шукаЇмо гравц€ та повертаЇмо посиланн€ на нього
	for (int i = 0; i < players.size(); ++i)
		if (players[i].get_id() == id)
			return &players[i];

	//€кщо не знаходимо, поветраЇмо нульовий вказ≥вник
	return nullptr;
}

//видаленн€ гравц€
void PlayerManager::delete_player(Player& player)
{
	//проходимос€ по ус≥х гравц€х та шукаЇмо заданого гравц€
	for (int i = 0; i < players.size(); ++i)
		if (players[i] == player)
		{
			//€кщо знайшли, видал€Їмо його
			players.erase(players.begin() + i);
			return;
		}
}

//вив≥д ≥нформац≥њ про гравц≥в
void PlayerManager::show_players_info()
{
	//вив≥д на екран ≥нформац≥њ про вс≥х гравц≥в
	for (int i = 0; i < players.size(); ++i)
		std::cout << players[i].get_info() << std::endl;
}

//деструктор
PlayerManager::~PlayerManager()
{
	//очищенн€ пам'€т≥
	players.clear();
}