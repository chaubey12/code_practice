#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int FindLongestPalindromicSubstring(string s){
    vector<vector<int>> lookup_table(s.length(), vector<int>(s.length()));
    for(int i=0; i < s.length(); ++i){
        lookup_table[i][i] = 1;
    }
    for(int start = s.length() - 2; start >= 0; --start){
        for(int end = start + 1; end < s.length; ++end){
            if(s[start] == s[end]){
                int substringLength = end - start + 1;
                if(substringLength == 2 || substringLength == 2 + lookup_table[start + 1][end - 1]){
                    lookup_table[start][end] = substringLength;
                }else{
                    lookup_table[start][end] = max(lookup_table[start + 1][end], lookup_table[start][end - 1]);
                }
            }else{
                lookup_table[start][end] = max(lookup_table[start + 1][end], lookup_table[start][end - 1]);
            }
        }
    }
    return lookup_table[0][s.length() - 1];
}