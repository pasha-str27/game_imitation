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

int Player::get_id()
{
	return this->id;
}

std::string Player::get_name()
{
	return this->name;
}

int Player::get_rank()
{
	return this->rank;
}

void Player::set_rank(int rank)
{
	this->rank = rank;
}

std::string Player::get_info()
{
	return std::to_string(id)+"\t"+name+"\t"+std::to_string(rank);
}

Player Player::operator=(Player other)
{
	this->name = other.name;
	this->rank = other.rank;
	return *this;
}

bool operator==(Player& first, Player& other)
{
	return first.name == other.name && first.rank == other.rank;
}

//����������� ������� ��������� ��'����
int Player::counter = 0;