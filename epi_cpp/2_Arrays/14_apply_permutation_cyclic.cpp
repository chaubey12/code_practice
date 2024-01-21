#include <iostream>
#include <vector>

using namespace std;
void CyclicPermutation(int start, const vector<int>& perm, vector<int>* A_ptr){
    vector<int>& A = *A_ptr;
    int i = start;
    int temp = A[start];
    do{
        int next_i = perm[i];
        int next_temp = A[next_i];
        A[next_i] = temp;
        i = next_i, temp = next_temp;
    }while(i != start);
}

void ApplyPermutation(vector<int>* perm_ptr, vector<int>* A_ptr){
    vector<int>&A = *A_ptr, &perm = *perm_ptr;
    for(int i=0; i < A.size(); ++i){
        bool is_min = true;
        int j = perm[i];
        while(j != i){
            if(j < i){
                is_min = false;
                break;
            }
            j = perm[j];
        }
        if(is_min){
            CyclicPermutation(i, perm, &A);
        }
    }
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