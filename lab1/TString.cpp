#include <iostream>
#include "TString.h"
using namespace std;


TString::~TString()
{
	delete [] Data; // Óäàëåíèå ïàìÿòè, âûäåëåííóþ äëÿ Data
}


TString::TString()
{
	Data = nullptr; // Èíèöèàëèçàöèÿ íóëåâûì óêàçàòåëåì
}


TString::TString(const char * data)
{
	// Íàõîæäåíèå äëèíû data

	int len = 0;
	while (data[len] != '\0')
		len++;

	// Èíèöèàëèçàöèÿ Data

	Data = new char[len + 1];
	for (int i = 0; i < len + 1; i++)
		Data[i] = data[i];
}


TString::TString(const TString& rhs)
{
	// Íàõîæäåíèå äëèíû data

	int len = 0;
	while (rhs.Data[len] != '\0')
		len++;

	// Èíèöèàëèçàöèÿ Data

	Data = new char[len + 1];
	for (int i = 0; i < len + 1; i++)
		Data[i] = rhs.Data[i];
}


TString & TString::operator=(const TString & rhs)
{
	// Ïðîâåðêà íà ñõîäñòâî ïåðåäàííûõ äàííûõ

	if (Data == rhs.Data)
		return *this;

	// Íàõîæäåíèå äëèíû rhs.Data

	int len = 0;
	while (rhs.Data[len] != '\0')
		len++;

	// Èíèöèàëèçàöèÿ Data

	Data = new char[len + 1];
	for (int i = 0; i < len + 1; i++)
		Data[i] = rhs.Data[i];
	return *this;
}


TString & TString::operator+=(const TString & rhs)
{
	// Íàõîæäåíèå äëèí Data è rhs.Data

	int len1 = 0, len2 = 0;
	while (Data[len1] != '\0')
		len1++;
	while (rhs.Data[len2] != '\0')
		len2++;

	// Êîïèðîâàíèå Data â str

	int len = len1 + len2;
	char *str = (char*)malloc(len1*sizeof(char));
	for (int i = 0; i < len1 + 1; i++)
		str[i] = Data[i];

	// Èíèöèàëèçàöèÿ Data

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
	// Ïðîâåðêà íà ïóñòóþ ñòðîêó

	if (Data == nullptr)
	{
		if (rhs.Data[0] == '\0')
			return true;
		else
			return false;
	}

	// Íàõîæäåíèå äëèí Data è rhs.Data

	int len1 = 0, len2 = 0;
	while (Data[len1] != '\0')
		len1++;
	while (rhs.Data[len2] != '\0')
		len2++;

	// Ñðàâíåíèå äëèí äâóõ ñòðîê

	if (len1 != len2)
		return false;
	else
	{
		//Ñðàâíåíèå ñòðîêó ïî áóêâàì

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
	// Íàõîæäåíèå äëèí ñòðîê Data è substr.Data

	int len1 = 0, len2 = 0;
	while (Data[len1] != '\0')
		len1++;
	while (substr.Data[len2] != '\0')
		len2++;

	// Ïðîâåðêà, ÿâëÿåòñÿ ëè ïîäñòðîêà ïî äëèíå áîëüøå ÷åì ñàìà ñòðîêà

	if (len2 > len1)
		return -1;

	// Íàõîæäåíèå ïîäñòðîêè â ñòðîêå

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

	// Âîçâðàùàåòñÿ -1, ò.ê. âî âðåìÿ âûïîëíåíèÿ öèêëà 
	// íå áûëà íàéäåíà ïîäñòðîêà â ñòðîêå

	return -1;
}


bool TString::operator<(const TString & rhs) const
{
	// ñòðîêà ìåíüøå òîãäà, 
	// êîãäà êîä i-îé áóêâû ïåðâîé ñòðîêè 
	// ìåíüøå êîäà i-îé áóêâû âòîðîé ñòðîêè 

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
	// Íàõîæäåíèå äëèíû Data

	int len = 0;
	while (Data[len] != '\0')
		len++;

	// Êîïèðîâàíèå Data â str, èçìåíÿÿ
	// oldSymbol íà newSymbol

	char *str = new char[len + 1];
	for (int i = 0; i < len + 1; i++)
	{
		if (Data[i] == oldSymbol)
			str[i] = newSymbol;
		else
			str[i] = Data[i];
	}

	// Èíèöèàëèçàöèÿ Data

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
	// Ïðîâåðêà, ÿâëÿåòñÿ ëè 
	// ïåðâûé ñèìâîë Data 
	// òåì ñàìûì symbol

	if (Data[0] == symbol)
	{
		// Íàõîæäåíèå äëèíû

		int len = 0;
		while (Data[len] != '\0')
			len++;

		// Íàõîæäåíèå èíäåêñà ïåðâîãî ñèìâîëà ïîñëå symbol

		int i = 0;
		while (Data[i] == symbol)
			i++;

		// Êîïèðîâàíèå â str ñòðîêè Data, 
		// íà÷èíàÿ ñ ïåðâîãî ñèìâîëà, 
		// ñòîÿùåãî ïîñëå symbol

		char *str = new char[len + 1];
		int k = 0;
		for (i; i < len + 1; i++)
		{
			str[k] = Data[i];
			k++;
		}

		// Èíèöèàëèçàöèÿ Data
		
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
