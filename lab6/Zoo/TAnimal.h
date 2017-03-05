#pragma once
#include <string>


class TAnimal
{
	std::string Name;
	int Age;

public:
	TAnimal();
	TAnimal(const std::string & name, int age);

	/// Используем деструктор по умолчанию.
	/// т.к. специальных действия для очистки объектов не требуется
	virtual ~TAnimal() = default;

	/// Абстрактный метод
	/// <param name="time"> Время суток </param>
	virtual void Live(int time) = 0;

	virtual bool Death(int time) = 0;

	virtual void EndDay() = 0;

	virtual int GetDeath() = 0;

	virtual int GetAgeDeath() = 0;

	virtual void Birthday(int day) = 0;

	virtual void PlusAge();

	virtual int GetKey() = 0;

	virtual int GetChild() = 0;

	virtual void ChangeFlagChild() = 0;

	virtual int GetDayChild() = 0;

	virtual bool GetFlagChild() = 0;

	std::string GetName() const;
	int GetAge() const;
};