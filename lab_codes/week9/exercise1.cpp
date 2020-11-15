#include <iostream>
#include "exercise1.h"
using namespace std;

int main()
{
    CandyBar CandyBar1;

    CandyBar1.setCandyBar();
    CandyBar1.showCandyBar();

    return 0;
}

CandyBar::CandyBar(){
    name[40];
    weight = 0.0;
    calories = 0;
}

CandyBar::CandyBar(char name,double weight,int calories){
    *this->name = name;
    this->weight = weight;
    this->calories = calories;
}

void CandyBar::setCandyBar()
{
    std::cout << "Enter the name of this candy bar: ";
    std::cin.get(name,40);
    std::cin.get();
    std::cout << "Enter weight of the candy bar: ";
    std::cin >> weight;
    std::cout << "Enter calories(an integer value) in the candy bar: ";
    std::cin >> calories;
}

void CandyBar::showCandyBar()
{
    std::cout << "Brand: " << name << endl;
    std::cout << "Weight: " << weight << endl;
    std::cout << "Calories: " << calories << endl;
}