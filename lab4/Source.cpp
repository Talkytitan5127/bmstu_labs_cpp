#include <iostream>
#include "Employee.h"

using namespace std;

int main()
{
    TEmploy men1("Gorbunov Pavel", 15000, 5, 3);
    men1.print();
    cout << " the result = " << men1.count() << '\n';
    
    cout << "----------------" << '\n';
    
    TEmployer glav1("Petrov Petr", 32000, 10, 15, "Toyota", 15);
    glav1.print();
    cout << "The result = " << glav1.count() << '\n';

    return 0;
}
