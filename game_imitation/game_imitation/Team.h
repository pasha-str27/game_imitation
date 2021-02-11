#pragma once
#include "Player.h"
#include "Hero.h"

struct team_member//������� �������
{
	Player player_obj;//�������
	Hero hero_obj;//�����
};

class Team//�������
{
	std::string name;//�����
	team_member team_members[5];//�������� ���'���� � �������
public:
	void set_name(std::string name);//������ ��� ����� �������
	team_member& operator[](int i);//����������, ������� ��������� ����� �������
	int get_all_damage();//��������� �����
	int get_all_hp();//��������� ������'�
	void set_data(Team other);//��������� ��� ����
	std::string get_name();//������ ��� ����
};