#include <iostream>
#include "candybar.h"
using namespace std;
int main(){
    CandyBar *c1 = new CandyBar;
    CandyBar c2;

    cout << "Call the set function of Passing by pointer: " << endl;
    setCandyBar(c1);
    cout << "Call the show function of Passing by pointer: " << endl;
    showCandyBar(c1);
    cout << "Call the set function Passing by reference: " << endl;
    setCandyBar(c2);
    cout << "Call the show function of Passing by reference: " << endl;
    showCandyBar(c2);

    delete c1;
    return 0;
}