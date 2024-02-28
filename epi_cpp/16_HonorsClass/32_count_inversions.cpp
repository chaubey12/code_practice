#include <iostream>
#include <vector>

using namespace std;

int MergeSortAndCountInversionsAcrossSubarray(int start, int mid, int end, vector<int>* A_ptr){
    vector<int> sorted_A;
    int left_start=start, right_start=mid, inversion_count=0;
    vector<int>& A = *A_ptr;
    while(left_start < mid && right_start < end){
        if(A[left_start] <= A[right_start]){
            sorted_A.emplace_back(A[left_start++]);
        }else{
            inversion_count += mid - left_start;
            sorted_A.emplace_back(A[right_start++]);
        }
    }
    copy(A.begin() + left_start, A.begin() + mid, back_inserter(sorted_A));
    copy(A.begin() + right_start, A.begin() + end, back_inserter(sorted_A));
    copy(sorted_A.begin(), sorted_A.end(), A.begin() + start);
    return inversion_count;
}

int CountSubarrayInversions(int start, int end, vector<int>* A_ptr){
    if(end - start <= 1){
        return 0;
    }
    int  mid = start + ((end - start)/2);
    return CountSubarrayInversions(start, mid, A_ptr) +
           CountSubarrayInversions(mid, end, A_ptr) +
           MergeSortAndCountInversionsAcrossSubarray(start, mid, end, A_ptr);
}

int CountInversions(vector<int>& A){
    return CountSubarrayInversions(0, A.size(), &A);
}

int main(){
    vector<int> A{3, 6, 4, 2, 5, 1};
    cout << "Total inversions = "<<CountInversions(A)<<endl;
    return 0;
}