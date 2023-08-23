#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;

class PermutationInString{
public:
    static bool find(string& str, string& pattern){
        unordered_map<char, int> charFrequencyMap;
        int windowStart=0;
        int matched = 0;
        for(auto ch : pattern){
            charFrequencyMap[ch]++;
        }
        for(int windowEnd=0; windowEnd < str.length(); windowEnd++){
            char rightChar = str[windowEnd];
            if(charFrequencyMap.find(rightChar) != charFrequencyMap.end()){
                charFrequencyMap[rightChar]--;
                if(charFrequencyMap[rightChar] == 0){
                    matched++;
                }
            }
            if(matched == charFrequencyMap.size()){
                return true;
            }
            if(windowEnd >= (pattern.size() - 1)){
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
        return false;
    }
};

int main(){
    string pattern = "abc";
    string str = "pqrsppabac";
    if(PermutationInString::find(str, pattern)){
        cout << "PERMUTATION FOUND" << endl;
    }else{
        cout << "PERMUTATION NOT FOUND" << endl;
    }
    return 0;
}