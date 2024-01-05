#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <random>

using namespace std;

template<typename Compare>
int PartitionAroundPivot(int left, int right, int pivot_idx, Compare comp, vector<int>* A_ptr){
    vector<int>& A = *A_ptr;
    int pivot_value = A[pivot_idx];
    int new_pivot_idx = left;
    swap(A[pivot_idx], A[right]);
    for(int i=left; i < right; ++i){
        if(comp(A[i], pivot_value)){
            swap(A[i], A[new_pivot_idx++]);
        }
    }
    swap(A[right], A[new_pivot_idx]);
    return new_pivot_idx;
}

template<typename Compare>
int FindKth(int k, Compare comp, vector<int>* A_ptr){
    vector<int>& A = *A_ptr;
    int left=0, right=A.size()-1;
    default_random_engine gen((random_device())());
    while(left < right){
        int pivot_idx = uniform_int_distribution<int>{left, right}(gen);
        int new_pivot_idx = PartitionAroundPivot(left, right, pivot_idx, comp, &A);
        if(new_pivot_idx == k-1){
            return A[new_pivot_idx];
        }else if(new_pivot_idx > k-1){
            right = new_pivot_idx - 1;
        }else{
            left = new_pivot_idx + 1;
        }
    }
    return -1;
}

int FindKthLargest(int k, vector<int>* A_ptr){
    return FindKth(k, greater<int>(), A_ptr);
}


int main(){
    vector<int> A{3, 2, 1, 4, 5};
    int k = 3;
    cout << FindKthLargest(4, &A)<<endl;
    return 0;
}