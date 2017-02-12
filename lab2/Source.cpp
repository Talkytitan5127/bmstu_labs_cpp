#include "deposit.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n = 0;
	cout << "Enter the number of deposits" << endl;
	cin >> n;
	TDeposit *deposit = new TDeposit[n];
	for (int i = 0; i < n; i++)
	{
		string fio;
		cout << "Enter the fio" << endl;
		getline(cin, fio);
		double sum;
		cout << "Enter the current sum" << endl;
		cin >> sum;
		int entry;
		cout << "Enter the entry" << endl;
		cin >> entry;
		deposit[i].SetDate(fio, sum, entry);
	}
	for (int i = 0; i < n; i++)
		deposit[i].print();

	int year;
	cout << "Enter the number of years" << endl;
	cin >> year;

	for (int i = 0; i < n; i++)
	{
		deposit[i].count(year);
		deposit[i].print();
	}

	double result = 0;
	for (int i = 0; i < n; i++)
		result += deposit[i].get_sum();
	printf_s("The general sum is %.3lf\n", result);
	
	system("pause");
	return 0;
}