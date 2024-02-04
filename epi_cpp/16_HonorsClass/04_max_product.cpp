#include <iostream>
#include <vector>
#include <numeric>
#include <limits>


using namespace std;

int FindBiggestMinusOneProduct(const vector<int>& A){
    vector<int> L, R(A.size());
    partial_sum(A.cbegin(), A.cend(), back_inserter(L), multiplies<int>());
    partial_sum(A.crbegin(), A.crend(), R.rbegin(), multiplies<int>());
    int max_product = numeric_limits<int>::min();
    for(int i=0; i < A.size(); ++i){
        int forward = (i > 0) ? L[i-1] : 1;
        int backward = (i+1 < A.size()) ?  R[i+1] : 1;
        max_product = max(max_product, forward*backward);
    }
    return max_product;
}

int main(){
    vector<int> A{3,2,-1,4,-1,6};
    cout << FindBiggestMinusOneProduct(A)<<endl;
    return 0;
}