#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <limits>

using namespace std;

class NoRepeatSubstr{
public:
    static int find(string& str){
        int maxLen = numeric_limits<int>::min();
        int windowStart = 0;
        unordered_map<char, int> charIndexMap;
        for(int windowEnd=0; windowEnd < str.length(); windowEnd++){
            char rightChar = str[windowEnd];
            if(charIndexMap.find(rightChar) != charIndexMap.end()){
                windowStart = max(windowStart, charIndexMap[rightChar] + 1);
            }
            charIndexMap[rightChar] = windowEnd;
            maxLen = max(maxLen, windowEnd - windowStart + 1);
        }
        return maxLen;
    } 
};

int main(){
    string str = "aabcdecbb";
    cout << NoRepeatSubstr::find(str) << endl;
    return 0;
}