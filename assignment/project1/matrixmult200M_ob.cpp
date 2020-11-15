#include <iostream>
#include <time.h>
#include <chrono>

#include "cblas.h"

using namespace std;

void cblas_sgemm(const enum CBLAS_ORDER __Order, const enum CBLAS_TRANSPOSE __TransA, const enum CBLAS_TRANSPOSE __TransB, const int __M, const int __N, const int __K, const float __alpha, const float *__A, const int __lda, const float *__B, const int __ldb, const float __beta, float *__C, const int __ldc);


int main(){
    
    float *matA = (float *)malloc(20 * 100000000 * sizeof(float));  
    float *matB = (float *)malloc(10000000 * 20 * sizeof(float));  
    float *matC = (float *)malloc(20 * 20 * sizeof(float));  

    for(int i=0;i<200000000;i++)
    {
        srand((unsigned)time(NULL));
		matA[i]= rand()*1.0/RAND_MAX*(10-1)+1;
        matB[i]= rand()*1.0/RAND_MAX*(10-1)+1;
    }

    auto start = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 20, 20,10000000,1,matA,10000000,matB,20,0,matC,20);
    auto end = chrono::steady_clock::now();

    cout << "The calculation took: " << chrono::duration_cast< chrono::milliseconds>(end - start).count() << "ms.";

    cout << "The result is: " << endl;

    for(int i=0;i<400;i++)
    {
        cout << matC[i] << " ";
        if ((i+1)%20 == 0) 
            cout << endl;
    } 


    free(matA);
    free(matB);
    free(matC);

    return 0;
}

