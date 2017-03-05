#pragma once

#include "TAnimal.h"
#include <iostream>


class TCarnivora : public TAnimal
{
public:
	TCarnivora()
		:TAnimal()
	{}

	TCarnivora(const std::string &name, int age)
		: TAnimal(name, age)
	{}
	virtual ~TCarnivora() = default;
};