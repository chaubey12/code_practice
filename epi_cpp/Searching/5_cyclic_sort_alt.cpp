#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int SearchSmallestHelper(const vector<int>& A, int left, int right){
    if(left == right){
        return left;
    }
    int mid = left + (right - left)/2;
    if(A[mid] > A[right]){
        return SearchSmallestHelper(A, mid+1, right);
    }else if(A[mid] < A[right]){
        return SearchSmallestHelper(A, left, mid);
    }
    int left_result = SearchSmallestHelper(A, left, mid);
    int right_result = SearchSmallestHelper(A, mid+1, right);
    return A[right_result] < A[left_result] ? right_result : left_result;

}

int SearchSmallest(const vector<int>& A){
    return SearchSmallestHelper(A, 0, A.size() - 1);
}

int main(){
    vector<int> A{378, 478, 550, 631, 103, 203, 220, 234, 279, 368};
    cout << SearchSmallest(A)<<endl;
    return 0;
}