#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <unordered_map>

using namespace std;

struct Subarray{
    int start, end;
};

Subarray FindSmallestSubarrayCoveringSubset(istringstream* sin, vector<string>& query_strings){
    list<int> loc;
    unordered_map<string, list<int>::iterator> dict;
    for(const string& s : query_strings){
        dict.emplace(s, loc.end());
    }
    Subarray res = Subarray{-1, -1};
    int idx = 0;
    string s;
    while(*sin >> s){
        auto it = dict.find(s);
        if(it != dict.end()){
            if(it->second != loc.end()){
                loc.erase(it->second);
            }
            loc.emplace_back(idx);
            it->second = --loc.end();
        }
        if(loc.size() == query_strings.size()){
            if((res.start == -1 && res.end == -1) ||
                idx - loc.front() < res.end - res.start){
                res = {loc.front(), idx};
            }
        }
        ++idx;
    }
    return res;
}

int main(){
    string paragraph = "this is the most bad cruel place";
    istringstream ss(paragraph);
    vector<string> keywords = {"cruel", "most"};
    auto result = FindSmallestSubarrayCoveringSubset(&ss,keywords);
    cout << result.start <<", "<<result.end<<endl;
    return 0;
}