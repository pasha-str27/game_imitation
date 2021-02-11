#include "Player.h"

//����������� � �����������
Player::Player(std::string name, int rank)
{
	//����������� id ������
	++counter;
	id = counter;

	//��������� ��������� �������
	this->name = name;
	this->rank = rank;
}

Player::Player()
{
}

//������ ��� id
int Player::get_id()
{
	return this->id;
}

//������ ��� ����
std::string Player::get_name()
{
	return this->name;
}

//������ ��� �����
int Player::get_rank()
{
	return this->rank;
}

//������ ��� �����
void Player::set_rank(int rank)
{
	this->rank = rank;
}

//��������� ���������� ��� ������
std::string Player::get_info()
{
	//������� ����� � ��� ���� �����
	return std::to_string(id)+"\t"+name+"\t"+std::to_string(rank);
}

//�������� ����������
bool operator==(Player& first, Player& other)
{
	//��������� id ��'����
	return first.id == other.id;
}

//��������� ����� � ������ ��'����
void Player::set_data(Player& player)
{
	this->id = player.id;
	this->name = player.name;
	this->rank = player.rank;
}

//����������� ������� ��������� ��'����
int Player::counter = 0;