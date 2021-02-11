#pragma once
#include "Team.h"
#include "TeamManager.h"
#include "PlayerManager.h"
#include "HeroManager.h"

class Session
{
	int start_time;//час початку гри
	Team team_one;//перша команда
	Team team_two;//друга команда 
	Team winner;//команда-переможець
	TeamManager manag_team;//генератор команд
	std::string info_start_game;//інформація про команди перед початкуом гри
	std::string info_end_game;//інформація про команди після гри
public:
	Session(int start_time, PlayerManager&, HeroManager&);//конструктор
	void calculate_winner(PlayerManager&);//визначення переможця
	std::string get_info_before_start_game();//отримання інформації що була перед грою
	std::string get_info_finish_game();//отримання інформації після гри
};

