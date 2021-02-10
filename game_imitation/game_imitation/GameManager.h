#pragma once
#include <list>
#include "Session.h"
class GameManager
{
	std::list<Session>game_sessions;
public:
	void perform_game_session();
	GameManager();
	~GameManager();
};

