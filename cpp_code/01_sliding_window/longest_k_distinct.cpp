#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class LongestKDistinct{
public:
    static int find(string& str, int k){
        unordered_map<char, int> charFrequencyMap;
        int windowStart = 0;
        int maxLength = numeric_limits<int>::min();
        for(int windowEnd = 0; windowEnd < str.length(); windowEnd++){
            char rightChar = str[windowEnd];
            charFrequencyMap[rightChar]++;
            while(charFrequencyMap.size() > k){
                char leftChar = str[windowStart];
                charFrequencyMap[leftChar]--;
                if(charFrequencyMap[leftChar] == 0){
                    charFrequencyMap.erase(leftChar);
                }
                windowStart++;
            }
            maxLength = max(maxLength, windowEnd - windowStart + 1);
        }
        return maxLength;
    }
};

int main(){
    string str = "cbbebi";
    int k = 3;
    cout << LongestKDistinct::find(str, k) << endl;
    str = "araaci";
    k = 1;
    cout << LongestKDistinct::find(str, k) << endl;
    return 0;
}