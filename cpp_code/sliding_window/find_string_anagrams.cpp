#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class FindStringAnagrams{
public:
    static vector<int> findAnagrams(const string& str, const string& pattern){
        unordered_map<char, int> charFrequencyMap;
        int windowStart=0, matches=0;
        vector<int> result;
        for(char c : pattern){
            charFrequencyMap[c]++;
        }
        for(int windowEnd=0; windowEnd < str.length(); windowEnd++){
            char rightChar = str[windowEnd];
            if(charFrequencyMap.find(rightChar) != charFrequencyMap.end()){
                charFrequencyMap[rightChar]--;
                if(charFrequencyMap[rightChar] == 0){
                    matches++;
                }
            }
            if(matches == (int)charFrequencyMap.size()){
                result.push_back(windowStart);
            }
            if(windowEnd >= pattern.length() - 1){
                char leftChar = str[windowStart++];
                if(charFrequencyMap.find(leftChar) != charFrequencyMap.end()){
                    if(charFrequencyMap[leftChar] == 0){
                        matches--;
                    }
                    charFrequencyMap[leftChar]++;
                }
            }
        }
        return result;
    }

};

int main(){
    string str = "iamadiscodancer iamadiscodancep iamadiscodancer";
    string pattern = "randec";
    auto result = FindStringAnagrams::findAnagrams(str, pattern);
    cout << "Anagrams can be found here: ";
    for(auto item : result){
        cout << item << ", ";
    }
    cout << endl;
    return 0;
}