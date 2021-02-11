#include "GameManager.h"
#include "TeamManager.h"

//початок ігрової сесії
void GameManager::perform_game_session(PlayerManager &player_manager, HeroManager &hero_manager)
{
	//створюємо ігрову сесію з рандомним початком та записуємо її в список
	game_sessions.push_back(Session(rand()%24+1, player_manager, hero_manager));
}

//конструктор без параметрів
GameManager::GameManager()
{
}

//вивід інформації про всі сесії
void GameManager::print_info()
{
	//кількість сесії
	int counter = 0;

	//виводимо інформацію про кожну сесію
	for (auto session : game_sessions)
	{
		std::cout << "##################################################\n";
		std::cout << "Сесія " << counter + 1 << "\n\tсклад команд:\n";
		std::cout << "\t\t" << session.get_info_before_start_game() << "\n";
		std::cout << "-----------------------------------------------------\n";
		std::cout <<"\tрезультат гри:\n";
		std::cout << "\t\t" << session.get_info_finish_game() << "\n";
		++counter;
		std::cout << "##################################################\n";
	}
}

//деструктор
GameManager::~GameManager()
{
	//звільнення пам'яті
	game_sessions.clear();
}