#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <limits>

using namespace std;

class SmallestWindowSubstr{
public:
    static string find(const string& str, const string& pattern){
        unordered_map<char, int> charFrequencyMap;
        int minLength = str.length() + 1;
        int windowStart = 0, matched=0, substrStart=0;
        for(auto ch : pattern){
            charFrequencyMap[ch]++;
        }
        for(int windowEnd=0; windowEnd < str.length(); windowEnd++){
            char rightChar = str[windowEnd];
            if(charFrequencyMap.find(rightChar) != charFrequencyMap.end()){
                charFrequencyMap[rightChar]--;
                if(charFrequencyMap[rightChar] >= 0){
                    matched++;
                }
            }
            while(matched == pattern.length()){
                if(minLength > windowEnd - windowStart + 1){
                    minLength = windowEnd - windowStart + 1;
                    substrStart = windowStart;
                 }
                char leftChar = str[windowStart];
                windowStart++;
                if(charFrequencyMap.find(leftChar) != charFrequencyMap.end()){
                    if(charFrequencyMap[leftChar] == 0){
                        matched--;
                    }
                    charFrequencyMap[leftChar]++;
                }
            }
        }
        return minLength < str.length() ? str.substr(substrStart, minLength) : "";
    }
};

int main(){
    string str = "aaabdecx";
    string pattern = "abcd";
    cout << SmallestWindowSubstr::find(str, pattern) << endl;
    return 0;
}