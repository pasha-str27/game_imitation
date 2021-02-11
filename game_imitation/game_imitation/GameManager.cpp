#include "GameManager.h"
#include "TeamManager.h"

//������� ������ ���
void GameManager::perform_game_session(PlayerManager &player_manager, HeroManager &hero_manager)
{
	//��������� ������ ���� � ��������� �������� �� �������� �� � ������
	game_sessions.push_back(Session(rand()%24+1, player_manager, hero_manager));
}

//����������� ��� ���������
GameManager::GameManager()
{
}

//���� ���������� ��� �� ���
void GameManager::print_info()
{
	//������� ���
	int counter = 0;

	//�������� ���������� ��� ����� ����
	for (auto session : game_sessions)
	{
		std::cout << "##################################################\n";
		std::cout << "���� " << counter + 1 << "\n\t����� ������:\n";
		std::cout << "\t\t" << session.get_info_before_start_game() << "\n";
		std::cout << "-----------------------------------------------------\n";
		std::cout <<"\t��������� ���:\n";
		std::cout << "\t\t" << session.get_info_finish_game() << "\n";
		++counter;
		std::cout << "##################################################\n";
	}
}

//����������
GameManager::~GameManager()
{
	//��������� ���'��
	game_sessions.clear();
}