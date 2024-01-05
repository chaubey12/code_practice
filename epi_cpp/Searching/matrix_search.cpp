#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

bool MatrixSearch(const vector<vector<int>>& A, int x){
    int row=0, col=A.size()-1;
    while(row < A.size() && col >= 0){
        if(A[row][col] == x){
            return true;
        }else if(A[row][col] < x){
            ++row;
        }else{
            --col;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> A {{1,2,3}, {4,5,6}, {7,8,9}};
    int k = 15;
    if(MatrixSearch(A, k)){
        cout << "FOUND"<<endl;
    }else{
        cout << "NOT FOUND"<<endl;
    }
    return 0;
}