#include <iostream>

using namespace std;

short Parity(unsigned int x){
    int result = 0;
    while(x){
        result ^= 1;
        x &= (x-1);
    }
    return result;
}

int main(){
    unsigned int x = 0x7;
    cout << Parity(x) << endl;
    return 0;
}