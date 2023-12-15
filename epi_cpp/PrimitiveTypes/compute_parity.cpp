#include <iostream>

using namespace std;

short Parity(unsigned int x){
    short result = 0;
    while(x){
        result ^= (x&1);
        x >>= 1;
    }
    return result;
}

int main(){
    unsigned int x = 3;
    cout << Parity(x)<< endl;
    return 0;
}