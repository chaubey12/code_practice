#include <iostream>
#include <vector>
#include <numeric>
#include <random>

using namespace std;

void RandomSampling(vector<int>* A_ptr, int k){
    vector<int>& A = *A_ptr;
    default_random_engine seed((random_device())());
    for(int i = 0; i < k; i++){
        swap(A[i], A[uniform_int_distribution<int>{i, static_cast<int>(A.size()-1)}(seed)]);
    }
}

vector<int> ComputeRandomPermutation(int n){
    vector<int> permutation(n);
    iota(permutation.begin(), permutation.end(), 0);
    RandomSampling(&permutation, permutation.size());
    return permutation;
}

int main(){
    int n = 5;
    vector<int> permutation;
    permutation = ComputeRandomPermutation(n);
    for(auto val : permutation){
        cout << val << " ";
    }
    cout << endl;
    return 0;
}