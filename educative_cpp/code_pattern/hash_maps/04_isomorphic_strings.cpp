#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

bool IsIsomorphic(string string1, string string2){
    unordered_map<char, char> mapStr1Str2;
    unordered_map<char, char> mapStr2Str1;
    for(int i=0; i < string1.length(); ++i){
        char char1 = string1[i];
        char char2 = string2[i];
        if(mapStr1Str2.find(char1) != mapStr1Str2.end() && mapStr1Str2[char1] != char2){
            return false;
        }
        if(mapStr2Str1.find(char2) != mapStr2Str1.end() && mapStr2Str1[char2] != char1){
            return false;
        }
        mapStr1Str2[char1] = char2;
        mapStr2Str1[char2] = char1;
    }
    return true;
}

int main(){
    vector<string> aStringList = {
        "egg",
        "foo",
        "paper",
        "baac",
        "aaeaa"
    };
    vector<string> bStringList = {
        "all",
        "bar",
        "title",
        "baba",
        "uuxyy"  
    };
    for(int i=0; i < aStringList.size(); ++i){
        cout << boolalpha << IsIsomorphic(aStringList[i], bStringList[i])<<endl;
    }
    return 0;
}