#pragma once
#include "TCarnivora.h"
#include <iostream>

class TLeo : public TCarnivora
{
	int Key = 5;

	int AgeChild = 3;
	int DayChild = 5;
	bool FlagChild = false;

	int AgeDeath = 15;
	int DayDeath = 10;
	int TimeDeath = 12;

	
public:
	TLeo()
		:TCarnivora() 
	{}
	TLeo(const std::string &name, int age)
		:TCarnivora(name, age) 
	{}
	void Live(int time) override
	{
		if (time >= 8 && time <= 10)
			std::cout << GetName() << " is getting up" << '\n';
		else if (time >= 15 && time <= 17)
			std::cout << GetName() << " is eating" << '\n';
		else if (time >= 23 || time <= 7)
			std::cout << GetName() << " is sleeping" << '\n';
		else
			std::cout << GetName() << " is walking" << '\n';
	}
	void Birthday(int day) override
	{
		if (day % 5 == 0)
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

