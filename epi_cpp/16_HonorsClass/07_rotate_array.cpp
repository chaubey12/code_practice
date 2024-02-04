#include <iostream>
#include <vector>

using namespace std;

long long GCD(long long x, long long y){
    if(x == 0){
        return y;
    }
    if(y == 0){
        return x;
    }
    if(!(x&1) && !(y&1)){
        return GCD(x >>1, y>>1)<<1;
    }else if(!(x&1) && (y&1)){
        return GCD(x>>1, y);
    }else if((x&1) && !(y&1)){
        return GCD(x, y>>1);
    }else if(x > y){
        return GCD(x-y, y);
    }
    return GCD(x, y-x);
}

void ApplyCyclicPermutation(int rotate_amount, int offset, int cycle_length, vector<int>* A_ptr){
    vector<int>& A = *A_ptr;
    int temp = A[offset];
    for(int i=1; i < cycle_length; ++i){
        swap(A[(offset + i*rotate_amount)%A.size()], temp);
    }
    A[offset] = temp;
}

void RotateArray(int rotate_amount, vector<int>* A_ptr){
    rotate_amount %= A_ptr->size();
    int num_cycles = GCD(A_ptr->size(), rotate_amount);
    int cycle_length = A_ptr->size() / num_cycles;
    for(int c = 0; c < num_cycles; ++c){
        ApplyCyclicPermutation(rotate_amount, c, cycle_length, A_ptr);
    }
}

int main(){
    vector<int> A{4,5,1,2,3,4};
    int rotate_amount = 2;
    for(auto e : A){
        cout << e << " ";
    }
    cout << endl;
    RotateArray(rotate_amount, &A);
    for(auto e : A){
        cout << e << " ";
    }
    cout << endl;
    return 0;
}