#include <iostream>
#include <vector>

using namespace std;

int GetHeightHelper(int cases, int drops, vector<vector<int>>* F){
    if(cases == 0 || drops == 0){
        return 0;
    }else if(cases == 1){
        return drops;
    }else{
        if((*F)[cases][drops] == -1){
            (*F)[cases][drops] = GetHeightHelper(cases, drops-1,F) + GetHeightHelper(cases-1, drops-1,F) + 1;
        }
    }
    return (*F)[cases][drops];
}

int GetHeight(int cases, int drops){
    vector<vector<int>> F(cases + 1, vector<int>(drops + 1, -1));
    return GetHeightHelper(cases, drops, &F);
}

int main(){
    int cases=2, drops=5;
    cout << GetHeight(cases, drops)<<endl;
    return 0;
}