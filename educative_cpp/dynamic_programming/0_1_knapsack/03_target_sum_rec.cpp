#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int FindTargetSumWaysRec(vector<int>& arr, int i, int T){
    if(i == arr.size()){
        if(T == 0){
            return 1;
        }
        return 0;
    }
    return FindTargetSumWaysRec(arr, i + 1, T + arr[i]) + FindTargetSumWaysRec(arr, i + 1, T - arr[i]);
}

int FindTargetSumWays(vector<int>& arr, int T){ 
    return FindTargetSumWaysRec(arr, 0, T);
}