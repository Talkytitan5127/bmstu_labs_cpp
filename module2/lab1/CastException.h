#pragma once

#include <iostream>
#include <exception>
#include <string>

class CastException 
	: public std::exception
{
public:
	virtual void what() = 0;
};

class LengthError 
	: public CastException
{
	void what()
	{
		std::cout << "Error!!! Out of int range." << '\n';
	}
};

class ErrorData 
	: public CastException
{
	void what()
	{
		std::cout << "Error!!. The original date isn't type of function." << '\n';
	}
};
