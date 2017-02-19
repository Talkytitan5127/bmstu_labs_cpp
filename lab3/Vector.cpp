#include "Vector.h"
#include <iostream>
#include <cstring>

using namespace std;

TVector::~TVector()
{
	delete[] mas;
}

TVector::TVector()
{
	n = 0;
	mas = new double[n];
}

TVector::TVector(double * vec, int m)
{
	n = m;
	mas = new double[n];
	memcpy(mas, vec, n * sizeof(double));
}

void TVector::print()
{
	if (n == 0)
		cout << "Array is empty" << endl;

	else
	{
		cout << "len = " << n << endl;
		cout << "Array is ";
		for (int i = 0; i < n; i++)
			cout << mas[i] << " ";
		cout << endl;
	}
}

TVector & TVector::operator=(const TVector& rhs)
{
	delete[] mas;
	n = rhs.n;
	mas = new double[n];
	memcpy(mas, rhs.mas, n * sizeof(double));
	return *this;
}

double TVector::operator[](size_t index)const
{
	return mas[index];
}

double & TVector::operator[](size_t index)
{
	return mas[index];
}

int TVector::getN()
{
	return n;
}

double* operator+(TVector& rhs, TVector& vec)
{
	int len = rhs.getN() + vec.getN();
	double* mas = new double[len];
	int i = 0, j = 0;
	for (int k = 0; k < len; k++)
	{
		if (k < rhs.getN())
		{
			mas[k] = rhs[i];
			i++;
		}
		else
		{
			mas[k] = vec[j];
			j++;
		}
	}
	return mas;
}