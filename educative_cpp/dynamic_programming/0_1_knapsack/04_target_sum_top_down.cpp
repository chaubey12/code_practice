#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>

using namespace std;

int FindTargetSumWaysRec(vector<int>& arr, int T, int total, int i, int sum, vector<vector<int>> &dp){
    if(i == arr.size()){
        if(sum == T){
            return 1;
        }
        return 0;
    }
    if(dp[i][sum + total] != -1){
        return dp[i][sum + total];
    }
    dp[i][sum + total] = FindTargetSumWaysRec(arr, T, total, i + 1, sum - arr[i], dp) +
                         FindTargetSumWaysRec(arr, T, total, i + 1, sum + arr[i], dp);
    return dp[i][sum + total];
}

int FindTargetSumWays(vector<int>& arr, int T){
    int total = accumulate(arr.begin(), arr.end(), 0);
    if(total < abs(T)){
        return 0;
    }
    vector<vector<int>> dp(arr.size(), vector<int> (2*total+1, -1));
    return FindTargetSumWaysRec(arr, T, total, 0, 0, dp);
}