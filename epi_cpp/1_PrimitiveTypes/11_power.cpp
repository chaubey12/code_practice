#include <iostream>

using namespace std;

double Power(double x, int y){
    double result = 1.0;
    int power = y;
    if(power < 0){
        power = -power, x = 1.0/x;
    }
    while(power){
        if(power&1){
            result *= x;
        }
        x *= x, power >>= 1;
    }
    return result;
}

int main(){
    double x = 2;
    int y = 10;
    cout << Power(x, y) << endl;
    return 0;
}