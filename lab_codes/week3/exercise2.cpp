#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

int main(){
	cout << "Enter words(to stop, type the word done):" << endl;
	string a;
	int b = 0;
	while(a != "done"){
		cin >> a;
		b++;
	}
	b -= 1;
	cout << "You entered a total of " << b << " words." << endl;
	return 0;	
}
