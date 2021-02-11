#include "Player.h"

//конструктор з параметрами
Player::Player(std::string name, int rank)
{
	//ініціалізація id гравця
	++counter;
	id = counter;

	//присвоєння переданих значень
	this->name = name;
	this->rank = rank;
}

Player::Player()
{
}

//геттер для id
int Player::get_id()
{
	return this->id;
}

//геттер для імені
std::string Player::get_name()
{
	return this->name;
}

//геттер для рангу
int Player::get_rank()
{
	return this->rank;
}

//сеттер для рангу
void Player::set_rank(int rank)
{
	this->rank = rank;
}

//отримання інформації про гравця
std::string Player::get_info()
{
	//формуємо рядок з усіх полів класу
	return std::to_string(id)+"\t"+name+"\t"+std::to_string(rank);
}

//оператор поврівняння
bool operator==(Player& first, Player& other)
{
	//порівнюємо id об'єктів
	return first.id == other.id;
}

//копіювання даних з іншого об'єкта
void Player::set_data(Player& player)
{
	this->id = player.id;
	this->name = player.name;
	this->rank = player.rank;
}

//ініціалізація кількості створених об'єктів
int Player::counter = 0;