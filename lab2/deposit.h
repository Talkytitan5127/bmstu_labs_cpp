#pragma once
#include <iostream>
using namespace std;

class TDeposit
{
private:
	string fio;
	double current_sum;
	int entry;
public:

	TDeposit();

	TDeposit(string, double, int);

	void SetDate(string, double, int);

	string get_fio();

	double get_sum();

	float get_entry();

	void print();

	void count(int);

};