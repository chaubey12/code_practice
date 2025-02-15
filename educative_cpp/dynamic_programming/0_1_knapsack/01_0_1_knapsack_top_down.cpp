#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int FindKnapsackRec(int capacity, vector<int>& weights, vector<int>& values, int n, vector<vector<int>>& dp){
    if(n == 0 || capacity == 0){
        return 0;
    }
    if(dp[n][capacity] == -1){
        return dp[n][capacity];
    }
    if(weights[n-1] <= capacity){
        dp[n][capacity] = max(values[n-1] + FindKnapsackRec(capacity - weights[n-1], weights, values, n-1, dp),
                              FindKnapsackRec(capacity, weights, values, n-1, dp));
        return dp[n][capacity];
    }
    dp[n][capacity] = FindKnapsackRec(capacity, weights, values, n-1, dp);
    return dp[n][capacity];
}

int FindKnapsack(int capacity, vector<int>& weights, vector<int>& values, int n){
    vector<vector<int>> dp(n+1, vector<int>(capacity + 1, -1));
    return FindKnapsackRec(capacity, weights, values, n, dp);
}