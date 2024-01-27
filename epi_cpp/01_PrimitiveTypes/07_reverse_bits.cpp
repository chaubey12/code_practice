#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> PRECOMPUTED_REVERSE(0xFFFF, -1);

void populate_cache(){
    for(int i=0; i <= 0xFFFF; ++i){
        int temp = i;
        int left = 1, right = 16;
        while(left < right){
            if(((temp>>left)&1) != ((temp>>right)&1)){
                short bitmask = (1<<left) | (1<<right);
                temp ^= bitmask;
            }
            ++left, --right;
        }
        PRECOMPUTED_REVERSE[i] = temp;
    }
}

long ReverseBits(long x){
    cout << "sizeof :" << 8*sizeof(x)<<endl;
    const int kWordSize = 16;
    int kBitMask = 0xFFFF;
    return PRECOMPUTED_REVERSE[(x >> 3*kWordSize)] |
    PRECOMPUTED_REVERSE[(x >> 2*kWordSize)& kBitMask]<<kWordSize |
    PRECOMPUTED_REVERSE[(x >> kWordSize) & kBitMask]<<(2*kWordSize)|
    PRECOMPUTED_REVERSE[(x & kBitMask)]<<(3*kWordSize);
}

int main(){
    long x = 1;
    cout << ReverseBits(x) << endl;
    return 0;
}