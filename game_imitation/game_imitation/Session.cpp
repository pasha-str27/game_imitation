#include "Session.h"

Session::Session(int start_time, PlayerManager& player_manager, HeroManager& hero_manager) :manag_team(player_manager,hero_manager)
{
	this->start_time = start_time;
	this->team_one.set_data(manag_team.generate_new_team());
	this->team_one.set_name("team 1");
	team_one.calculate_damage();
	team_one.calculate_hp();
	this->team_two.set_data(manag_team.generate_new_team(team_one));
	this->team_two.set_name("team 2");
	info_start_game = manag_team.get_team_info(team_one) + "\n" + manag_team.get_team_info(team_two) + "\n";
	//info_start_game+=team_one.get_info()+"\n"+ team_two.get_info();
	team_two.calculate_damage();
	team_two.calculate_hp();
	calculate_winner(player_manager);
}

void Session::calculate_winner(PlayerManager& player_manager)
{
	if (team_one.get_all_hp() < team_one.get_all_damage())
	{
		winner = team_one;
		for (int i = 0; i < 5; ++i)
			team_two[i].player_obj.set_rank(team_two[i].player_obj.get_rank() - 25);
		for (int i = 0; i < 5; ++i)
			team_one[i].player_obj.set_rank(team_one[i].player_obj.get_rank() + 25);
	}		
	else
	{
		winner = team_two;
		for (int i = 0; i < 5; ++i)
			team_two[i].player_obj.set_rank(team_two[i].player_obj.get_rank() + 25);
		for (int i = 0; i < 5; ++i)
			team_one[i].player_obj.set_rank(team_one[i].player_obj.get_rank() - 25);
	}
	for (int i = 0; i < 5; ++i)
	{
		player_manager.get_player_by_id(team_two[i].player_obj.get_id())->set_rank(team_two[i].player_obj.get_rank());
		player_manager.get_player_by_id(team_one[i].player_obj.get_id())->set_rank(team_one[i].player_obj.get_rank());
	}

	info_end_game = manag_team.get_team_info(team_one) + "\n" + manag_team.get_team_info(team_two) + "\n";

}

std::string Session::get_info_before_start_game()
{
	return info_start_game;
}

std::string Session::get_info_finish_game()
{
	return info_end_game;
}
