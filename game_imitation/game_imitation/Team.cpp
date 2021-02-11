#include "Team.h"

//������ ��� ����, ��������� ��������
void Team::set_name(std::string name)
{
	this->name = name;
}

//����������, ������ �������� ������� � �������� �
team_member& Team::operator[](int i)
{
	return team_members[i];
}

//��������� ����� ������� �� ���� ����������
int Team::get_all_damage()
{
	int all_damage = 0;
	for (int i = 0; i < 5; ++i)
		all_damage += team_members[i].hero_obj.get_damage();

	return all_damage;
}

//��������� ������'� ������� �� ���� ����������
int Team::get_all_hp()
{
	int all_hp = 0;
	for (int i = 0; i < 5; ++i)
		all_hp += team_members[i].hero_obj.get_hp();
	return all_hp;
}

//��������� ����� � ������ ������� � �������
void Team::set_data(Team other)
{
	this->name = other.name;
	for (int i = 0; i < 5; ++i)
	{
		this->team_members[i].hero_obj = other.team_members[i].hero_obj;
		this->team_members[i].player_obj = other.team_members[i].player_obj;
	}
}

//������ ��� ����
std::string Team::get_name()
{
	return name;
}