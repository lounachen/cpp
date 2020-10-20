#include <iostream>
using namespace std;

int Fill_array(double arr[], int size);
void Show_array(double *arr, int size);
void Reverse_array(double *arr, int size);
int main()
{
    int size;
    cout << "Enter the size of an array:";
    cin >> size;
    double a[size];
    int acsize = Fill_array(a,size);
    
    Show_array(a,size);
    cout << "\n";
    Reverse_array(a,size);
    
    cout << "\n";
    cout << a[0] << " ";
    double b[size-2];
    for (int j=0;j<size-2;j++){
        b[j] = a[j+1];
    }
    Reverse_array(b,size-2);
    cout << a[size-1];

    return 0;
}

int Fill_array(double arr[], int size){
    for(int i=0;i<size;i++){
        cout << "Enter value #" << i+1 << ": ";
        cin >> arr[i];
        if(cin.fail()){
            cout << "wrong input." << endl;
            exit(1);
        }
    }
    return size;    
}

void Show_array(double *arr, int size){
    for (int i=0;i<size;i++){
        cout << arr[i] << " ";
    }
    return;
}

void Reverse_array(double *arr, int size){
    static int i;
    if (i==size){
        i=0;
        return;
    }
    cout << arr[size-1-i] << " ";
    i++;
    Reverse_array(arr,size);
}