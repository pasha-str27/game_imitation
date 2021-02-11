#include "Hero.h"

//конструктор з параметрами
Hero::Hero(std::string name, int hp,int damage)
{
	//≥н≥ц≥ал≥зац≥€ id гравц€
	++counter;
	id = counter;

	//присвоЇнн€ переданих значень
	this->name = name;
	this->hp = hp;
	this->damage = damage;
}

Hero::Hero()
{
}

int Hero::get_id()
{
	return this->id;
}

std::string Hero::get_name()
{
	return this->name;
}

int Hero::get_hp()
{
	return this->hp;
}

int Hero::get_damage()
{
	return this->damage;
}

void Hero::set_data(Hero& other)
{
	this->id = other.id;
	this->hp = other.hp;
	this->name = other.name;
	this->damage = other.damage;
}

//Hero Hero::operator=(Hero other)
//{
//	this->id = other.id;
//	this->name = other.name;
//	this->damage = other.damage;
//	this->hp = other.hp;
//	return *this;
//}

std::string Hero::get_info()
{
	return std::to_string(id)+"\t"+name+"\t"+std::to_string(hp)+"\t"+ std::to_string(damage);
}

//≥н≥ц≥ал≥зац≥€ к≥лькост≥ створених об'Їкт≥в
int Hero::counter = 0;

bool operator==(Hero& first, Hero& other)
{
	return first.id == other.id;
}

bool operator!=(Hero& first, Hero& other)
{
	return first.id != other.id;
}
