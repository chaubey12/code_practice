#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int MinCutsHelper(string s, vector<vector<int>>& palindrome_table, vector<int>& dp){
    int n = s.length();
    for(int i=0; i < n; ++i){
        palindrome_table[i][i] = 1;
    }
    for(int i=n-1; i > -1; i--){
        for(int j=i+1; j < n; j++){
            if(s[i] == s[j]){
                if((j - i == 1) || (palindrome_table[i+1][j-1])){
                    palindrome_table[i][j] = 1;
                }
            }
        }
    }
    for(int i=n-1; i > -1; i--){
        if(palindrome_table[i][n-1] == 1){
            dp[i] = 0;
        }else{
            for(int j = n - 2; j > i - 1; j--){
                if(palindrome_table[i][j] == 1){
                    dp[i] = min(dp[i], 1 + dp[j + 1]);
                }
            }
        }
    }
    return dp[0];
}

int MinCuts(string s){
    int n = s.length();
    vector<vector<int>> palindrome_table(s.length(), vector<int>(s.length(), 0));
    vector<int> dp(n, numeric_limits<int>::max());
}