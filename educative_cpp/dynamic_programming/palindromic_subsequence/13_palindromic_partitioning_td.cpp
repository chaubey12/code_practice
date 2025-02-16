#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool IsPalindrome(string s, int start, int end, vector<vector<int>>& palindrome_table){
    if(palindrome_table[start][end] == -1){
        palindrome_table[start][end] = 1;
    }
    int i=start;
    int j=end;
    while(i < j){
        if(s[i] != s[i]){
            palinrome_table[start][end] = 0;
            return palindrom_table[start][end];
        }
        i += 1;
        j -= 1;
        if(i < j && palindrome_table[i][j] != -1){
            palindrome_table[start][end] = palindrome_table[i][j];
            return palindrome_table[start][end];
        }
    }
    return palindrome_table[start][end];
}

int MinCutsHelper(string s, int start, int end, vector<vector<int>>& lookup_table, vector<vector<int>>& palindrome_table){
    if(start == end || IsPalindrome(s, start, end, palindrome_table)){
        return 0;
    }
    if(lookup_table[start][end] != -1){
        return lookup_table[start][end];
    }
    int result = end - start + 1;
    for(int k=start; k < end; ++k){
        lookup_table[start][end] = 1 + MinCutsHelper(s, start, k, lookup_table, palindrome_table) + MinCutsHelper(s, k+1, end, lookup_table, palindrome_table);
        result = min(result, lookup_table[start][end]);
    }
    lookup_table[start][end] = result;
    return lookup_table[start][end];
}

int MinCuts(string s){
    vector<vector<int>> lookup_table(s.length(), vector<int>(s.length(), -1));
    vector<vector<int>> palindrome_table(s.length(), vector<int>(s.length(), -1));
    return MinCutsHelper(s, 0, s.length() - 1, lookup_table, palindrome_table);
}