#include <iostream>
#include <vector>

using namespace std;

typedef enum {R, G, B} Color;

void DutchFlagPartition(int pivot_index, vector<Color> *A_ptr){
    vector<Color>& A = *A_ptr;
    Color pivot = A[pivot_index];
    for(int i=0; i < A.size(); ++i){
        for(int j=i+1; j < A.size(); ++j){
            if(A[j] < pivot){
                swap(A[i], A[j]);
                break;
            }
        }
    }
    for(int i = A.size() - 1; i >= 0 && A[i] >= pivot; --i){
        for(int j = i-1; j >= 0 && A[j] >= pivot; --j){
            if(A[j] > pivot){
                swap(A[i], A[j]);
                break;
            }
        }
    }
}

int main(){
    vector<Color> A = {R,G,G,R,G,B,B,G,R};
    int pivot_index = 4;
    DutchFlagPartition(pivot_index, &A);
    for(auto i : A){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}