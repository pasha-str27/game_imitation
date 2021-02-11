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

	//PlayerManager g;
	//g.show_player_info();
	//a.generate_new_team();

	PlayerManager player_manager;
	HeroManager hero_manager;
	GameManager game;
	int count;
	std::cout << "Кількість сесій: ";
	std::cin >> count;


	for (int i = 0; i < count; ++i)
		game.perform_game_session(player_manager, hero_manager);
		


	std::cout << "Результати ігор\n";
	//вивід результатів

	game.print_info();


	return 0;
}