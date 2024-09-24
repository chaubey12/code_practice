#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

struct Comp{
    bool operator()(const pair<char, int>& a, const pair<char, int>& b){
        return a.second < b.second;
    }
};


string ReorganizeString(const string& str){
    unordered_map<char, int> charFrequencyMap;
    for(char ch : str){
        ++charFrequencyMap[ch];
    }
    priority_queue<pair<char, int>, vector<pair<char, int>>, Comp> mostFreqChars;
    for(auto entry : charFrequencyMap){
        mostFreqChars.emplace(entry);
    }
    pair<char, int> prev;
    string result = "";
    while(mostFreqChars.size() > 1){
        if(result.back() == mostFreqChars.top().first){
            prev = mostFreqChars.top();
            mostFreqChars.pop();
            if(!mostFreqChars.empty()){
                auto curr = mostFreqChars.top();
                mostFreqChars.pop();
                char ch = curr.first;
                int count = curr.second;
                result += curr.first;
                --count;
                if(count != 0){
                    mostFreqChars.emplace(make_pair(ch, count));
                }
            }
            mostFreqChars.emplace(prev);
        }else{
            auto curr = mostFreqChars.top();
            mostFreqChars.pop();
            result += curr.first;
            --curr.second;
            if(curr.second != 0){
                mostFreqChars.emplace(curr);
            }
        }
    }
    if(mostFreqChars.size() == 1){
        if(mostFreqChars.top().second > 1){
            return "";
        }else{
            result += mostFreqChars.top().first;
        }
    }
    return result;
}

int main(){
    string str = "aaaaabbddee";
    cout << ReorganizeString(str) << endl;
    return 0;
}