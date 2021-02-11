#pragma once
#include <list>
#include "Session.h"
#include "PlayerManager.h"
#include "HeroManager.h"

class GameManager
{
	std::list<Session>game_sessions;
public:
	void perform_game_session(PlayerManager&,HeroManager&);
	GameManager();
	void print_info();
	~GameManager();
};

