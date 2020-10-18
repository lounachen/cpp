#include <iostream>
using namespace std;

float dot_product(float v1[], float v2[], int p);

int main(){
    
    cout << "Please input the first vector (e.g. 2.3 4.5 6.7): ";
    float *vec1 = new float[100]();	
    int i;
    float a;
    
    while(1){
        cin >> a;
        if (cin.fail())
        {
            cout << "Error: input type wrong" << endl;
            exit(1);
        }
        else
        {
            vec1[i] = a;
            i++;
            if(cin.get() == '\n')
            {
                break;
            }
        }
    }
    
    cout << "Please input the second vector: ";
    float *vec2 = new float[20000000]();
    int j = 0;
    float b;
    
    while(1){
        cin >> b;
        if (cin.fail())
        {
            cout << "Error: input type wrong" << endl;
            exit(1);
        }
        else
        {
            vec2[j] = b;
            j++;

            if(cin.get() == '\n')
            {
                break;
            }
        }
    }

    if(i != j)
    {
        cout << "Error: vector size mismatch" << endl;
    }
    else
        cout << "The dot product is: " << dot_product(vec1,vec2,i);
    
    delete [] vec1;
    delete [] vec2;

    return 0;
}

float dot_product(float v1[100], float v2[100], int p){
    float product =0;
    for (int k=0;k<p;k++)
    {
        product += v1[k]*v2[k];
    }
    return product;
}
