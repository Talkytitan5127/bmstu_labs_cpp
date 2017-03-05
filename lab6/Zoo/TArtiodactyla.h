#pragma once

#include "TAnimal.h"
#include <iostream>

class TArtiodactyla : public TAnimal
{
public:
	TArtiodactyla()
		:TAnimal()
	{}

	TArtiodactyla(const std::string &name, int age)
		: TAnimal(name, age)
	{}
	virtual ~TArtiodactyla() = default;
};