#pragma once
#include "Header.h"
#include <vector>

const int STEP = 1;


class TZoo
{
	typedef TAnimal * TPtrAnimal;

	/// �����
	std::vector<TPtrAnimal> Animals;

	/// ������������ ����������� ��������
	size_t Capacity;

	/// ���������� ������ � ��������
	size_t NumAnimals;

	/// ����� �����
	int Time;
public:
	TZoo(size_t capacity);
	bool AddNewAnimal(TAnimal ** newAnimal);
	void Work();
	~TZoo();
	void Kill(TAnimal * animal);
	void FinishDay();
	void Print();
	void CheckBirthday(int);
	bool Empty();
	void Born();
	TAnimal * Delete(std::string name);
};

TAnimal * GetNewAnimal(int key);
TAnimal * NewAnimal(std::string, int, int);
