#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int SearchFirstOfK(const vector<int>& A, int k){
    int left=0, right=A.size()-1, result=-1;
    while(left <= right){
        int mid = left + (right - left)/2;
        if(A[mid] > k){
            right = mid - 1;
        }else if(A[mid] == k){
            result=mid;
            right=mid-1;
        }else{
            left = mid+1;
        }
    }
    return result;
}

int main(){
    vector<int> A { 1, 2, 3, 3, 3, 4, 4, 4, 4, 4, 5};
    int k = 4;
    cout << SearchFirstOfK(A, k) << endl;
    return 0;
}