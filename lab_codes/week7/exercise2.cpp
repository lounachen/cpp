#include <iostream>
using namespace std;
template <typename T>
T max5(T arr[])
{
    T x = arr[0];
    for (int i=1;i<5;i++)
    {
        if (x < arr[i]){
            x = arr[i];
        }
    }
    return x;
}

int main(){
    int a[5] = {1,2,3,4,5};
    double b[5] = {1.1,2.0,3.0,4.0,5.5};
    cout << max5(a) << endl;
    cout << max5(b) << endl;

    return 0;
}

