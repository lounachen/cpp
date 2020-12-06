#ifndef _NUMBER_H
#define _NUMBER_H
#include <iostream>
class Number {
private:
    int num;

public:
    Number();
    Number(int num);
    Number& operator++();
    Number operator++(int);
    Number& operator--();
    Number operator--(int);


    friend std::ostream& operator << (std::ostream& os, const Number& other);
};

#endif