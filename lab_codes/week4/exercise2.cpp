#include <iostream>
using namespace std;

struct CandyBar
{
	char name[30];
	double weight;
	int calories;
	double calperWeight;
};

int main()
{
	CandyBar c[3];
	double maxcpw = 0;
	int maxnum = 0;
	for (int j=0;j<3;j++)
	{
		cout << "Enter brand name of Candy bar #" << j+1 << ": ";
		cin.getline(c[j].name,30);
		cout << "Enter weight of the Candy bar #" << j+1 << ": ";
		cin >> c[j].weight;
		cout << "Enter calories (an integer value) in the Candy bar #" << j+1 << ": ";
		cin >> c[j].calories;
		cin.get(); 
		c[j].calperWeight = c[j].calories/c[j].weight;
		if (c[j].calperWeight >= maxcpw)
		{
			maxcpw = c[j].calperWeight;
			maxnum = j;
		}
	}
	
	for(int i=0;i<3;i++)
	{
		cout << "Brand #" << i+1 << endl;
		cout << "Brand: " << c[i].name << endl;
		cout << "Weight: " << c[i].weight << endl;
		cout << "Calories: " << c[i].calories << endl;
	}
	cout << "The greatest calories per weight comes from " << c[maxnum].name << ": " << maxcpw << endl;
	
	return 0;
}
