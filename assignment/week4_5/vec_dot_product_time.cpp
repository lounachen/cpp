#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <time.h>
#include <chrono>

using namespace std;
float dot_product(float v1[200000000], float v2[200000000]);
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

auto start = chrono::steady_clock::now();
cout << "The dot product is: " << dot_product(vec1,vec2) << endl;
auto end = chrono::steady_clock::now();

cout << "Calculation took: " << chrono::duration_cast< chrono::milliseconds>(end - start).count() << "ms.";

delete [] vec1;
delete [] vec2;
return 0;
}

float dot_product(float v1[200000000], float v2[200000000])
{
    float product =0;
    for (int k=0;k<200000000;k++)
    {
        product += v1[k]*v2[k];
    }
    return product;
}