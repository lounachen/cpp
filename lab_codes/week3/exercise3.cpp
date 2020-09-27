#include <iostream>
#include <string>
using namespace std;

int main(){
	int i,j;
	const char* xiaosi[7] = {"1","12","123","1234","12345","123456","1234567"};
	for (i=7;i>=1;i--)
	{	
		cout << xiaosi[7-i];
		for(j=1;j<=i;j++)
		{
			cout<<"*";
		}
		cout << "\n";
	}
	
	return 0; 
}
