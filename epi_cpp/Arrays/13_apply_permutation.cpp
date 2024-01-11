#include <iostream>
#include <vector>

using namespace std;

void ApplyPermutation(vector<int>* perm_ptr, vector<int>* A_ptr){
    vector<int>& perm = *perm_ptr, &A = *A_ptr;
    for(int i=0; i < A.size(); ++i){
        int next = i;
        while(perm[next] >= 0){
            swap(A[i], A[perm[next]]);
            int temp = perm[next];
            perm[next] -= perm.size();
            next = temp;
        }
    }
    for_each(perm.begin(), perm.end(), [&](int& x){ x += perm.size(); });
}

int main(){
    vector<int> perm {3,2,1,0};
    vector<int> A{1,2,3,4};
    for(auto elem: A){
        cout << elem <<" ";
    }
    cout << endl;
    cout << "Apply permutation"<<endl;
    ApplyPermutation(&perm, &A);
    for(auto elem: A){
        cout << elem <<" ";
    }
    cout << endl;
    return 0;
}