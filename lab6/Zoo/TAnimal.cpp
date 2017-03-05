#include "TAnimal.h"

using namespace std;

TAnimal::TAnimal()
	: Name()
	, Age(0)
{ }

TAnimal::TAnimal(const std::string & name, int age)
	: Name(name)
	, Age(age)
{ }

std::string TAnimal::GetName() const
{
	return Name;
}

void TAnimal::PlusAge()
{
	Age++;
}

int TAnimal::GetAge() const
{
	return Age;
}