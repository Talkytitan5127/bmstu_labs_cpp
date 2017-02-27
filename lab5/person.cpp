#include <iostream>
#include "person.h"

using namespace std;

Tperson::Tperson()
{
    name = "";
    age = 0;
}

Tperson::Tperson(const string & Name, int Age)
{
    name = Name;
    age = Age;
}

void Tperson::changeName(const string & Name)
{
    name = Name;
}

void Tperson::changeAge(int Age)
{
    age = Age;
}

Temploy::Temploy()
        :Tperson()
{
    post = "";
    okl = 0;
}

Temploy::Temploy(const string & Name, int Age, const string & Post, double Okl)
        :Tperson(Name, Age)
{
    post = Post;
    okl = Okl;
}

void Temploy::changePost(const string & Post)
{
    post = Post;
}

void Temploy::changeOkl(double Okl)
{
    okl = Okl;
}

double Temploy::salary(int procent)
{
    double result = 0;
    result = okl + procent * 0.01 * okl;
    return result;
}

void Tperson::print()
{
    cout << "Name is " << name << '\n';
    cout << "His age is " << age << '\n';
}

void Temploy::print()
{
    Tperson::print();
    cout << "His post is " << post << '\n';
    cout << "His oklad = " << okl << '\n';
}