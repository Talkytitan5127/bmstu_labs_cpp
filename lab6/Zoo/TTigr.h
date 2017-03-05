#pragma once
#include "TCarnivora.h"
#include <iostream>

class TTigr : public TCarnivora
{
	int Key = 6;

	int AgeChild = 5;
	int DayChild = 4;
	bool FlagChild = false;

	int AgeDeath = 12;
	int DayDeath = 8;
	int timeDeath = 4;

	
public:
	TTigr()
		:TCarnivora()
	{}
	TTigr(const std::string &name, int age)
		:TCarnivora(name, age)
	{}
	void Live(int time) override
	{
		if (time >= 5 && time <= 6)
			std::cout << GetName() << " is getting" << '\n';
		else if (time >= 12 && time <= 13)
			std::cout << GetName() << " is watching TV" << '\n';
		else if (time >= 15 && time <= 17)
			std::cout << GetName() << " is eating" << '\n';
		else if (time >= 20 || time <= 4)
			std::cout << GetName() << " is sleeping" << '\n';
		else
			std::cout << GetName() << " is walking" << '\n';
	}
	void EndDay() override
	{
		if (GetAge() >= AgeDeath)
			DayDeath--;
		if (GetAge() >= AgeDeath)
			DayChild--;
	}

	void Birthday(int day) override
	{
		if (day % 3 == 0)
		{
			std::cout << GetName() << " was borned in this day" << '\n';
			PlusAge();
		}
	}

	bool Death(int time) override
	{
		if (DayDeath == 0 && timeDeath == time)
			return true;
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
	
	int GetKey()
	{
		return Key;
	}
	int GetChild() override
	{
		return AgeChild;
	}
	bool GetFlagChild() override
	{
		return FlagChild;
	}

	void ChangeFlagChild() override
	{
		FlagChild = true;
	}
	int GetDayChild() override
	{
		return DayChild;
	}
};