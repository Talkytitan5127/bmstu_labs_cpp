#pragma once
#include "TArtiodactyla.h"
#include <iostream>

class THippopotamus : public TArtiodactyla
{
	int Key = 2;

	int AgeChild = 12;
	int DayChild = 25;
	bool FlagChild = false;

	int AgeDeath = 30;
	int DayDeath = 15;
	int TimeDeath = 15;


public:
	THippopotamus()
		:TArtiodactyla()
	{}
	THippopotamus(const std::string &name, int age)
		:TArtiodactyla(name, age)
	{}
	void Live(int time) override
	{
		if (time >= 10 && time <= 11)
			std::cout << GetName() << " is getting up" << '\n';
		else if (time >= 12 && time <= 14)
			std::cout << GetName() << " is swimming" << '\n';
		else if (time >= 15 && time <= 17)
			std::cout << GetName() << " is eating " << '\n';
		else if (time >= 22 || time <= 9)
			std::cout << GetName() << " is sleeping" << '\n';
		else
			std::cout << GetName() << " is walking" << '\n';
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