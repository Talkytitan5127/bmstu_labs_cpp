#pragma once
#include "TProboscidea.h"
#include <iostream>

class TElephas : public TProboscidea
{
	int Key = 3;

	int AgeChild = 6;
	int DayChild = 12;
	bool FlagChild = false;

	int AgeDeath = 30;
	int DayDeath = 4;
	int TimeDeath = 22;


public:
	TElephas()
		:TProboscidea()
	{}
	TElephas(const std::string &name, int age)
		:TProboscidea(name, age)
	{}
	void Live(int time) override
	{
		if (time >= 7 && time <= 10)
			std::cout << GetName() << " is getting up" << '\n';
		else if (time >= 11 && time <= 13)
			std::cout << GetName() << " is washing up" << '\n';
		else if (time >= 23 || time <= 6)
			std::cout << GetName() << " is sleeping" << '\n';
		else if (time >= 14 && time <= 20)
			std::cout << GetName() << " is walking" << '\n';
		else
			std::cout << GetName() << " is eating" << '\n';
	}
	void Birthday(int day) override
	{
		if (day % 7 == 0)
		{
			std::cout << GetName() << " was borned in this day" << '\n';
			PlusAge();
		}
	}
	void EndDay() override
	{
		if (GetAge() >= AgeDeath)
			DayDeath--;
		if (GetAge() >= AgeChild)
			DayChild--;
	}
	bool Death(int time) override
	{
		if (DayDeath <= 0 && TimeDeath == time)
			return true;
		else
			return false;
	}

	int GetDeath() override
	{
		return DayDeath;
	}

	int GetAgeDeath() override
	{
		return AgeDeath;
	}

	int GetKey() override
	{
		return Key;
	}

	int GetChild() override
	{
		return AgeChild;
	}

	void ChangeFlagChild() override
	{
		FlagChild = true;
	}

	bool GetFlagChild() override
	{
		return FlagChild;
	}

	int GetDayChild() override
	{
		return DayChild;
	}
};