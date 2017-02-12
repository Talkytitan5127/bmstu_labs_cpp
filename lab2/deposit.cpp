#include "deposit.h"
#include <iostream>
#include <string>
using namespace std;

TDeposit::TDeposit()
{
	fio = "";
	current_sum = 0;
	entry = 0;
}

void TDeposit::SetDate(string data_fio, double data_sum, int data_entry)
{
	fio = data_fio;
	current_sum = data_sum;
	entry = data_entry;
}

TDeposit::TDeposit(string data_fio, double data_sum, int data_entry)
{
	SetDate(data_fio, data_sum, data_entry);
}

string TDeposit::get_fio()
{
	return fio;
}

double TDeposit::get_sum()
{
	return current_sum;
}

float TDeposit::get_entry()
{
	return entry;
}

void TDeposit::print()
{
	cout << "FIO is " << fio << endl;
	cout << "current sum is " << current_sum << endl;
	cout << "year's entry is " << entry << endl;
}

void TDeposit::count(int year)
{
	for (int i = 0; i < year; i++)
		current_sum += current_sum * (entry * 0.01);
}
