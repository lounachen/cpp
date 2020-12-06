#ifndef _MYCOMPLEX_H
#define _MYCOMPLEX_H
#include <iostream>
class Complex {
public:
    double real;
    double imag;

public:
    Complex();
    Complex(double re,double im);

    void Comp() const;
    void operator+(const Complex& other) const;
    void operator==(const Complex& other) const;
    void operator!=(const Complex& other) const;
    void operator-(const Complex& other) const;
    void operator*(const Complex& other) const;
    Complex operator*(int real) const;
    void Show() const;

    friend std::ostream& operator << (std::ostream& os, const Complex& other);
    friend std::istream& operator<<(std::istream  &is, double smth); 
};

#endif