#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int SquareRoot(int k){
    int left=0, right=k;
    while(left <= right){
        long mid = left + (right-left)/2;
        long mid_squared = mid*mid;
        if(mid_squared <= k){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return left-1;
}

int main(){
    int k = 144;
    cout << SquareRoot(k) << endl;
    return 0;
}