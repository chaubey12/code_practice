#include <iostream>
#include <vector>

using namespace std;

int FindKthInTwoSortedArrays(const vector<int>& A, const vector<int>& B, int k){
    int b = max(0, static_cast<int>(k - B.size()));
    int t = max(static_cast<int>(A.size()), k);
    while(b < t){

    }
    int A_b_1 = (b <= 0)? numeric_limits<int>::min() : A[b-1];
    int B_k_b_1 = (k - b - 1 < 0) ? numeric_limits<int>::min() : B[k-b-1];
    return max(A_b_1, B_k_b_1);
}

int main(){
    vector<int> A{1,3,5,7,9};
    vector<int> B{2,4,6,8,10};
    int k = 5;
    cout << FindKthInTwoSortedArrays(A, B, k)<<endl;
    return 0;
}