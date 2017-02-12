#include <iostream>
#include "TString.h"
using namespace std;


TString::~TString()
{
	delete Data; // <summary> Удаление памяти, выделенную для Data </summary>
}


TString::TString()
{
	Data = nullptr; // <summary> Инициализация нулевым указателем </summary>
}


TString::TString(const char * data)
{
	//<summary> Нахождение длины data </summary>

	int len = 0;
	while (data[len] != '\0')
		len++;

	// <summary> Инициализация Data </summary>
	Data = new char[len + 1];
	for (int i = 0; i < len + 1; i++)
		Data[i] = data[i];
}


TString::TString(const TString& rhs)
{
	// <summary> Нахождение длины data </summary>

	int len = 0;
	while (rhs.Data[len] != '\0')
		len++;

	// <summary> Инициализация Data </summary>
	Data = new char[len + 1];
	for (int i = 0; i < len + 1; i++)
		Data[i] = rhs.Data[i];
}


TString & TString::operator=(const TString & rhs)
{
	// <summary> Проверка на сходство переданных данных </summary>

	if (Data == rhs.Data)
		return *this;

	// <summary> Нахождение длины rhs.Data </summary>

	int len = 0;
	while (rhs.Data[len] != '\0')
		len++;

	// <summary> Инициализация Data </summary>
	Data = new char[len + 1];
	for (int i = 0; i < len + 1; i++)
		Data[i] = rhs.Data[i];
	return *this;
}


TString & TString::operator+=(const TString & rhs)
{
	// <summary> Нахождение длин Data и rhs.Data </summary>

	int len1 = 0, len2 = 0;
	while (Data[len1] != '\0')
		len1++;
	while (rhs.Data[len2] != '\0')
		len2++;

	// <summary> Копирование Data в str </summary>

	int len = len1 + len2;
	char *str = (char*)malloc(len1*sizeof(char));
	for (int i = 0; i < len1 + 1; i++)
		str[i] = Data[i];

	// <summary> Инициализация Data </summary>
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
	// <summary> Проверка на пустую строку </summary>

	if (Data == nullptr)
	{
		if (rhs.Data[0] == '\0')
			return true;
		else
			return false;
	}

	// <summary> Нахождение длин Data и rhs.Data </summary>

	int len1 = 0, len2 = 0;
	while (Data[len1] != '\0')
		len1++;
	while (rhs.Data[len2] != '\0')
		len2++;

	// <summary> Сравнение длин двух строк </summary>

	if (len1 != len2)
		return false;
	else
	{
		//<summary> Сравнение строку по буквам </summary>

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
	// <summary> Нахождение длин строк Data и substr.Data </summary>

	int len1 = 0, len2 = 0;
	while (Data[len1] != '\0')
		len1++;
	while (substr.Data[len2] != '\0')
		len2++;

	// <summary> Проверка, является ли подстрока по длине больше чем сама строка </summary>

	if (len2 > len1)
		return -1;

	// <summary> Нахождение подстроки в строке </summary>

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

	//  <summary> Возвращается -1, т.к. во время выполнения цикла </summary>
	// <summary> не была найдена подстрока в строке </summary>

	return -1;
}


bool TString::operator<(const TString & rhs) const
{
	// <summary> строка меньше тогда, </summary>
	// <summary> когда код i-ой буквы первой строки </summary>
	// <summary> меньше кода i-ой буквы второй строки </summary>

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
	// <summary> Нахождение длины Data </summary>

	int len = 0;
	while (Data[len] != '\0')
		len++;

	// <summary> Копирование Data в str, изменяя </summary>
	// <summary> oldSymbol на newSymbol </summary>

	char *str = new char[len + 1];
	for (int i = 0; i < len + 1; i++)
	{
		if (Data[i] == oldSymbol)
			str[i] = newSymbol;
		else
			str[i] = Data[i];
	}

	// <summary> Инициализация Data </summary>
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
	// <summary> Проверка, является ли </summary>
	// <summary> первый символ Data </summary>
	// <summary> тем самым symbol </summary>

	if (Data[0] == symbol)
	{
		// <summary> Нахождение длины </summary>

		int len = 0;
		while (Data[len] != '\0')
			len++;

		// <summary> Нахождение индекса первого символа после symbol </summary>

		int i = 0;
		while (Data[i] == symbol)
			i++;

		// <summary> Копирование в str строки Data, </summary>
		// <summary> начиная с первого символа, </summary>
		// <summary> стоящего после symbol </summary>

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