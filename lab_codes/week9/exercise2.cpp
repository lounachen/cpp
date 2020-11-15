#include <iostream>
#include "exercise2.h"
using namespace std;

int main()
{
    Rectangle Rectangle1;
    
    double area,perimeter;
    area = Rectangle1.getArea();
    perimeter = Rectangle1.getPerimeter();
    cout << "Rectangle 1" << endl;
    Rectangle1.display();
    cout << "Area:   " << area << endl;
    cout << "Perimeter:   " << perimeter << endl;

    Rectangle Rectangle2(3.5,35.9);
    area = Rectangle2.getArea();
    perimeter = Rectangle2.getPerimeter();
    cout << "Rectangle 2" << endl;
    Rectangle2.display();
    cout << "Area:   " << area << endl;
    cout << "Perimeter:   " << perimeter << endl;
    return 0;
}

Rectangle::Rectangle(){
    width = 4;
    height = 40;
}

Rectangle::Rectangle(double width,double height){
    this->width = width;
    this->height = height;
}

double Rectangle::getArea(){
    return width * height;
}

double Rectangle::getPerimeter(){
    return 2 * (width + height);
}

void Rectangle::display(){
    std::cout << "-------------" << endl;
    std::cout << "Width:   " << width << endl;
    std::cout << "Height:   " << height << endl;
}
