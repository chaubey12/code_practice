#include <iostream>
#include <vector>

using namespace std;

vector<short> PRECOMPUTED_PARITY(0xFFFF, 0);

short ParitySimple(unsigned int x){
    int result = 0;
    while(x){
        result ^= 1;
        x &= (x-1);
    }
    return result;
}


void populate_cache(){
    for(int i=0; i <= 0xFFFF; ++i){
        PRECOMPUTED_PARITY[i] = ParitySimple(i);
    }
}



short Parity(unsigned long x){
    int kWordSize = 16;
    const int kBitMask = 0xFFFF;
    return PRECOMPUTED_PARITY[x >> (3*kWordSize)] ^
    PRECOMPUTED_PARITY[(x >> (2*kWordSize))&kBitMask]^
    PRECOMPUTED_PARITY[(x >> kWordSize)&kBitMask]^
    PRECOMPUTED_PARITY[x & kBitMask];
}


int main(){
    populate_cache();
    unsigned long long x = (1<<6) + 124;
    cout << Parity(x) << endl;
    cout << Parity(x&(x-1))<<endl;
    return 0;
}
