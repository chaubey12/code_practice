#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void ReverseStr(string& str, int start, int end){
    while(start < end){
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        ++start;
        --end;
    }
}

string ReverseWords(string sentence){
    reverse(sentence.begin(), sentence.end());
    int start = 0, end = 0;
    int len = sentence.size();
    while(start < len){
        while((end < len) && (sentence[end] != ' ')){
            ++end;
        }
        ReverseStr(sentence, start, end-1);
        start = end + 1;
        end += 1;
    }
    return sentence;
}

int main(){
    string sentence = "The quick brown fox jumped over the lazy dog";
    auto result = ReverseWords(sentence);
    cout << result << endl;
    return 0;
}