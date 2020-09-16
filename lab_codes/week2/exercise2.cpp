#include <iostream>
using namespace std;

int main()
{
	long long a;
	cout << "Enter the number of seconds: \n";
	cin >> a;
	long long day = a / 86400;
	int daymol = a % 86400;
	int hour = daymol / 3600;
	int hourmol = daymol % 3600;
	int minute = hourmol / 60;
	int second = minute % 60;
	cout << a << " seconds = " << day << " days, " << hour << " hours, " << minute << " minutes, " << second << " seconds" << endl;
	return 0;
}
