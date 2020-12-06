#include "Number.h"
#include <iostream>
using namespace std;

int main()
{
    Number n1(20);
    Number n2 = n1++;
    cout << n1 << endl;
    cout << n2 << endl;

    Number n3 = n2--;
    cout << n2 << endl;
    cout << n3 << endl;

    Number n4 = ++n3;
    cout << n3 << endl;
    cout << n4 << endl;

    Number n5 = --n4;
    cout << n4 << endl;
    cout << n5 << endl;

    return 0;
}
Number::Number():num(0)
{
}
Number::Number(int num):num(num)
{
}
Number Number::operator++(int)
{
   Number result = *this;
   ++ *this;
   return result;
}

Number Number::operator--(int)
{
    Number result = *this;
    -- *this;
    return result;
}

Number& Number::operator++()
{
    num++;
    return *this;
}

Number& Number::operator--()
{
    num--;
    return *this;
}

std::ostream& operator << (std::ostream& os, const Number& other)
{
    os << other.num;
    return os;
}