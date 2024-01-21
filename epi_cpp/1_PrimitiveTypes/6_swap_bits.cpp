#include <iostream>

using namespace std;

long SwapBits(unsigned long x, int i, int j){
    if(((x >> i)&1) != ((x >> j)&1)){
        unsigned long bitmask = (1<<i) | (1<<j);
        x ^= bitmask;
    }
    return x;
}

int main(){
    unsigned long x = 32;
    int i=5, j=2;
    cout << SwapBits(x, i, j) << endl;
    return 0;
}