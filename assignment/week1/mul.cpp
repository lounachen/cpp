//mul.cpp
#include "iostream"
#include "string.h"
#include "iomanip"
using namespace std;

int main(){
    cout <<"Please input two integers:"<< endl;
    long long int a,b;
    while(1) //https://www.cnblogs.com/tonglingliangyong/p/3908463.html
	{
		cin >> a >> b;
		if (!cin)
    	{
    		cout <<"Please check your input type and try again: "<< endl;
			cin.clear();
			cin.sync();
		}
		else
		{	// inspired by a friend
			cout << "How would you like the result to be presented? A: scientific B: integer"<<endl;
			char selection;
			cin.getline(selection);
			cin >> selection;
			if (strcmp(selection, "A") == 0)
			{
				double c = (double) a*b; 
				cout.precision(5);
				cout << "The product is: "<<std::scientific<< c << endl;
			}
			else if (strcmp(selection, "B") == 0)
			{
				cout << "The product is: "<< a*b << endl;
			}
			break;
		}		
	}	
	return 0;
}
