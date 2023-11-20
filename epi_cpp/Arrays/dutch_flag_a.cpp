#include <iostream>
#include <vector>

using namespace std;

typedef enum {R,G,B} Color;

void DutchFlagPartition(int pivot_index, vector<Color>* A_ptr){
    vector<Color>& A = *A_ptr;
    int smaller = 0;
    Color pivot = A[pivot_index];
    for(int i=0; i < A.size(); ++i){
        if(A[i] < pivot){
            swap(A[smaller++], A[i]);
        }
    }
    int larger = A.size() - 1;
    for(int i = A.size() - 1; i >= 0 && A[i] >= pivot; --i){
        if(A[i] > pivot){
            swap(A[larger--], A[i]);
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