#include <iostream>
using namespace std;

int main(){
	int a,a1;
	cout << "Enter an integer number:";
	cin >> a;
	cout << "The cumulative sum of the entries to date is :" << a << endl;
	do{
		cout << "Enter an integer number:";
		cin >> a1;
		a += a1;
		cout << "The cumulative sum of the entries to date is :" << a << endl;
	}while(a1 != 0);
	return 0;
} 
