#pragma once
#include <list>
#include "Session.h"
#include "PlayerManager.h"
#include "HeroManager.h"

class GameManager
{
	std::list<Session>game_sessions;//список в якому зберігаємо інформацію про ігові сесії
public:
	void perform_game_session(PlayerManager&,HeroManager&);//початок ігрової сесії
	GameManager();//конструктор без параметрів
	void print_info();//вивід інформації про сесії
	~GameManager();//деструктор
};