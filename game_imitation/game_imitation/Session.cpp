#include "Session.h"

//конструктор
Session::Session(int start_time, PlayerManager& player_manager, HeroManager& hero_manager) :manag_team(player_manager, hero_manager)
{
	//запам'ятовуємо початок гри
	this->start_time = start_time;
	//генеруємо першу команду та присвоюємо для неї ім'я
	this->team_one.set_data(manag_team.generate_new_team());
	this->team_one.set_name("team 1");

	//генеруємо другу команду та присвоюємо для неї ім'я
	this->team_two.set_data(manag_team.generate_new_team(team_one));
	this->team_two.set_name("team 2");

	//формуємо інформацію про команди перед грою
	info_start_game = manag_team.get_team_info(team_one) + "\n" + manag_team.get_team_info(team_two) + "\n";

	//визначаємо переможця
	calculate_winner(player_manager);
}

//визначення переможця
void Session::calculate_winner(PlayerManager& player_manager)
{
	//якщо здоровя першої команди менше за урон другої то виграла друга команда
	if (team_one.get_all_hp() - team_two.get_all_damage() < team_two.get_all_hp() - team_one.get_all_damage())
	{
		//запам'ятовуємо переможця
		winner = team_two;

		//змінюємо рейтинг для гравців команди що виграла
		for (int i = 0; i < 5; ++i)
			team_two[i].player_obj.set_rank(team_two[i].player_obj.get_rank() + 25);

		//змінюємо рейтинг для гравців команди що програла
		for (int i = 0; i < 5; ++i)
			team_one[i].player_obj.set_rank(team_one[i].player_obj.get_rank() - 25);
	}
	else//інакше виграла перша команда
	{
		//запам'ятовуємо переможця
		winner = team_one;

		//змінюємо рейтинг для гравців команди що програла
		for (int i = 0; i < 5; ++i)
			team_two[i].player_obj.set_rank(team_two[i].player_obj.get_rank() - 25);

		//змінюємо рейтинг для гравців команди що виграла
		for (int i = 0; i < 5; ++i)
			team_one[i].player_obj.set_rank(team_one[i].player_obj.get_rank() + 25);
	}

	//змінюємо значення рейтингу в гловаьному списку гравців
	for (int i = 0; i < 5; ++i)
	{
		player_manager.get_player_by_id(team_two[i].player_obj.get_id())->set_rank(team_two[i].player_obj.get_rank());
		player_manager.get_player_by_id(team_one[i].player_obj.get_id())->set_rank(team_one[i].player_obj.get_rank());
	}

	//формуємо інформацію про команду після закінчення гри
	info_end_game = manag_team.get_team_info(team_one) + "\n" + manag_team.get_team_info(team_two) + "\n";
}

//отримання інформації перед початком гри
std::string Session::get_info_before_start_game()
{
	return info_start_game;
}


//отримання інформації після гри
std::string Session::get_info_finish_game()
{
	return info_end_game;
}