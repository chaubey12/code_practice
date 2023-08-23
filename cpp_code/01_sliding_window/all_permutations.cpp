#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class AllPermutations{
public:
    static vector<int> find(string& str, string& pattern){
        vector<int> result;
        int matched = 0;
        int windowStart = 0;
        unordered_map<char, int> charFrequencyMap;
        for(auto ch : pattern){
            charFrequencyMap[ch]++;
        }
        for(int windowEnd = 0; windowEnd < str.length(); windowEnd++){
            char rightChar = str[windowEnd];
            if(charFrequencyMap.find(rightChar) != charFrequencyMap.end()){
                charFrequencyMap[rightChar]--;
                if(charFrequencyMap[rightChar] == 0){
                    matched++;
                }
            }
            if(matched == charFrequencyMap.size()){
                result.push_back(windowStart);
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
        return result;
    }
};

int main(){
    string str = "abbcabc";
    string pattern = "abc";
    auto result = AllPermutations::find(str, pattern);
    for(auto e : result){
        cout << e << " ";
    }
    cout << endl;
    return 0;
}