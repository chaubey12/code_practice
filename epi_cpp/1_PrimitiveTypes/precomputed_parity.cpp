#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> PRECOMPUTED_PARITY(0xFFFF, -1);

void populate_cache(){
    for(int i = 0; i <= 0xFFFF; ++i){
        short parity = 0, temp = i;
        while(temp){
            parity ^= 1;
            temp &= (temp-1);
        }
        PRECOMPUTED_PARITY[i] = parity;
    }
}

short Parity(unsigned long x){
    int kBitMask = 0xFFFF;
    int kWordSize = 16;
    return PRECOMPUTED_PARITY[(x >> 3*kWordSize)]^
    PRECOMPUTED_PARITY[(x >> 2*kWordSize)&kBitMask]^
    PRECOMPUTED_PARITY[(x >> kWordSize)&kBitMask]^
    PRECOMPUTED_PARITY[x&kBitMask];
}

int main(){
    populate_cache();
    auto x = pow(2, 32);
    cout << Parity(x) << endl;
    return 0;
}