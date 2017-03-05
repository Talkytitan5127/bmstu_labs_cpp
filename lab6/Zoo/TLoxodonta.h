#pragma once
#include "TProboscidea.h"
#include <iostream>

class TLoxodonta : public TProboscidea
{
	int Key = 4;

	int AgeChild = 10;
	int DayChild = 2;
	bool FlagChild = false;

	int AgeDeath = 15;
	int DayDeath = 12;
	int TimeDeath = 2;


public:
	TLoxodonta()
		:TProboscidea()
	{}
	TLoxodonta(const std::string &name, int age)
		:TProboscidea(name, age)
	{}
	void Live(int time) override
	{
		if (time >= 10 && time <= 12)
			std::cout << GetName() << " is getting up" << '\n';
		else if (time >= 11 && time <= 13)
			std::cout << GetName() << " is boxing" << '\n';
		else if (time >= 21 || time <= 9)
			std::cout << GetName() << " is sleeping" << '\n';
		else if (time >= 14 && time <= 20)
			std::cout << GetName() << " is running" << '\n';
		else
			std::cout << GetName() << " is drinking" << '\n';
	}
	void Birthday(int day) override
	{
		if (day % 4 == 0)
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