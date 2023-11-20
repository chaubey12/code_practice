#include <iostream>
#include <vector>

using namespace std;

typedef enum {R,G,B} Color;

void DutchFlagPartition(int pivot_index, vector<Color>* A_ptr){
    vector<Color>& A = *A_ptr;
    int greater = A.size() - 1;
    int smaller = 0, equal = 0;
    Color pivot = A[pivot_index];
    while(equal < greater){
        if(A[equal] < pivot){
            swap(A[smaller++], A[equal++]);
        }else if(A[equal] == pivot){
            ++equal;
        }else{
            swap(A[equal], A[greater--]);
        }
    }
}

int main(){
    vector<Color> A = {R,R,G,G,G,B,B,B,G,G,R,R,G};
    int pivot_index = 2;
    DutchFlagPartition(pivot_index, &A);
    for(auto i : A){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}