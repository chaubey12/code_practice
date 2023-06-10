#include <iostream>

using namespace std;

long long GCD(long long x, long long y){
    if(x == y){
        return x;
    }else if(!(x&1) && !(y&1)){
        return GCD(x >> 1, y >> 1) << 1;
    }else if(!(x&1) && (y&1)){
        return GCD(x >> 1, y);
    }else if((x&1) && !(y&1)){
        return GCD(x, y >> 1);
    }else if(x > y){
        return GCD(x-y, y);
    }
    return GCD(x, y-x);
}

int main(){
    long long x = 1024, y = 812;
    cout << GCD(x, y) << " is the GCD of the two numbers." << endl;
    return 0;
}