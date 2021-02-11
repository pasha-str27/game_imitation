#include <iostream>
#include <ctime>
#include <Windows.h>

#include "Player.h"
#include "Hero.h"
#include "HeroManager.h"
#include "PlayerManager.h"
#include "GameManager.h"
#include "Session.h"
#include "Team.h"
#include "TeamManager.h"

int main()
{
	srand(time(0));
	SetConsoleOutputCP(1251);

	//створюємо об'єкт для збереження інформації про всіх гравців
	PlayerManager player_manager;

	//створюємо об'єкт для збереження інформації про всіх героїв
	HeroManager hero_manager;

	//менеджер гри
	GameManager game;

	//вводимо кількість ігрових сесій
	int count;
	std::cout << "Кількість сесій: ";
	std::cin >> count;

	//запускаємо сесії гри
	for (int i = 0; i < count; ++i)
		game.perform_game_session(player_manager, hero_manager);
		
	//вивід результатів
	std::cout << "Результати ігор\n";
	game.print_info();

	return 0;
}