#include <iostream>

using namespace std;

long long GCD(long long x, long long y){
    if(x == 0){
        return y;
    }
    if(y == 0){
        return x;
    }
    if(!(x&1) && !(y&1)){
        return GCD(x >>1, y>>1)<<1;
    }else if(!(x&1) && (y&1)){
        return GCD(x>>1, y);
    }else if((x&1) && !(y&1)){
        return GCD(x, y>>1);
    }else if(x > y){
        return GCD(x-y, y);
    }
    return GCD(x, y-x);

}

int main(){
    cout << GCD(32, 64) << endl;
    return 0;
}