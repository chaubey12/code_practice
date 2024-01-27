#include <iostream>
#include <cmath>

using namespace std;

long Reverse(int x){
    bool is_negative = x<0;
    long result = 0, x_remaining = abs(x);
    while(x_remaining){
        result = (result*10) + (x_remaining%10);
        x_remaining /= 10;
    }
    return is_negative ? -result : result;
}


int main(){
    int x = -1234;
    cout << Reverse(x) << endl;
    return 0;
}