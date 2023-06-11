#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class StringAnagram{
public:
    static bool findAnagram(const string& str, const string& pattern){
        unordered_map<char, int> charFrequencyMap;
        int windowStart=0, matched = 0;
        for(auto c : pattern){
            charFrequencyMap[c]++;
        }
        for(int windowEnd = 0; windowEnd < str.length(); windowEnd++){
            char rightChar = str[windowEnd];
            if(charFrequencyMap.find(rightChar) != charFrequencyMap.end()){
                charFrequencyMap[rightChar]--;
                if(charFrequencyMap[rightChar] == 0){
                    matched += 1;
                }
            }
            if(matched == (int)charFrequencyMap.size()){
                return true;
            }
            if(windowEnd >= pattern.length() - 1){
                char leftChar = str[windowStart++];
                if(charFrequencyMap.find(leftChar) == charFrequencyMap.end()){
                    if(charFrequencyMap[leftChar] == 0){
                        matched++;
                    }
                    charFrequencyMap[leftChar]++;
                }
            }
        }
        return false;
    }
};

int main(){
    string str = "iamadiscodancep";
    string pattern = "randec";
    if(StringAnagram::findAnagram(str, pattern)){
        cout << "ANAGRAM FOUND" << endl;
    }else{
        cout << "ANAGRAM NOT FOUND" << endl;
    }
    return 0;
}