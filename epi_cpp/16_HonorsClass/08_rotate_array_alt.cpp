#include <iostream>
#include <vector>

using namespace std;

void RotateArray(int i, vector<int>* A){
    i %= A->size();
    reverse(A->begin(), A->end());
    reverse(A->begin(), A->begin() + i);
    reverse(A->begin() + i, A->end());
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