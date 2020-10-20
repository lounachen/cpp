#include <iostream>
#include <string.h>

using namespace std;

struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void beforeSetting(struct box smth);
void afterSetting(struct box* smth1);
int main(){
    struct box v1;
    strcpy_s(v1.maker, "Luna Chen");
    v1.height = 6.5;
    v1.width = 3.0;
    v1.length = 20;
    
    beforeSetting(v1);
    cout << "\n";
    v1.volume = v1.height*v1.width*v1.length;

    afterSetting(&v1);

    return 0;
}

void beforeSetting(struct box smth){
    cout << "Before setting volume:" << endl;
    cout << "Maker: " << smth.maker << endl;
    cout << "Height: " << smth.height << endl;
    cout << "Width: " << smth.width << endl;
    cout << "Length: " << smth.length << endl;
    cout << "Volume: " << smth.volume << endl;
}

void afterSetting(struct box *smth1){
    cout << "After setting volume:" << endl;
    cout << "Maker: " << smth1 -> maker << endl;
    cout << "Height: " << smth1 -> height << endl;
    cout << "Width: " << smth1 -> width << endl;
    cout << "Length: " << smth1 -> length << endl;
    cout << "Volume: " << smth1 -> volume << endl;
}