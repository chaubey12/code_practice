#include <iostream>

using namespace std;

unsigned Add(unsigned a, unsigned b){
    unsigned sum=0, carryin=0, k=1, temp_a=a, temp_b=b;
    while (temp_a||temp_b){
        unsigned ak = a&k, bk = b&k;
        unsigned carryout = (ak&carryin)|(bk&carryin)|(ak&bk);
        sum |= (ak^bk^carryin);
        carryin = carryout<<1;
        k <<= 1, temp_a >>= 1, temp_b >>= 1;
    }
    return sum|carryin;
}

unsigned Multiply(unsigned x, unsigned y){
    unsigned sum=0;
    while (x){
        if(x&1){
            sum = Add(sum, y);
        }
        x >>= 1, y <<= 1;
    }
    return sum;
    
}

int main(){
    unsigned x = 10, y = 20;
    cout << Multiply(x, y) <<endl;
    return 0;
}