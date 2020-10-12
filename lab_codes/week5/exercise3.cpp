#include <iostream>
using namespace std;

int main()
{
	cout << "Enter 5 integers: " << endl;
	int * ptArray = NULL, *t;
	ptArray = new int[5];
	for (int i=0;i<5;i++)
	{
		cin >> ptArray[i];
	}
	cout << "The elementes of the array in reverse order are: " << endl;
	for (int j=4;j>=2;j--)
	{
			swap(ptArray[j],ptArray[4-j]);
	}
	for (int k=0;k<5;k++)
	{
		cout << ptArray[k] << " ";
	}
	delete [] ptArray;
	
	return 0;
}
