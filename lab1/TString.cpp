#include <iostream>
#include "TString.h"
using namespace std;


TString::~TString()
{
	delete Data; // <summary> �������� ������, ���������� ��� Data </summary>
}


TString::TString()
{
	Data = nullptr; // <summary> ������������� ������� ���������� </summary>
}


TString::TString(const char * data)
{
	//<summary> ���������� ����� data </summary>

	int len = 0;
	while (data[len] != '\0')
		len++;

	// <summary> ������������� Data </summary>
	Data = new char[len + 1];
	for (int i = 0; i < len + 1; i++)
		Data[i] = data[i];
}


TString::TString(const TString& rhs)
{
	// <summary> ���������� ����� data </summary>

	int len = 0;
	while (rhs.Data[len] != '\0')
		len++;

	// <summary> ������������� Data </summary>
	Data = new char[len + 1];
	for (int i = 0; i < len + 1; i++)
		Data[i] = rhs.Data[i];
}


TString & TString::operator=(const TString & rhs)
{
	// <summary> �������� �� �������� ���������� ������ </summary>

	if (Data == rhs.Data)
		return *this;

	// <summary> ���������� ����� rhs.Data </summary>

	int len = 0;
	while (rhs.Data[len] != '\0')
		len++;

	// <summary> ������������� Data </summary>
	Data = new char[len + 1];
	for (int i = 0; i < len + 1; i++)
		Data[i] = rhs.Data[i];
	return *this;
}


TString & TString::operator+=(const TString & rhs)
{
	// <summary> ���������� ���� Data � rhs.Data </summary>

	int len1 = 0, len2 = 0;
	while (Data[len1] != '\0')
		len1++;
	while (rhs.Data[len2] != '\0')
		len2++;

	// <summary> ����������� Data � str </summary>

	int len = len1 + len2;
	char *str = (char*)malloc(len1*sizeof(char));
	for (int i = 0; i < len1 + 1; i++)
		str[i] = Data[i];

	// <summary> ������������� Data </summary>
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
	// <summary> �������� �� ������ ������ </summary>

	if (Data == nullptr)
	{
		if (rhs.Data[0] == '\0')
			return true;
		else
			return false;
	}

	// <summary> ���������� ���� Data � rhs.Data </summary>

	int len1 = 0, len2 = 0;
	while (Data[len1] != '\0')
		len1++;
	while (rhs.Data[len2] != '\0')
		len2++;

	// <summary> ��������� ���� ���� ����� </summary>

	if (len1 != len2)
		return false;
	else
	{
		//<summary> ��������� ������ �� ������ </summary>

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
	// <summary> ���������� ���� ����� Data � substr.Data </summary>

	int len1 = 0, len2 = 0;
	while (Data[len1] != '\0')
		len1++;
	while (substr.Data[len2] != '\0')
		len2++;

	// <summary> ��������, �������� �� ��������� �� ����� ������ ��� ���� ������ </summary>

	if (len2 > len1)
		return -1;

	// <summary> ���������� ��������� � ������ </summary>

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

	//  <summary> ������������ -1, �.�. �� ����� ���������� ����� </summary>
	// <summary> �� ���� ������� ��������� � ������ </summary>

	return -1;
}


bool TString::operator<(const TString & rhs) const
{
	// <summary> ������ ������ �����, </summary>
	// <summary> ����� ��� i-�� ����� ������ ������ </summary>
	// <summary> ������ ���� i-�� ����� ������ ������ </summary>

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
	// <summary> ���������� ����� Data </summary>

	int len = 0;
	while (Data[len] != '\0')
		len++;

	// <summary> ����������� Data � str, ������� </summary>
	// <summary> oldSymbol �� newSymbol </summary>

	char *str = new char[len + 1];
	for (int i = 0; i < len + 1; i++)
	{
		if (Data[i] == oldSymbol)
			str[i] = newSymbol;
		else
			str[i] = Data[i];
	}

	// <summary> ������������� Data </summary>
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
	// <summary> ��������, �������� �� </summary>
	// <summary> ������ ������ Data </summary>
	// <summary> ��� ����� symbol </summary>

	if (Data[0] == symbol)
	{
		// <summary> ���������� ����� </summary>

		int len = 0;
		while (Data[len] != '\0')
			len++;

		// <summary> ���������� ������� ������� ������� ����� symbol </summary>

		int i = 0;
		while (Data[i] == symbol)
			i++;

		// <summary> ����������� � str ������ Data, </summary>
		// <summary> ������� � ������� �������, </summary>
		// <summary> �������� ����� symbol </summary>

		char *str = new char[len + 1];
		int k = 0;
		for (i; i < len + 1; i++)
		{
			str[k] = Data[i];
			k++;
		}

		// ������������� Data
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