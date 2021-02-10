#include "GameManager.h"
#include "TeamManager.h"
#include <time.h>

void GameManager::perform_game_session()
{
	TeamManager meneg_team;
	game_sessions.push_back(Session(rand()%24+1));
}

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
	game_sessions.clear();
}
