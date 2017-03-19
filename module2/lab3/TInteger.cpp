#include "TInteger.h"

void Right(long long int data)
{
	if (data < INT_MIN || data > INT_MAX)
		throw LengthError();
}

TInteger::TInteger()
{
	Data = 0;
}
TInteger::TInteger(long long int data)
{
	Right(data);
	Data = data;
}
int TInteger::Get()
{
	return Data;
}
TInteger& TInteger::operator=(const TInteger & rhs)
{
	Data = rhs.Data;
	return *this;
}
TInteger& TInteger::operator=(long long int data)
{
	Data = data;
	return *this;
}
TInteger& TInteger::operator+=(const TInteger & rhs)
{
	Right(Data + rhs.Data);
	Data += rhs.Data;
	return *this;
}
TInteger& TInteger::operator+=(long long int data)
{
	Right(Data + data);
	Data += data;
	return *this;
}
bool TInteger::operator==(const TInteger & rhs)
{
	return Data == rhs.Data;
}
bool TInteger::operator==(long long int data)
{
	return Data == data;
}
TInteger& TInteger::operator-=(const TInteger & rhs)
{
	Right(Data - rhs.Data);
	Data -= rhs.Data;
	return *this;
}
TInteger& TInteger::operator-=(long long int data)
{
	Right(Data - data);
	Data -= data;
	return *this;
}
TInteger& TInteger::operator*=(const TInteger & rhs)
{
	Right(Data * rhs.Data);
	Data *= rhs.Data;
	return *this;
}
TInteger& TInteger::operator*=(long long int data)
{
	Right(Data * data);
	Data *= data;
	return *this;
}
TInteger& TInteger::operator/=(const TInteger & rhs)
{
	Right(Data / rhs.Data);
	Data /= rhs.Data;
	return *this;
}
TInteger& TInteger::operator/=(long long int data)
{
	Right(Data / data);
	Data /= data;
	return *this;
}
TInteger& TInteger::operator%=(const TInteger & rhs)
{
	Right(Data % rhs.Data);
	Data %= rhs.Data;
	return *this;
}
TInteger& TInteger::operator%=(long long int data)
{
	Right(Data % data);
	Data %= data;
	return *this;
}
bool TInteger::operator>(const TInteger & rhs)
{
	return Data > rhs.Data;
}
bool TInteger::operator>(long long int data)
{
	return Data > data;
}

std::ostream & operator<<(std::ostream & out, const TInteger & rhs)
{
	out << rhs.Data;
	return out;
}

TInteger operator +(TInteger & a, TInteger & b)
{
	Right(a.Get() + b.Get());
	return (a.Get() + b.Get());
}
TInteger operator+(TInteger & a, const long long int data)
{
	Right(a.Get() + data);
	return a.Get() + data;
}
TInteger operator+(const long long int data, TInteger & a)
{
	Right(data + a.Get());
	return data + a.Get();
}
TInteger operator -(TInteger & a, TInteger & b)
{
	Right(a.Get() - b.Get());
	return (a.Get() - b.Get());
}
TInteger operator-(TInteger & a, const long long int data)
{
	Right(a.Get() - data);
	return a.Get() - data;
}
TInteger operator-(const long long int data, TInteger & a)
{
	Right(data - a.Get());
	return data - a.Get();
}
TInteger operator *(TInteger & a, TInteger & b)
{
	Right(a.Get() * b.Get());
	return (a.Get() * b.Get());
}
TInteger operator*(TInteger & a, const long long int data)
{
	Right(a.Get() * data);
	return a.Get() * data;
}
TInteger operator*(const long long int data, TInteger & a)
{
	Right(data * a.Get());
	return data * a.Get();
}
TInteger operator /(TInteger & a, TInteger & b)
{
	Right(a.Get() / b.Get());
	return (a.Get() / b.Get());
}
TInteger operator/(TInteger & a, const long long int data)
{
	Right(a.Get() / data);
	return a.Get() / data;
}
TInteger operator/(const long long int data, TInteger & a)
{
	Right(data / a.Get());
	return data / a.Get();
}
TInteger operator %(TInteger & a, TInteger & b)
{
	Right(a.Get() % b.Get());
	return (a.Get() % b.Get());
}
TInteger operator%(TInteger & a, const long long int data)
{
	Right(a.Get() % data);
	return a.Get() % data;
}
TInteger operator%(const long long int data, TInteger & a)
{
	Right(data % a.Get());
	return data % a.Get();
}
bool operator !=(TInteger & a, TInteger & b)
{
	return !(a.Get() == b.Get());
}
bool operator!=(TInteger & a, const long long int data)
{
	return !(a.Get() == data);
}
bool operator!=(const long long int data, TInteger & a)
{
	return data != a.Get();
}
bool operator <(TInteger & a, TInteger & b)
{
	return a.Get() < b.Get();
}
bool operator<(TInteger & a, const long long int data)
{
	return a.Get() < data;
}
bool operator<(const long long int data, TInteger & a)
{
	return data < a.Get();
}
