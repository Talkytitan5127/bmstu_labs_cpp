#ifndef TINTEGER_TINTEGER_H
#define TINTEGER_TINTEGER_H

#include <iostream>
#include <exception>
#include <climits>

class LengthError : public std::exception
{
public:
	void what()
	{
		std::cout << "Length error\n";
	}
};

class TInteger
{
	int Data;
public:
	TInteger();
	TInteger(long long int);
	~TInteger() = default;
	int Get();
	TInteger & operator=(const TInteger &);
	TInteger & operator=(const long long int);
	bool operator==(const TInteger &);
	bool operator==(const long long int);
	TInteger & operator+=(const TInteger &);
	TInteger & operator+=(const long long int);
	TInteger & operator-=(const TInteger &);
	TInteger & operator-=(const long long int);
	TInteger & operator*=(const TInteger &);
	TInteger & operator*=(const long long int);
	TInteger & operator/=(const TInteger &);
	TInteger & operator/=(const long long int);
	TInteger & operator%=(const TInteger &);
	TInteger & operator%=(const long long int);
	bool operator>(const TInteger &);
	bool operator>(const long long int);
	friend std::ostream & operator<<(std::ostream&, const TInteger &);
};
void Right(long long int);
TInteger operator+(TInteger &,  TInteger &);
TInteger operator+(TInteger &, const long long int);
TInteger operator+(const long long int, TInteger&);
TInteger operator-(TInteger &, TInteger &);
TInteger operator-(TInteger &, const long long int);
TInteger operator-(const long long int, TInteger&);
TInteger operator*(TInteger &, TInteger &);
TInteger operator*(TInteger &, const long long int);
TInteger operator*(const long long int, TInteger&);
TInteger operator/(TInteger &, TInteger &);
TInteger operator/(TInteger &, const long long int);
TInteger operator/(const long long int, TInteger&);
TInteger operator%(TInteger &, TInteger &);
TInteger operator%(TInteger &, const long long int);
TInteger operator%(const long long int, TInteger&);
bool operator!=(TInteger &, TInteger &);
bool operator!=(TInteger &, const long long int);
bool operator!=(const long long int, TInteger&);
bool operator<(TInteger &, TInteger &);
bool operator<(TInteger &, const long long int);
bool operator<(const long long int, TInteger&);
#endif //TINTEGER_TINTEGER_H
