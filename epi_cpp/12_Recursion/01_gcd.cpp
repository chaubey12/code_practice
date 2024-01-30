#include <iostream>

using namespace std;
long long GCD(long long x, long long y){
    return y == 0 ? x : GCD(y, x%y);
}


int main(){
    cout << GCD(72, 36)<<endl;
    return 0;
}