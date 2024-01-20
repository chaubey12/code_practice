#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int SearchSmallest(const vector<int>& A){
    int left=0, right=A.size()-1;
    while(left < right){
        int mid = left + (right-left)/2;
        if(A[mid] > A[right]){
            left = mid+1;
        }else{
            right = mid;
        }
    }
    return A[left];
}

int main(){
    vector<int> A{378, 478, 550, 631, 103, 203, 220, 234, 279, 368};
    cout << SearchSmallest(A)<<endl;
    return 0;
}