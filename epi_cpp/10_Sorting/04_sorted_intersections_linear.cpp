#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> IntersectTwoSortedArrays(const vector<int>& A, const vector<int>& B){
    vector<int> intersect_a_b;
    int i=0, j=0;
    while(i < A.size() && j < B.size()){
        if((A[i] == B[j]) && (i == 0 || A[i] != A[i-1])){
            intersect_a_b.emplace_back(A[i]);
            ++i, ++j;
        }else if(A[i] < B[j]){
            ++i;
        }else{
            --j;
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