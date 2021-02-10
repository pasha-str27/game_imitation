#include <iostream>
#include "Player.h"
#include "Hero.h"
#include "HeroManager.h"
#include "PlayerManager.h"
#include "GameManager.h"
#include "Session.h"
#include "Team.h"
#include "TeamManager.h"
#include <time.h>
#include <Windows.h>

int main()
{
	srand(time(NULL));
	SetConsoleOutputCP(1251);

	PlayerManager g;
	g.show_player_info();

	//GameManager game;
	//int count;
	//std::cout << "Кількість сесій: ";
	//std::cin >> count;


	//for (int i = 0; i < count; ++i)
	//	game.perform_game_session();


	//std::cout << "Результати ігор\n";
	//вивід результатів

	return 0;
}