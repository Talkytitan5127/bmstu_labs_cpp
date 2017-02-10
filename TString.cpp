#include <iostream>
#include "TString.h"
using namespace std;


TString::~TString()
{
	delete [] Data; // �������� ������, ���������� ��� Data
}


TString::TString()
{
	Data = nullptr; // ������������� ������� ����������
}


TString::TString(const char * data)
{
	// ���������� ����� data

	int len = 0;
	while (data[len] != '\0')
		len++;

	// ������������� Data

	Data = new char[len + 1];
	for (int i = 0; i < len + 1; i++)
		Data[i] = data[i];
}


TString::TString(const TString& rhs)
{
	// ���������� ����� data

	int len = 0;
	while (rhs.Data[len] != '\0')
		len++;

	// ������������� Data

	Data = new char[len + 1];
	for (int i = 0; i < len + 1; i++)
		Data[i] = rhs.Data[i];
}


TString & TString::operator=(const TString & rhs)
{
	// �������� �� �������� ���������� ������

	if (Data == rhs.Data)
		return *this;

	// ���������� ����� rhs.Data

	int len = 0;
	while (rhs.Data[len] != '\0')
		len++;

	// ������������� Data

	Data = new char[len + 1];
	for (int i = 0; i < len + 1; i++)
		Data[i] = rhs.Data[i];
	return *this;
}


TString & TString::operator+=(const TString & rhs)
{
	// ���������� ���� Data � rhs.Data

	int len1 = 0, len2 = 0;
	while (Data[len1] != '\0')
		len1++;
	while (rhs.Data[len2] != '\0')
		len2++;

	// ����������� Data � str

	int len = len1 + len2;
	char *str = (char*)malloc(len1*sizeof(char));
	for (int i = 0; i < len1 + 1; i++)
		str[i] = Data[i];

	// ������������� Data

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
	// �������� �� ������ ������

	if (Data == nullptr)
	{
		if (rhs.Data[0] == '\0')
			return true;
		else
			return false;
	}

	// ���������� ���� Data � rhs.Data

	int len1 = 0, len2 = 0;
	while (Data[len1] != '\0')
		len1++;
	while (rhs.Data[len2] != '\0')
		len2++;

	// ��������� ���� ���� �����

	if (len1 != len2)
		return false;
	else
	{
		//��������� ������ �� ������

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
	// ���������� ���� ����� Data � substr.Data

	int len1 = 0, len2 = 0;
	while (Data[len1] != '\0')
		len1++;
	while (substr.Data[len2] != '\0')
		len2++;

	// ��������, �������� �� ��������� �� ����� ������ ��� ���� ������

	if (len2 > len1)
		return -1;

	// ���������� ��������� � ������

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

	// ������������ -1, �.�. �� ����� ���������� ����� 
	// �� ���� ������� ��������� � ������

	return -1;
}


bool TString::operator<(const TString & rhs) const
{
	// ������ ������ �����, 
	// ����� ��� i-�� ����� ������ ������ 
	// ������ ���� i-�� ����� ������ ������ 

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
	// ���������� ����� Data

	int len = 0;
	while (Data[len] != '\0')
		len++;

	// ����������� Data � str, �������
	// oldSymbol �� newSymbol

	char *str = new char[len + 1];
	for (int i = 0; i < len + 1; i++)
	{
		if (Data[i] == oldSymbol)
			str[i] = newSymbol;
		else
			str[i] = Data[i];
	}

	// ������������� Data

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
	// ��������, �������� �� 
	// ������ ������ Data 
	// ��� ����� symbol

	if (Data[0] == symbol)
	{
		// ���������� �����

		int len = 0;
		while (Data[len] != '\0')
			len++;

		// ���������� ������� ������� ������� ����� symbol

		int i = 0;
		while (Data[i] == symbol)
			i++;

		// ����������� � str ������ Data, 
		// ������� � ������� �������, 
		// �������� ����� symbol

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