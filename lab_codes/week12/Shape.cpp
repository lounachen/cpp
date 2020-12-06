#include <iostream>
#include "Shape.h"
using namespace std;

int CStereoShape::numberOfObject = 0;
int main(){
    CCube a_cube(4.0,5.0,6.0);
    CSphere c_sphere(7.9);
    CStereoShape * p = &a_cube;
    p->Show();

    p = &c_sphere;
    p->Show();
    cout << "Number of Stereo graphics created: " << CStereoShape::GetNumOfObject();
    
    return 0;
}

Formatting CStereoShape::SetFormat() const
{
    Formatting f;
    f.flag = cout.setf(ios_base::fixed, ios_base::floatfield);
    f.pr = cout.precision(3);
    return f;
}

void CStereoShape::Restore(Formatting& f) const{
    cout.setf(f.flag, ios_base::floatfield);
    cout.precision(3);
}
CCube::CCube(double length, double width, double height)
{
    this->length = length;
    this->width = width;
    this->height = height;
}
CCube::CCube(CCube& cub)
{
    length = cub.length;
    width = cub.width;
    height = cub.height;
}

double CCube::GetArea() const
{
    return length*width;
}

double CCube::GetVolume() const
{
    return length*width*height;
}

void CCube::Show()
{
    Formatting flag = SetFormat();
    cout << "length: " << length
        << "\twidth: " << width
        << "\theight: " << height
        << "\tthe area: " << GetArea()
        << "\tthe volume: " << GetVolume() << endl;

    Restore(flag);
}

CSphere::CSphere(double radius)
{
    this->radius = radius;
}

CSphere::CSphere(CSphere& sph)
{
    radius = sph.radius;
}

double CSphere::GetArea() const
{
    return 4*3.1415*radius*radius;
}

double CSphere::GetVolume() const
{
    return (4/3)*3.1415*radius*radius*radius;
}

void CSphere::Show()
{
    Formatting flag = SetFormat();
    cout << "radius: " << radius
        << "\tthe area: " << GetArea()
        << "\tthe volume: " << GetVolume() << endl;

    Restore(flag);
}