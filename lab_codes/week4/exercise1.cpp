#include <iostream>
using namespace std;

struct CandyBar
{
	char name[30];
	double weight;
	int calories;
};

int main()
{
	CandyBar c1;
	cout << "Enter brand name of a Candy bar: ";
	cin.getline(c1.name, 30);
	cout << "Enter weight of the Candy bar: ";
	cin >> c1.weight;
	cout << "Enter calories (an integer value) in the Candy bar: ";
	cin >> c1.calories;
	
	cout << "Brand: " << c1.name << endl;
	cout << "Weight: " << c1.weight << endl;
	cout << "Calories: " << c1.calories << endl;
	
	return 0;
	
}
