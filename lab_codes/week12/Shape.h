#ifndef SHAPE_SHAPE_H
#define SHAPE_SHAPE_H
#include <iostream>
using namespace std;

struct Formatting
{
    ios_base::fmtflags flag;
    streamsize pr;
};

class CStereoShape{
private:
    static int numberOfObject;

protected:
    Formatting SetFormat() const;
    void Restore(Formatting& f) const;
public:
    CStereoShape() {numberOfObject++;}
    virtual double GetArea(){cout << "CStereoShape::GetArea()"; return 0.0;}
    virtual double GetVolume(){cout << "CStereoShape::GetVolume()";return 0.0;}
    virtual void Show(){cout << "CStereoShape::Show()";}
    static int GetNumOfObject(){return numberOfObject;}
};

class CCube : public CStereoShape
{
private:
    double length;
    double width;
    double height;
public:
    CCube(double length, double width, double height);
    CCube()
    {
        length = 1;
        width = 1;
        height = 1;
    }
    CCube(CCube& cub);
    double GetArea() const;
    double GetVolume() const;
    void Show();
};

class CSphere : public CStereoShape
{
private:
    double radius;
public:
    CSphere(double radius);
    CSphere()
    {
        radius = 1;
    }
    CSphere(CSphere& sph);
    double GetArea() const;
    double GetVolume() const;
    void Show();
};
#endif