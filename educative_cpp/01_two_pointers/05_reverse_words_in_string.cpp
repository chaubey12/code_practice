#include <iostream>
#include <vector>
#include <regex>
#include <string>

using namespace std;

void StrRev(string &str, int startRev, int endRev){
    while(startRev < endRev){
        char temp = str[startRev];
        str[startRev] = str[endRev];
        str[endRev] = temp;
        startRev++;
        endRev--;
    }
}

string ReverseWords(string sentence){
    sentence = regex_replace(sentence, regex("^ +| +$|( ) +"), "$1");
    int strLen = sentence.length() - 1;
    StrRev(sentence, 0, strLen);
    for(int start=0, end=0; end < strLen; ++end){
        if(end == strLen || sentence[end] == ' '){
            int endIdx = (end == strLen) ? end : end - 1;
            StrRev(sentence, start, endIdx);
            start = end + 1;
        }
    }
    return sentence;
}

int main(){
    // TBD
    return 0;
}