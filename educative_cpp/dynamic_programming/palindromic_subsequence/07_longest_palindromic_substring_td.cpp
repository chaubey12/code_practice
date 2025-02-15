#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

int FindLongestPalindromicSubstringLengthRecursive(vector<vector<int>> lookup_table, string s, int start, int end){
    if(start == end){
        return 1;
    }
    if(lookup_table[start][end] == -1){
        if(s[start] == s[end]){
            int substringLength = end - start + 1;
            if(substringLength == 2 + FindLongestPalindromicSubstringLengthRecursive(lookup_table, s, start+1, end-1)){
                lookup_table[start][end] = substringLength;
                return lookup_table[start][end];
            }
        }
        lookup_table[start][end] = max(FindLongestPalindromicSubstringLengthRecursive(lookup_table, s, start + 1, end), FindLongestPalindromicSubstringLengthRecursive(lookup_table, s, start, end - 1));
    }
    return lookup_table[start][end];
}


int FindLongestPalindromicSubstringLength(string s){
    vector<vector<int>> lookup_table(s.length(), vector<int>(s.length(), -1));
    return FindLongestPalindromicSubstringLengthRecursive(lookup_table, s, 0, s.length() - 1);
}