#include <iostream>

using namespace std;

short CountBits(unsigned int x){
    short numBits = 0;
    while(x){
        numBits += (x&1);
        x >>= 1;
    }
    return numBits;
}

int main(){
    unsigned int x = 255;
    cout << CountBits(x) << endl;
    return 0;
}