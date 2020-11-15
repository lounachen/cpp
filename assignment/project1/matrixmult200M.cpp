#include <iostream>
#include <time.h>
#include <chrono>

using namespace std;
float** create_matrix(int rows, int cols);
void destroy_matrix(float** &mat, int r);

int main(){
    
    
    float ** matA = create_matrix(20,10000000);
    float ** matB = create_matrix(10000000,20);
    float ** matC = create_matrix(20,20);

    for(int i=0;i<20;i++)
    {
        for (int j=0;j<10000000;j++)
        {
            srand((unsigned)time(NULL));
            matA[i][j]=rand()*1.0/RAND_MAX*(10-1)+1;
        }
	}

    for(int i=0;i<10000000;i++)
    {
        for (int j=0;j<20;j++)
        {
            srand((unsigned)time(NULL));
            matB[i][j]=rand()*1.0/RAND_MAX*(10-1)+1;
        }
	}


    
auto start = chrono::steady_clock::now();
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<20;j++)
        {
            for(int k=0;k<10000000;k++)
            {
                matC[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }
    

auto end = chrono::steady_clock::now();


cout << "Calculation took: " << chrono::duration_cast< chrono::milliseconds>(end - start).count() << "ms.";

    destroy_matrix(matA, 20);
    destroy_matrix(matB, 10000000);
    destroy_matrix(matC, 20);

    return 0;
}

float** create_matrix(int r, int c)
{
    float** mat = new float* [r]; 
    for (int i=0;i<r;i++)
    {
        mat[i] = new float[c](); 
    }
    return mat;
}

void destroy_matrix(float** &mat, int r)
{
    if (mat)
    {
        for (int i=0;i<r;i++)
        {
            delete[] mat[i];
        delete[] mat;
        mat = nullptr;
        }
    }
}
