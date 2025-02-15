#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

bool CheckPalindrome(string s, int start, inr end, vector<vector<bool>> &boolMem){
    if(start > end){
        return true;
    }
    if(boolMem[start][end] != false){
        return boolMem[start][end];
    }
    if(s[start] != s[end]){
        boolMem[start][end] = false;
        return boolMem[start][end];
    }
    boolMem[start][end] = CheckPalindrome(s, start + 1, end - 1, boolMem);
    return boolMem[start][end];
}


int CountPalindromicSubstringsRecursive(vector<vector<int>> lookup_table, string s, int start, int end){
    if(start >= end){
        return 0;
    }
    vector<vector<bool>> boolMem(s.length(), vector<int>(s.length(), false));
    if(lookup_table[start][end] != -1){
        return lookup_table[start][end];
    }
    if(CheckPalindrome(s, start, end, boolMem)){
        lookup_table[start][end] = 1 + CountPalindromicSubstringsRecursive(lookup_table, s, start + 1, end)
                                     + CountPalindromicSubstringsRecursive(lookup_table, s, start, end - 1)
                                     - CountPalindromicSubstringsRecursive(lookup_table, s, start + 1, end - 1);
        return lookup_table[start][end];                                    
    }else{
        lookup_table[start][end] = CountPalindromicSubstringsRecursive(lookup_table, s, start + 1, end)
                                     + CountPalindromicSubstringsRecursive(lookup_table, s, start, end - 1);
        return lookup_table[start][end];
    }
}

int CountPalindromicSubstrings(string s){
    vector<vector<int>> lookup_table(s.length(), vector<int>(s.length(), -1));
    return s.length() + CountPalindromicSubstringsRecursive(lookup_table, s, 0, s.length() - 1);
}