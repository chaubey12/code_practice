#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int SearchEntryEqualToItsIndex(const vector<int>& A){
    int left=0, right=A.size()-1;
    while(left <= right){
        int mid = left + (right-left)/2;
        int difference = A[mid] - mid;
        if(difference == 0){
            return mid;
        }else if(difference > 0){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    return -1;
}

int main(){
    vector<int> A{-3, -1, 0, 3, 5, 7};
    cout << SearchEntryEqualToItsIndex(A) << endl;
    return 0;
}