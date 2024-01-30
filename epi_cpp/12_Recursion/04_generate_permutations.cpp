#include <iostream>
#include <vector>

using namespace std;

void DirectedPermutation(int i, vector<int> *A_ptr, vector<vector<int>>* result){
    vector<int>& A = *A_ptr;
    if(i == A.size() - 1){
        result->emplace_back(A);
        return;
    }
    for(int j = i; j < A.size(); ++j){
        swap(A[i], A[j]);
        DirectedPermutation(i+1, A_ptr, result);
        swap(A[i], A[j]);
    }
}

vector<vector<int>> Permutations(vector<int> A){
    vector<vector<int>> result;
    DirectedPermutation(0, &A, &result);
    return result;
}

int main(){
    vector<int> A{1, 2, 3};
    auto result = Permutations(A);
    for(auto vec : result){
        for(auto item : vec){
            cout << item << " ";
        }
        cout << endl;
    }
    return 0;
}