#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> FindAnagrams(const vector<string>& dictionary){
    unordered_map<string, vector<string>> sorted_string_to_anagrams;
    for(const string& s : dictionary){
        string sorted_string(s);
        sort(sorted_string.begin(), sorted_string.end());
        sorted_string_to_anagrams[sorted_string].emplace_back(s);
    }
    vector<vector<string>> anagram_groups;
    for(const auto& p : sorted_string_to_anagrams){
        if(p.second.size() >= 2){
            anagram_groups.emplace_back(p.second);
        }
    }
    return anagram_groups;
}

int main(){
    const vector<string> dict{"elvis", "silent", "badcredit", "lives", "freedom", "listen", "levis", "money", "debitcard"};
    auto result = FindAnagrams(dict);
    for(auto vec : result){
        for(string str : vec){
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}