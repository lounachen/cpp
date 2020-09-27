#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	float q,m,f;
	cout << "Enter the quiz, mid-term and final scores:";
	cin>>q>>m>>f;
	float means = (q+m+f)/3;
	char *grade;
	if (means >= 90.0){
		grade = "A";
	}
	else if (means >= 70.0){
		grade = "B";
	}
	else if (means >= 50.0){
		grade = "C";
	}
	else {
		grade = "F";
	}
	
	cout << setprecision(6)<<"average score = " << means << " grade = " << grade << endl;
	
	return 0;
}
