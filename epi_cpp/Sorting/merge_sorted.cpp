#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void MergeTwoSortedArrays(int A[], int m, int B[], int n){
    int a = m-1, b = n-1, write_idx = m + n - 1;
    while(a >= 0 && b >= 0){
        A[write_idx--] = A[a] > B[b] ? A[a--] : B[b--];
    }
    while(b >= 0){
        A[write_idx--] = B[b--];
    }
}

int main(){
    int A[7] = {1,3,5};
    int m = 3;
    int B[] = {2,4,6,8};
    int n = 4;
    MergeTwoSortedArrays(A, m, B, n);
    for(auto elem : A){
        cout << elem << " ";
    }
    cout << endl;
    return 0;
}