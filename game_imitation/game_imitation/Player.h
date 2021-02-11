#pragma once
#include <iostream>
#include <string>

class Player
{
	//id ������
	int id;
	//��'�
	std::string name;
	//����
	int rank;
	//������� ��������� �������
	static int counter;

public:
	Player(std::string name, int rank);//����������� � �����������
	Player();//����������� ��� ���������
	int get_id();//������ ��� id
	std::string get_name();//������ ��� ����
	int get_rank();//������ ��� �����
	void set_rank(int rank);//������ ��� �����
	friend bool operator ==(Player& first, Player& other);//�������� ���������
	std::string get_info();//��������� ���������� ��� ������
	void set_data(Player& player);//��������� �������
};