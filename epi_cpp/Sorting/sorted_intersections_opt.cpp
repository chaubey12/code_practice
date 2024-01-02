#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> IntersectTwoSortedArrays(const vector<int>& A, const vector<int>& B){
    vector<int> intersect_a_b;
    for(int i=0; i < A.size(); ++i){
        if((i == 0 || A[i] != A[i-1]) && binary_search(B.cbegin(), B.cend(), A[i])){
            intersect_a_b.emplace_back(A[i]);
        }
    }
    return intersect_a_b;
}


int main(){
    vector<int> A{1, 2, 3, 4, 5};
    vector<int> B{2, 4, 6, 8, 10};
    auto result = IntersectTwoSortedArrays(A, B);
    for(auto elem : result){
        cout << elem <<" ";
    }
    cout << endl;
    return 0;
}