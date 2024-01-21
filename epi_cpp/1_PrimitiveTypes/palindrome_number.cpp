#include <iostream>
#include <cmath>

using namespace std;

bool IsPalindromeNumber(int x){
    if(x < 0){
        return false;
    }else if(x < 10){
        return true;
    }
    const int num_digits = static_cast<int>(floor(log10(x))) + 1;
    int msd_mask = static_cast<int>(pow(10, num_digits-1));
    for(int i=0; i < (num_digits/2); ++i){
        if((x/msd_mask) != (x%10)){
            return false;
        }
        x %= msd_mask; x/= 10;
        msd_mask /= 100;
    }
    return true;
}

int main(){
    int x = 12321;
    if(IsPalindromeNumber(x)){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}