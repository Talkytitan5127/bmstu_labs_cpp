#include <iostream>
#include "person.h"

using namespace std;

int main()
{
    Tperson **mas = new Tperson *[3];
    mas[0] = new Tperson("Gorbunov", 18);
    mas[1] = new Tperson("Dolmatov", 18);
    mas[2] = new Tperson("Golubkov", 19);

    Temploy **man = new Temploy *[2];
    man[0] = new Temploy("Kustov", 20, "butcher", 15000);
    man[1] = new Temploy("Ivanov", 16, "student", 1750);

    int procent = 5;

    mas[0]->changeName("Popov");
    mas[1]->changeAge(20);

    for (int i = 0; i < 3; i++)
        mas[i]->print();

    man[0]->changePost("teacher");
    man[1]->changeOkl(20000);

    for (int i = 0; i < 2; i++)
    {
        man[i]->print();
        cout << "The salary = " << man[i]->salary(procent) << '\n';
    }

    for (int i = 0; i < 3; i++)
        delete mas[i];
    delete[] mas;

    for (int i = 0; i < 2; i++)
        delete man[i];
    delete[] man;

    return 0;
}