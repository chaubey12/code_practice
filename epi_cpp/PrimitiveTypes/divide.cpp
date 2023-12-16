#include <iostream>

using namespace std;

unsigned Divide(unsigned x, unsigned y){
    unsigned result = 0;
    int power = 32;
    unsigned long long y_power = static_cast<unsigned long long>(y)<<power;
    while(x >= y){
        while(y_power > x){
            y_power >>= 1;
            --power;
        }
        result += 1<<power;
        x -= y_power;
    }
    return result;
}

int main(){
    unsigned x = 200, y = 10;
    cout << Divide(x,y)<<endl;
    return 0;
}