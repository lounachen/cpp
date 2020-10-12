#include <iostream>


struct pizza
{
	char name[30];
	int diameter;
	double weight;
};

int main()
{
	using namespace std;
	pizza *ps = new pizza;
	
	cout << "Enter the name of pizza company: ";
	cin.get(ps->name,30);
	cout << "Enter the diameter of pizza (inches): ";
	cin >> ps->diameter;
	cout << "Enter the weight of the pizza (g): ";
	cin >> ps->weight;
	
	cout << "Displaying the information of the pizza" << endl;
	cout << "Company name: " << ps->name << endl;
	cout << "Pizza diameter: " << ps->diameter << " inches" << endl;
	cout << "Pizza weight: " << ps->weight << " g" << endl;
	
	delete ps;
	
	return 0;
	
} 
