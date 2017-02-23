#include <iostream>
#include "Employee.h"

TEmploy::TEmploy()
{
    fio ="";
    salary = 0;
    extra = 0;
    year = 0;
}

TEmploy::TEmploy(std::string name, int money, int proccent, int work)
{
    fio = name;
    salary = money;
    extra = proccent;
    year = work;
}

void TEmploy::print()
{
    std::cout << "The FIO is " << fio << '\n';
    std::cout << "The salary = " << salary << '\n';
    std::cout << "The extra = " << extra << '%' << '\n';
    std::cout << fio << " works " << year << " years" << '\n';
}

double TEmploy::count()
{
    double result = 0;
    int k = 5;
    result = salary * ( 1 + 0.01 * extra + k * 0.01 * year);
    return result;
}

TEmployer::TEmployer()
        : TEmploy()
{
    factory = "";
    up_extra = 0;
}

TEmployer::TEmployer(std::string name, int money, int proccent, int work, std::string plant, int up)
        : TEmploy(name, money, proccent, work)
{
    factory = plant;
    up_extra = up;
}

void TEmployer::print()
{
    TEmploy::print();
    std::cout << "The name of segment is " << factory << '\n';
    std::cout << "His up_extra is " << up_extra << '%' << '\n';
}

double TEmployer::count()
{
    double result = TEmploy::count();
    result = result * (1 + 0.01 * up_extra);
    return result;
}
