#include "Hero.h"

//конструктор з параметрами
Hero::Hero(std::string name, int hp,int damage)
{
	//ініціалізація id гравця
	++counter;
	id = counter;

	//присвоєння переданих значень
	this->name = name;
	this->hp = hp;
	this->damage = damage;
}

Hero::Hero()
{
}

//геттер для id
int Hero::get_id()
{
	return this->id;
}

//геттер для імені
std::string Hero::get_name()
{
	return this->name;
}

//геттер для здоров'я
int Hero::get_hp()
{
	return this->hp;
}

//геттер для урону
int Hero::get_damage()
{
	return this->damage;
}

//копіювання даних
void Hero::set_data(Hero& other)
{
	this->id = other.id;
	this->hp = other.hp;
	this->name = other.name;
	this->damage = other.damage;
}

//отримання інформації про героя
std::string Hero::get_info()
{
	//формуємо рядок з усіх полів класу
	return std::to_string(id)+"\t"+name+"\t"+std::to_string(hp)+"\t"+ std::to_string(damage);
}

//оператор поврівняння
bool operator==(Hero& first, Hero& other)
{
	//порівнюємо id об'єктів
	return first.id == other.id;
}

//ініціалізація кількості створених об'єктів
int Hero::counter = 0;