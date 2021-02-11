#include "GameManager.h"
#include "TeamManager.h"

void GameManager::perform_game_session(PlayerManager &player_manager, HeroManager &hero_manager)
{
	game_sessions.push_back(Session(rand()%24+1, player_manager, hero_manager));
}

GameManager::GameManager()
{
}

void GameManager::print_info()
{
	int counter = 0;
	for (auto session : game_sessions)
	{
		std::cout << "Сесія " << counter + 1 << "\n\tсклад команд:\n";
		std::cout << "\t\t" << session.get_info_before_start_game() << "\n";
		std::cout <<"\tрезультат гри:\n";
		std::cout << "\t\t" << session.get_info_finish_game() << "\n";
		++counter;
	}
}

GameManager::~GameManager()
{
	game_sessions.clear();
}
