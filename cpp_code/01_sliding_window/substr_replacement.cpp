#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <limits>

using namespace std;

class SubstringReplacement{
public:
    static int find(string& str, int k){
        int windowStart=0;
        unordered_map<char,int> charFrequencyMap;
        int maxLen = 0;
        int maxRepeatLetterCount = 0;
        for(int windowEnd=0; windowEnd < str.length(); windowEnd++){
            char rightChar = str[windowEnd];
            charFrequencyMap[rightChar]++;
            maxRepeatLetterCount = max(maxRepeatLetterCount, charFrequencyMap[rightChar]);
            if(windowEnd - windowStart + 1 - maxRepeatLetterCount > k){
                char leftChar = str[windowStart];
                charFrequencyMap[leftChar]--;
                windowStart++;
            }
            maxLen = max(maxLen,windowEnd - windowStart + 1);
        }
        return maxLen;
    }
};

int main(){
    string str = "aabccbb";
    int k = 2;
    cout << SubstringReplacement::find(str, k) << endl;
    return 0;
}