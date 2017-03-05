#pragma once
#include "TArtiodactyla.h"
#include <iostream>

class TGiraffa : public TArtiodactyla
{
	int Key = 1;

	int AgeChild = 6;
	int DayChild = 15;
	bool FlagChild = false;

	int AgeDeath = 20;
	int DayDeath = 5;
	int TimeDeath = 6;


public:
	TGiraffa()
		:TArtiodactyla()
	{}
	TGiraffa(const std::string &name, int age)
		:TArtiodactyla(name, age)
	{}
	void Live(int time) override
	{
		if (time >= 10 && time <= 11)
			std::cout << GetName() << " is getting up" << '\n';
		else if (time >= 12 && time <= 14)
			std::cout << GetName() << " is eating" << '\n';
		else if (time >= 15 && time <= 17)
			std::cout << GetName() << " is playing chess" << '\n';
		else if (time >= 22 || time <= 9)
			std::cout << GetName() << " is sleeping" << '\n';
		else
			std::cout << GetName() << " is walking" << '\n';
	}
	void Birthday(int day) override
	{
		if (day % 9 == 0)
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