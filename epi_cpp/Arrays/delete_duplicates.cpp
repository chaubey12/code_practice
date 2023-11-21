#include <iostream>
#include <vector>

using namespace std;

int DeleteDuplicates(vector<int> *A_ptr){
    vector<int>& A = *A_ptr;
    int write_index=1;
    for(int i=1; i < A.size(); ++i){
        if(A[write_index-1] != A[i]){
            A[write_index++] = A[i];
        }
    }
    return write_index;
}

int main(){
    vector<int> A = {1, 1, 2, 2, 2, 3, 3, 5, 5, 5, 5};
    int idx = DeleteDuplicates(&A);
    for(int i=0; i < idx; i++){
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}