#include "complex.h"
#include <iostream>
#include <ostream>

using namespace std;

int main()
{
    Complex a(3.0,4.0);
    Complex b(2.0,6.0);


    cout << "b is ";b.Show();
    cout << "~b is ";b.Comp();
    cout << "a is ";a.Show();
    cout << "a + b is ";a + b;
    cout << "a - b is ";a - b;
    cout << "a * b is ";a * b;
    cout << "2 * b is ";(b * 2).Show();
    Complex c=b;
    cout << "b==c is ";(b==c);
    cout << "b!=c is ";(b!=c);
    cout << "a==c is ";(a==c);
    cout << endl;

    Complex d;

    cout << "Enter a complex number: " << endl;
    cout << "real: "; 
    cin >> d.real;
    cout << "imaginary: "; 
    cin >> d.imag;
    cout << "d is "; d.Show();
    return 0; 
}

Complex::Complex():real(0),imag(0)
{
}
Complex::Complex(double re,double im):real(re),imag(im)
{
}
void Complex::operator+(const Complex& other) const
{
    Complex result;
    result.real = real + other.real;
    result.imag = imag + other.imag;
    std::cout << result.real << " + " << result.imag << "i" << std::endl;
}
void Complex::operator-(const Complex& other) const
{
    Complex result;
    result.real = real - other.real;
    result.imag = imag - other.imag;
    std::cout << result.real << " + " << result.imag << "i" << std::endl;
}
void Complex::operator*(const Complex& other) const
{
    Complex result;
    result.real = (real * other.real) - (imag * other.imag);
    result.imag = (real * other.imag) - (imag * other.real);
    std::cout << result.real << " + " << result.imag << "i" << std::endl;
}
Complex Complex::operator*(int real) const
{
    int result_real = (real * this->real) - imag;
    int result_imag = real - (imag * this->real);
    return Complex(result_real, result_imag);
}

void Complex::Comp() const
{
    std::cout << real << " - " << imag << "i" << std::endl;
}
void Complex::Show() const
{
    std::cout << real << " + " << imag << "i" << std::endl;
}

std::ostream& operator << (std::ostream& os, const Complex& other)
{
    os << other.real << " + " << other.imag << "i" << std::endl;
    return os;
}
std::istream& operator >>(std::istream& is, const double smth)
{
    is >> smth;
    return is;
}

void Complex::operator==(const Complex& other) const
{
    if (real == other.real)
        std::cout << "true." << std::endl; 
    if (real != other.real)
        std::cout << "false." << std::endl;
}
void Complex::operator!=(const Complex& other) const
{
    if (real == other.real)
        std::cout << "false." << std::endl; 
    if (real != other.real)
        std::cout << "true." << std::endl;
}