#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

struct Comp{
    bool operator()(const pair<char, int>& a, const pair<char, int>& b){
        return a.second < b.second;
    }
};

vector<char> FindKMostVisitedPages(const vector<char>& pages, int k){
    vector<char> result;
    unordered_map<char, int> pageToFreqMap;
    for(auto page : pages){
        ++pageToFreqMap[page];
    }
    priority_queue<pair<char, int>, vector<pair<char, int>>, Comp>maxHeap;
    for(auto& entry : pageToFreqMap){
        maxHeap.emplace(entry);
    }
    int i=0;
    while(!maxHeap.empty() && i != k){
        auto page = maxHeap.top().first;
        maxHeap.pop();
        ++i;
        result.emplace_back(page);
    }
    return result;
}

int main(){
    vector<char> pages{'a', 'a', 'b', 'a', 'b', 'c', 'a', 'b', 'c', 'd', 'a', 'b', 'c', 'd', 'e'};
    int k = 3;
    auto result = FindKMostVisitedPages(pages, k);
    for(auto res : result){
        cout << res << endl;
    }
    return 0;
}