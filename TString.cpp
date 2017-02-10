#include <iostream>
#include "TString.h"
using namespace std;


TString::~TString()
{
	delete [] Data; // Удаление памяти, выделенную для Data
}


TString::TString()
{
	Data = nullptr; // Инициализация нулевым указателем
}


TString::TString(const char * data)
{
	// Нахождение длины data

	int len = 0;
	while (data[len] != '\0')
		len++;

	// Инициализация Data

	Data = new char[len + 1];
	for (int i = 0; i < len + 1; i++)
		Data[i] = data[i];
}


TString::TString(const TString& rhs)
{
	// Нахождение длины data

	int len = 0;
	while (rhs.Data[len] != '\0')
		len++;

	// Инициализация Data

	Data = new char[len + 1];
	for (int i = 0; i < len + 1; i++)
		Data[i] = rhs.Data[i];
}


TString & TString::operator=(const TString & rhs)
{
	// Проверка на сходство переданных данных

	if (Data == rhs.Data)
		return *this;

	// Нахождение длины rhs.Data

	int len = 0;
	while (rhs.Data[len] != '\0')
		len++;

	// Инициализация Data

	Data = new char[len + 1];
	for (int i = 0; i < len + 1; i++)
		Data[i] = rhs.Data[i];
	return *this;
}


TString & TString::operator+=(const TString & rhs)
{
	// Нахождение длин Data и rhs.Data

	int len1 = 0, len2 = 0;
	while (Data[len1] != '\0')
		len1++;
	while (rhs.Data[len2] != '\0')
		len2++;

	// Копирование Data в str

	int len = len1 + len2;
	char *str = (char*)malloc(len1*sizeof(char));
	for (int i = 0; i < len1 + 1; i++)
		str[i] = Data[i];

	// Инициализация Data

	Data = new char[len + 1];
	int k = 0;
	for (int i = 0; i < len; i++)
	{
		if (i < len1)
			Data[i] = str[i];
		else
		{
			Data[i] = rhs.Data[k];
			k++;
		}
	}
	Data[len] = '\0';
	return *this;
}


bool TString::operator==(const TString & rhs) const
{
	// Проверка на пустую строку

	if (Data == nullptr)
	{
		if (rhs.Data[0] == '\0')
			return true;
		else
			return false;
	}

	// Нахождение длин Data и rhs.Data

	int len1 = 0, len2 = 0;
	while (Data[len1] != '\0')
		len1++;
	while (rhs.Data[len2] != '\0')
		len2++;

	// Сравнение длин двух строк

	if (len1 != len2)
		return false;
	else
	{
		//Сравнение строку по буквам

		bool fl = true;
		for (int i = 0; i < len1 + 1; i++)
		{
			if (Data[i] != rhs.Data[i])
			{
				fl = false;
				break;
			}
		}
		return fl;
	}
}


size_t TString::Find(const TString & substr) const
{
	// Нахождение длин строк Data и substr.Data

	int len1 = 0, len2 = 0;
	while (Data[len1] != '\0')
		len1++;
	while (substr.Data[len2] != '\0')
		len2++;

	// Проверка, является ли подстрока по длине больше чем сама строка

	if (len2 > len1)
		return -1;

	// Нахождение подстроки в строке

	int k = 0;
	for (int i = 0; i < len1; i++)
	{
		if (Data[i] == substr.Data[k])
		{
			int q = i;
			bool fl = true;
			while (k != len2)
			{
				if (Data[q] != substr.Data[k])
				{
					fl = false;
					break;
				}
				q++;
				k++;
			}
			if (fl)
				return i;
			k = 0;
		}
	}

	// Возвращается -1, т.к. во время выполнения цикла 
	// не была найдена подстрока в строке

	return -1;
}


bool TString::operator<(const TString & rhs) const
{
	// строка меньше тогда, 
	// когда код i-ой буквы первой строки 
	// меньше кода i-ой буквы второй строки 

	int i = 0;
	while (true)
	{
		char word1 = Data[i];
		char word2 = rhs.Data[i];
		if (int(word1) < int(word2))
			return true;
		else if (int(word1) > int(word2))
			return false;
		else if (word1 == '\0' && word2 != '\0')
			return true;
		else
			return false;
	}
}


void TString::Replace(char oldSymbol, char newSymbol)
{
	// Нахождение длины Data

	int len = 0;
	while (Data[len] != '\0')
		len++;

	// Копирование Data в str, изменяя
	// oldSymbol на newSymbol

	char *str = new char[len + 1];
	for (int i = 0; i < len + 1; i++)
	{
		if (Data[i] == oldSymbol)
			str[i] = newSymbol;
		else
			str[i] = Data[i];
	}

	// Инициализация Data

	Data = new char[len + 1];
	for (int i = 0; i < len + 1; i++)
		Data[i] = str[i];
}


size_t TString::Size() const
{
	int len = 0;
	while (Data[len] != '\0')
		len++;
	return len;
}

bool TString::Empty() const
{
	if (Data == nullptr || Data[0] == '\0')
		return true;
	else
		return false;
}

char TString::operator[](size_t index) const
{
	return Data[index];
}

char & TString::operator[](size_t index)
{
	return Data[index];
}

void TString::RTrim(char symbol)
{
	int len = 0;
	while (Data[len] != '\0')
		len++;
	if (Data[len - 1] == symbol)
	{
		for (int i = len - 1; Data[i] == symbol; i--)
			Data[i] = '\0';
	}
}

void TString::LTrim(char symbol)
{
	// Проверка, является ли 
	// первый символ Data 
	// тем самым symbol

	if (Data[0] == symbol)
	{
		// Нахождение длины

		int len = 0;
		while (Data[len] != '\0')
			len++;

		// Нахождение индекса первого символа после symbol

		int i = 0;
		while (Data[i] == symbol)
			i++;

		// Копирование в str строки Data, 
		// начиная с первого символа, 
		// стоящего после symbol

		char *str = new char[len + 1];
		int k = 0;
		for (i; i < len + 1; i++)
		{
			str[k] = Data[i];
			k++;
		}

		// Инициализация Data
		
		Data = new char[len + 1];
		i = 0;
		for (i; str[i] != '\0'; i++)
			Data[i] = str[i];
		Data[i] = '\0';
	}
}

std::ostream & operator<<(std::ostream &out, const TString &str)
{
	out << str.Data;
	return out;
}

TString operator+(const TString & a, const TString & b)
{
	TString str3;
	str3 = a;
	str3 += b;
	return str3;
}

bool operator>(const TString & a, const TString & b)
{
	if (a < b || a == b)
		return false;
	else
		return true;
}

bool operator!=(const TString & a, const TString & b)
{
	if (a == b)
		return false;
	else
		return true;
}