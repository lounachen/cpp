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
	CandyBar *dynArray;
	dynArray = new CandyBar[3];
	
	cout << "Please input three CandyBar's information: " << endl;
	for (int i=0;i<3;i++)
	{
		cout << "Enter the brand name of candy bar: ";
		cin.get(dynArray[i].name,30);
		cout << "Enter the weight: ";
		cin >> dynArray[i].weight;
		cout << "Enter the calories: ";
		cin >> dynArray[i].calories; 
		cin.get();
	}
	
	cout << "\nDisplaying the CandyBar array contents" << endl;
	for (int j=0;j<3;j++)
	{
		cout << "Brand name: " << dynArray[j].name << endl;
		cout << "Weight: " << dynArray[j].weight << endl;
		cout << "Calories: " << dynArray[j].calories << endl;
	}
	
	delete [] dynArray;
	
	return 0;
}
