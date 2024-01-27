#include <iostream>

using namespace std;

const int kNumUnsignedBits = 64;

unsigned long ClosestIntSameBitCount(unsigned long x){
    for(int i=0; i < kNumUnsignedBits-1; ++i){
        if(((x>>i)&1) != ((x>>(i+1))&1)){
            x ^= ((1UL<<i)|(1UL<<(i+1)));
            return x;
        }
    }
    throw invalid_argument("All bits are 0 or 1");
}

int main(){
    unsigned long x = 16;
    cout << ClosestIntSameBitCount(x) << endl;
    return 0;
}