#include <thread>
#include <iostream>
#include "TZoo.h"

using namespace std;

int main()
{
	TZoo myZoo1(10);
	TZoo myZoo2(7);

	TAnimal *leoVasya = new TLeo("Vasya", 82);
	TAnimal *leoIvan = new TLeo("Ivan", 40);
	TAnimal *girAnton = new TGiraffa("Anton", 10);
	TAnimal *girGleb = new TGiraffa("Gleb", 14);
	TAnimal *HipPetya = new THippopotamus("Petya", 23);
	TAnimal *elSonya = new TElephas("Sonya", 5);
	TAnimal *loxBob = new TLoxodonta("Boby", 6);

	if (!myZoo1.AddNewAnimal(&leoVasya))
		delete leoVasya;
	if (!myZoo1.AddNewAnimal(&leoIvan))
		delete leoIvan;
	if (!myZoo2.AddNewAnimal(&girAnton))
		delete leoIvan;
	if (!myZoo2.AddNewAnimal(&girGleb))
		delete girGleb;
	if (!myZoo2.AddNewAnimal(&HipPetya))
		delete HipPetya;
	if (!myZoo1.AddNewAnimal(&elSonya))
		delete elSonya;
	if (!myZoo1.AddNewAnimal(&loxBob))
		delete loxBob;

	int day = 0;

	while (true)
	{
		day++;
		cout << "welcome to my Zooland" << " Now is " << day << " day" << '\n';
		cout << "----ZOOOOLLAAAANNDDD----" << '\n';
		cout << '\n';
		cout << "to add animal - push 1" << '\n';
		cout << "to swap animals - push 2" << '\n';
		cout << "to print info about Zoos - push 3" << '\n';
		cout << "to continue - push 4" << '\n';

		int num;
		cin >> num;

		if (num == 1)
		{
			int number = 0;
			cout << "Choose Zoo: push 1 or 2" << '\n';
			cin >> number;

			string name;
			string rub;
			cout << "Enter the name of animal" << '\n';
			getline(cin, rub);
			getline(cin, name);

			cout << "Choose kind of animal" << '\n';
			cout << " 1 - Giraffe\n 2 - Hippopotamus\n 3 - Elephas" << '\n';
			cout << "4 - Loxodonta\n 5 - Leo\n 6 - Tigr" << '\n';
			int kind = 0;
			cin >> kind;

			int year = 0;
			cout << "Enter the count of year" << '\n';
			cin >> year;
			
			TAnimal * Animal = NewAnimal(name, kind, year);
			if (number == 1)
			{
				if (!myZoo1.AddNewAnimal(&Animal))
				{
					cout << "OOppss. The " << name << "ran away" << '\n';
				}
				else
				{
					cout << "In Zoo1 appears new animal - " << name << '\n';
				}
			}
			else if (number == 2)
			{
				if (!myZoo2.AddNewAnimal(&Animal))
				{
					delete Animal;
					cout << "OOppss. The " << name << "ran away" << '\n';
				}
				else
				{
					cout << "In Zoo2 appears new animal - " << name << '\n';
				}
			}
			else
				cout << "You entered wrong number" << '\n';
		}
		else if (num == 2)
		{
			int number = 0;
			cout << " Choose Zoo - push 1 or 2" << '\n';
			cin >> number;

			if (number == 1)
			{
				myZoo1.Print();
				cout << "Choose animal to transport to the Zoo2. Enter it's name" << '\n';
				string rub;
				getline(cin, rub);

				string name;
				getline(cin, name);

				TAnimal * animal = myZoo1.Delete(name);

				if (!myZoo2.AddNewAnimal(&animal))
				{
					delete animal;
					cout << "OOppss. The " << name << "decided to stay in Zoo1" << '\n';
				}
				else
				{
					cout << "In Zoo2 appears new animal - " << name << '\n';
				}
			}
			else if (number == 2)
			{
				myZoo2.Print();
				cout << "Choose animal to transport to the Zoo1. Enter it's name. " << '\n';
				string rub;
				getline(cin, rub);

				string name;
				getline(cin, name);

				TAnimal * animal = myZoo2.Delete(name);

				if (!myZoo1.AddNewAnimal(&animal))
				{
					delete animal;
					cout << "OOppss. The " << name << "decided to stay in Zoo2" << '\n';
				}
				else
				{
					cout << "In Zoo1 appears new animal - " << name << '\n';
				}
			}
			else
			{
				cout << "You entered wrong number" << '\n';
			}
		}
		else if (num == 3)
		{
			myZoo1.Print();
			myZoo2.Print();
			this_thread::sleep_for(chrono::seconds(5));
		}
		if (myZoo1.Empty())
		{
			cout << "The Zooland is empty" << '\n';
		}
		if (myZoo2.Empty())
		{
			cout << "The Zooland is empty" << '\n';
		}

		myZoo1.CheckBirthday(day);
		myZoo2.CheckBirthday(day);
		
		cout << '\n';
		cout << "The Zooland is coming.." << '\n';
		cout << '\n';

		myZoo1.Born();
		myZoo2.Born();

		for (int hour = 0; hour < 24; hour++)
		{
			myZoo1.Work();
			cout << '\n';
			cout << "|--------|---------|" << '\n';
			cout << "|--------|---------|" << '\n';
			cout << "|--------|---------|" << '\n';
			myZoo2.Work();
			cout << '\n';
			cout << '\n';
			this_thread::sleep_for(chrono::seconds(1));
		}
		
		myZoo1.FinishDay();
		myZoo2.FinishDay();

		cout << "To continue press " << "Y or y" << " else press " << "E or e" << '\n';
		string rub;
		getline(cin, rub);

		string exit;
		getline(cin, exit);
		if (exit == "e" || exit == "E")
			break;
		cout.clear();
	}
	system("pause");
}