#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class LongestSubStrWithKDistinct{
public:
    static int find(const string& str, int k){
        unordered_map<char, int> charFrequencyMap;
        int maxLength = 0, windowStart = 0;
        for(int windowEnd = 0; windowEnd < str.length(); windowEnd++){
            char rightChar = str[windowEnd];
            charFrequencyMap[rightChar]++;
            while(charFrequencyMap.size() > k){
                char leftChar = str[windowStart];
                if(charFrequencyMap.find(leftChar) != charFrequencyMap.end()){
                    charFrequencyMap[leftChar]--;
                    if(charFrequencyMap[leftChar] == 0){
                        charFrequencyMap.erase(leftChar);
                    }
                }
                windowStart++;
            }
            maxLength = max(maxLength, windowEnd - windowStart + 1);
        }
        return maxLength;
    }
};

int main(){
    string str = "abcccbbbbaaadefgh";
    int k = 3;
    cout << LongestSubStrWithKDistinct::find(str, k) << endl;
    return 0;
}