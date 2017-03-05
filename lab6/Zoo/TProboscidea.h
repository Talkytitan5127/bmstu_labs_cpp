#pragma once

#include "TAnimal.h"
#include <iostream>

class TProboscidea : public TAnimal
{
public:
	TProboscidea()
		:TAnimal()
	{}

	TProboscidea(const std::string &name, int age)
		: TAnimal(name, age)
	{}
	virtual ~TProboscidea() = default;
};