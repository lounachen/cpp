#include <iostream>
#include <fstream> 
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
	
	char input[100];	
	cout << "Please input a string:";
	cin.getline(input, 100);
	
	
	ofstream myfile("f1.txt");
	if(myfile.is_open())
	{
		myfile << input << endl; 
	}else
	{
		cout << "Unable to open the file.";
	}
	
	string f1contents;
	
	ifstream myfile3("f1.txt");
	if(myfile3.is_open())
	{
		cout << "The contents of f1.txt : ";
		while(getline(myfile3, f1contents))
			cout << f1contents << endl;
		myfile3.close();
	}else
	{
		cout << "Unable to open the file.";
	}

	ofstream myfile2("f2.txt");
	if(myfile2.is_open())
	{
		int len=strlen(input);
   		for(int i=0;i<len;i++)
		    {
        	if(input[i]>='a'&&input[i]<='z')
			{
            	input[i]-=32;
        	}
    		}
		myfile2 << input << endl; 
		myfile2.close();
	}else
	{
		cout << "Unable to open the file.";
	}
	
	
	string f2contents;
	ifstream myfile4("f2.txt");
	if(myfile4.is_open())
	{
		cout << "The contents of f2.txt : ";
		while(getline(myfile4, f2contents))
			cout << f2contents << endl;
		myfile4.close();
	}else
	{
		cout << "Unable to open the file.";
	}
	return 0;
}






