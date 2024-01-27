#include <iostream>

using namespace std;

short Parity(unsigned long x){
    x ^= (x >> 32);
    x ^= (x >> 16);
    x ^= (x >> 8);
    x ^= (x >> 4);
    x ^= (x >> 2);
    x ^= (x >> 1);
    return x & 0x1;
}

int main(){
    unsigned int x = 31;
    cout << Parity(x) << endl;
    return 0;
}