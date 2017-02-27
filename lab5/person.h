#ifndef LABA_5_PERSON_H
#define LABA_5_PERSON_H

#include <iostream>

class Tperson
{
protected:
    std::string name;
    int age;
public:
    Tperson();
    Tperson(const std::string &, int);
    void changeName(const std::string &);
    void changeAge(int);
    virtual void print();
};

class Temploy : public Tperson
{
protected:
    std::string post;
    double okl;
public:
    Temploy();
    Temploy(const std::string &, int, const std::string &, double);
    void changePost(const std::string &);
    void changeOkl(double);
    double salary(int);
    void print() override;
};



#endif //LABA_5_PERSON_H
