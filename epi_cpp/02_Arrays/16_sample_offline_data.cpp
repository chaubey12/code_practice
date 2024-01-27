#include <iostream>
#include <vector>
#include <random>

using namespace std;

void RandomSampling(vector<int>* A_ptr, int k){
    vector<int>& A = *A_ptr;
    default_random_engine seed((random_device())());
    for(int i=0; i < k; ++i){
        swap(A[i], A[uniform_int_distribution<int>{i, static_cast<int>(A.size() - 1)}(seed)]);
    }
}

int main(){
    vector<int> A = {3, 5, 7, 9, 11, 13};
    int k=3;
    for(int i=0; i < 10; i++){
        RandomSampling(&A, k);
        for(int j=0; j < k; ++j){
            cout << A[j] << " ";
        }
        cout << endl;
    }
    return 0;
}