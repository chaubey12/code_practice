#include <iostream>
#include <vector>
#include <string>

using namespace std;

int CountPalindromicSubstring(string s){
    int n = s.length();
    vector<vector<bool>> lookup_table(s.length(), vector<bool>(s.length(), false));
    int psCount=0;
    for(int i=n-1; i >= 0; --i){
        for(int j=i; j < n; ++j){
            if(s[i] == s[j]){
                if(i + 1 >= j){
                    lookup_table[i][j] = true;
                }else{
                    lookup_table[i][j] = lookup_table[i+1][j-1];
                }
            }
            if(lookup_table[i][j]){
                psCount += 1;
            }
        }
    }
    return psCount;
}