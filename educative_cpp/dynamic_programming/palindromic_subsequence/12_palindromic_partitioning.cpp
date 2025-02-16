#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool IsPalindrome(string s, int start, int end){
    while(start < end){
        if(s[start] != s[end]){
            return false;
        }
        ++start;
        --end;
    }
    return true;
}

int MinCutsHelper(string s, int start, int end){
    if(start == end || IsPalindrome(s, start, end)){
        return 0;
    }
    int result = end - start + 1;
    for(int k=start; k < end; ++k){
        int totalCuts = 1 + MinCutsHelper(s, i, k) + MinCutsHelper(s, k+1, j);
        result = min(result, totalCuts);
    }
    return result;
}


int MinCuts(string s){
    return MinCutsHelper(s, 0, s.length() - 1);
}