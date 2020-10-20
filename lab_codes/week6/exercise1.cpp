#include <iostream>
using namespace std;
void Displaymenu();
int Add(int a, int b);
int Substract(int a, int b);
int Multiply(int a, int b);
int Divide(int a, int b);
int Modulus(int a, int b);

void Displaymenu()
{
    cout << "==================================================" << endl;
    cout << "                      MENU                        " << endl;
    cout << "==================================================" << endl;
    cout << "           1.Add                                  " << endl;
    cout << "           2.Subtract                             " << endl;
    cout << "           3.Multiply                             " << endl;
    cout << "           4.Divide                               " << endl;
    cout << "           5.Modulus                              " << endl;
}

int Add(int a, int b)
{
    cout << "Result:" << a+b << endl;
}

int Substract(int a, int b)
{
    cout << "Result:" << a-b << endl;
}

int Multiply(int a, int b)
{
    cout << "Result:" << a*b << endl;
}

int Divide(int a, int b)
{
    cout << "Result:" << a/b << endl;
}

int Modulus(int a, int b)
{
    cout << "Result:" << a%b << endl;
}

int main()
{
    Displaymenu();
    int YourChoice;
    int a,b;
    char confirm;
    do
    {
        cout << "Enter your choice(1~5):";
        cin >> YourChoice;
        cout << "Enter your integer numbers:";
        cin >> a >> b;
        cout << "\n";
        switch(YourChoice)
        {
            case 1:
                Add(a,b);
                break;
            case 2:
                Substract(a,b);
                break;
            case 3:
                Multiply(a,b);
                break;
            case 4:
                Divide(a,b);
                break;
            case 5:
                Modulus(a,b);
                break;
        }
        cout << "Press y or Y to continue:";
        cin >> confirm;
    } while (confirm == 'y'||confirm == 'Y');
    return 0;
}