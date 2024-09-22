#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int LongestPalindrome(const string& str){
    unordered_map<char, int> charFrequencyMap;
    for(auto& ch : str){
        ++charFrequencyMap[ch];
    }
    int longestPalidromeLength=0;
    int maxOddcount = 0;
    for(auto entry : charFrequencyMap){
        if(entry.second & 1){
            maxOddcount = max(maxOddcount, entry.second);
        }else{
            longestPalidromeLength += entry.second;
        }
    }
    longestPalidromeLength += maxOddcount;
    return longestPalidromeLength;
}