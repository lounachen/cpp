#include <iostream>
#include "candybar.h"
using namespace std;

void setCandyBar(CandyBar & cb)
{
    cout << "Enter the brand name of a Candy bar: ";
    cin.get();
    cin.getline(cb.brand,30);
    cout << "Enter the weight of the Candy bar: ";
    cin >> cb.weight;
    cout << "Enter calories (an integer value) in the Candy bar: ";
    cin >> cb.calories;
}

void showCandyBar(const CandyBar & cb)
{
    cout << "Brand: " << cb.brand << endl;
    cout << "Weight: " << cb.weight << endl;
    cout << "Calories: " << cb.calories << endl;
}

void setCandyBar(CandyBar *cb)
{
    cout << "Enter the brand name of a Candy bar: ";
    cin.get(cb -> brand,30);
    cout << "Enter the weight of the Candy bar: ";
    cin >> cb -> weight;
    cout << "Enter calories (an integer value) in the Candy bar: ";
    cin >> cb -> calories;
}
	
	
void showCandyBar(const CandyBar *cb)
{
	cout << "Brand: " << cb -> brand << endl;
	cout << "Weight: " << cb -> weight << endl;
	cout << "Calories: " << cb -> calories << endl;
}