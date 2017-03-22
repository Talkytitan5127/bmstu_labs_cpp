#include "CastException.h"

using namespace std;

template<typename T> 
T FromString(const string &data);

bool IsMaxInt(const string &Number)
{
	string max = "2147483647";
	if (Number > max)
		return false;
	else
		return true;
}

bool IsMaxFloat(const string &Number)
{
	string max = "2147483647.0";
	if (Number > max)
		return false;
	else
		return true;
}

template<>
bool FromString<bool>(const string &data)
{
	string str;
	for (int i = 0; i < data.size(); i++)
	{
		str.push_back(tolower(data[i]));
	}

	if ("true" == str)
		return true;
	else if ("false" == str)
		return false;
	else
		throw ErrorData();

}

int STOI(const string &num)
{
	int st = num.size() - 1;
	int res = 0;
	for (int i = 0; i < num.size(); i++)
	{
		res += (num[i] - '0') * pow(10, st);
		st--;
	}
	return res;
}

float STOF(const string &num)
{
	float res = 0;
	int dot = num.find('.');
	int st = dot - 1;
	for (int i = 0; i < num.size(); i++)
	{
		if (i == dot)
			continue;
		res += (num[i] - '0') * pow(10, st);
		st--;
	}
	return res;

}

template<>
int FromString<int>(const string &data)
{
	string Number;
	int Minus = 1;
	bool error = false;

	for (int i = 0; i < data.size(); i++)
	{
		if (data[i] == '-' && i == 0)
		{
			Minus = -1;
		}
		else if (isdigit(data[i]))
		{
			Number.push_back(data[i]);
		}
		else
		{
			error = true;
			break;
		}
	}

	if (error)
		throw ErrorData();

	if (Number.size() > 10 || (Number.size() == 10 && !IsMaxInt(Number)))
	{
		throw LengthError();
	}

	int Result = STOI(Number);

	Result *= Minus;

	return Result;
}

template<>
float FromString<float>(const string &data)
{
	bool error = false;
	int k = 0;
	int Minus = 1;
	string res;
	for (int i = 0; i < data.size(); i++)
	{
		if (data[i] == '-' && i == 0)
		{
			Minus = -1;
		}
		else if (isdigit(data[i]))
		{
			res.push_back(data[i]);
		}
		else if (data[i] == ',' || data[i] == '.')
		{
			res.push_back('.');
			k++;
		}
		else if (k > 1)
		{
			throw ErrorData();
		}
		else
		{
			throw ErrorData();
		}
	}

	if (!IsMaxFloat(res))
		throw LengthError();

	float result = STOF(res);

	result *= Minus;
	return result;
}


int main()
{
	string var1 = "asdfg";
	try
	{
		int a = FromString<int>(var1);
		cout << a << '\n';
	}
	catch (CastException &q)
	{
		q.what();
	}
	string var2 = "3456";
	try
	{
		int a = FromString<int>(var2);
		cout << a << '\n';
	}
	catch (CastException &q)
	{
		q.what();
	}
	string var3 = "-2345";
	try
	{
		int a = FromString<int>(var3);
		cout << a << '\n';
	}
	catch (CastException &q)
	{
		q.what();
	}
	string var4 = "123456798765432345678876543234567876543";
	try
	{
		int a = FromString<int>(var4);
		cout << a << '\n';
	}
	catch (CastException &q)
	{
		q.what();
	}
	string var5 = "TRUE";
	try
	{
		bool a = FromString<bool>(var5);
		cout << a << '\n';
	}
	catch (CastException &q)
	{
		q.what();
	}
	string var6 = "4h37";
	try
	{
		bool a = FromString<bool>(var6);
		cout << a << '\n';
	}
	catch (CastException &q)
	{
		q.what();
	}
	string var7 = "123.234";
	try
	{
		float a = FromString<float>(var7);
		cout << a << '\n';
	}
	catch (CastException &q)
	{
		q.what();
	}
	string var8 = "-123.43";
	try
	{
		float a = FromString<float>(var8);
		cout << a << '\n';
	}
	catch (CastException &q)
	{
		q.what();
	}
	string var9 = "-12df3.43";
	try
	{
		float a = FromString<float>(var9);
		cout << a << '\n';
	}
	catch (CastException &q)
	{
		q.what();
	}
	system("pause");
	return 0;
}
