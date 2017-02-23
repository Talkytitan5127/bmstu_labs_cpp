#ifndef FACTORY_EMPLOYEE_H
#define FACTORY_EMPLOYEE_H

#include <iostream>
#include <string>

class TEmploy
{
protected:
    std::string fio;
    int salary;
    int extra;
    int year;
public:
    TEmploy();
    TEmploy(std::string, int, int, int);
    virtual void print();
    virtual double count();
};

class TEmployer : public TEmploy
{
protected:
    std::string factory;
    int up_extra;
public:
    TEmployer();
    TEmployer(std::string, int, int, int, std::string, int);
    void print() override;
    double count() override;
};

#endif //FACTORY_EMPLOYEE_H
