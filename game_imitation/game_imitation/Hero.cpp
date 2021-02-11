#include "Hero.h"

//����������� � �����������
Hero::Hero(std::string name, int hp,int damage)
{
	//����������� id ������
	++counter;
	id = counter;

	//��������� ��������� �������
	this->name = name;
	this->hp = hp;
	this->damage = damage;
}

Hero::Hero()
{
}

//������ ��� id
int Hero::get_id()
{
	return this->id;
}

//������ ��� ����
std::string Hero::get_name()
{
	return this->name;
}

//������ ��� ������'�
int Hero::get_hp()
{
	return this->hp;
}

//������ ��� �����
int Hero::get_damage()
{
	return this->damage;
}

//��������� �����
void Hero::set_data(Hero& other)
{
	this->id = other.id;
	this->hp = other.hp;
	this->name = other.name;
	this->damage = other.damage;
}

//��������� ���������� ��� �����
std::string Hero::get_info()
{
	//������� ����� � ��� ���� �����
	return std::to_string(id)+"\t"+name+"\t"+std::to_string(hp)+"\t"+ std::to_string(damage);
}

//�������� ����������
bool operator==(Hero& first, Hero& other)
{
	//��������� id ��'����
	return first.id == other.id;
}

//����������� ������� ��������� ��'����
int Hero::counter = 0;