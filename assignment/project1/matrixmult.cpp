#include <iostream>
using namespace std;

struct matrix{
    int r;
    int c;
    float mat[10][10];
}A,B,C;

int main(){
    cout << "Enter the number of rows and columns for A: \n";
    cin >> A.r >> A.c;
    cout << "Enter the number of rows and columns for B: \n";
    cin >> B.r >> B.c;

    if (A.c != B.r)
    {
        cout << "The number of rows of B must equal the number of columns of A." << endl;
        exit(1);
    }

    for (int i=0;i<A.r;i++)
    {
        cout << "Enter the #" << i+1 << " row of matrix A: " << endl;
        for (int j=0;j<A.c;j++)
        {
            cin >> A.mat[i][j];
            if (!cin)
            {
                cout << "Wrong input!" << endl;
                exit(1);
            }
        }
    }

    cout << "Matrix A is: " << endl;

    for(int i=0;i<A.r;i++)
    {
        for(int j=0;j<A.c;j++)
        {
            cout << A.mat[i][j] << "  ";
        }
        cout << endl;
    }

    for (int i=0;i<B.r;i++)
    {
        cout << "Enter the #" << i+1 << " row of matrix B: " << endl;
        for (int j=0;j<B.c;j++)
        {
            cin >> B.mat[i][j];
            if (!cin)
            {
                cout << "Wrong input!" << endl;
                exit(1);
            }
        }
    }

    cout << "Matrix B is: " << endl;

    for(int i=0;i<B.r;i++)
    {
        for(int j=0;j<B.c;j++)
        {
            cout << B.mat[i][j] << "  ";
        }
        cout << endl;
    }

    for(int i=0;i<A.r;i++)
    {
        for(int j=0;j<B.c;j++)
        {
            for(int k=0;k<A.c;k++)
            {
                C.mat[i][j] += A.mat[i][k] * B.mat[k][j];
            }
        }
    }

    cout << "The result is: " << endl;

    for(int i=0;i<A.r;i++)
    {
        for(int j=0;j<B.c;j++)
        {
            cout << C.mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

