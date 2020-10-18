#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <time.h>
#include <chrono>

#include "cblas.h"
//This program can test OpenBLAS and calculate dot product. Currently it's testing OpenBLAS.
using namespace std;

float cblas_sdot(const int __N, const float *__X, const int __incX, const float *__Y, const int __incY);
double dot_product(float v1[200000000], float v2[200000000]);
int main()
{
    float *vec1 = new float[200000000]();
    float *vec2 = new float[200000000]();

    for(int i=0;i<200000000;i++)
    {
        srand((unsigned)time(NULL));
		vec1[i]= rand()*1.0/RAND_MAX*(10-1)+1;
        vec2[i]= rand()*1.0/RAND_MAX*(10-1)+1;
	}


cout << "The dot product is: " << dot_product(vec1,vec2) << endl;

auto start = chrono::steady_clock::now();
cout << "The dot product is: "<< cblas_sdot(200000000, vec1, 1, vec2, 1) << endl;
auto end = chrono::steady_clock::now();

cout << "Calculation took: " << chrono::duration_cast< chrono::milliseconds>(end - start).count() << "ms.";

delete [] vec1;
delete [] vec2;
return 0;
}


double dot_product(float v1[200000000], float v2[200000000])
{
    double product(0);
    double product1(0);
    double product2(0);
    double product3(0);
    double product4(0);
    double product5(0);
    double product6(0);
    double product7(0);
    for (int k(0);k<199999994;k+=7)
    {
        product1 += v1[k]*v2[k];
        product2 += v1[k+1]*v2[k+1];
        product3 += v1[k+2]*v2[k+2];
        product4 += v1[k+3]*v2[k+3];
        product5 += v1[k+4]*v2[k+4];
        product6 += v1[k+5]*v2[k+5];
        product7 += v1[k+6]*v2[k+6];
    }
    product = product1 + product2 + product3 + product4 + product5 + product6 + product7;
    return product;
}