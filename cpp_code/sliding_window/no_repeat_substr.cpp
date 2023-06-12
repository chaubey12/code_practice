#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class NoRepeatSubstring{
public:
    static int findLength(const string& str){
        int windowStart = 0, maxLength = 0;
        unordered_map<char, int> charIndexMap;
        for(int windowEnd = 0; windowEnd < str.length(); windowEnd++){
            char rightChar = str[windowEnd];
            if(charIndexMap.find(rightChar) != charIndexMap.end()){
                windowStart = max(windowStart, charIndexMap[rightChar] + 1);
            }
            charIndexMap[rightChar] = windowEnd;
            maxLength = max(maxLength, windowEnd - windowStart + 1);
        }
        return maxLength;
    }
};


int main(){
    string str = "abcddefghhabcdiff";
    cout << "Longest non repeating substring is : "<< NoRepeatSubstring::findLength(str) << endl;
    return 0;
}