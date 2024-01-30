#include <iostream>
#include <vector>

using namespace std;

int FirstMissingPositive(vector<int> A){
    size_t i = 0;
    while(i < A.size()){
        if((A[i] > 0) && (A[i] <= A.size()) && (A[i] != A[A[i] - 1])){
            swap(A[i], A[A[i] - 1]);
        }else{
            ++i;
        }
    }
    for(i=0; i < A.size(); ++i){
        if(A[i] != (i+1)){
            return i+1;
        }
    }
    return A.size() + 1;
}

int main(){
    vector<int> A = {3, 5, 4, -1, 5, 1, -1};
    cout << FirstMissingPositive(A) << endl;
    return 0;
}