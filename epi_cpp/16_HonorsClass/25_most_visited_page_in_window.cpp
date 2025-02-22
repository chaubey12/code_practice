// PLACEHOLDER
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <deque>
#include <queue>

using namespace std;

vector<pair<string, int>> KMostVisitedPagesInWindow(const vector<string>& pageVisits, int k, int w){
    unordered_map<string, int> visitCount;
    deque<string> window;
    for(const string& page : pageVisits){
        window.emplace_back(page);
        ++visitCount[page];
        if(window.size() > w){
            string oldestPage = window.front();
            window.pop_front();
            if(--visitCount[oldestPage] == 0){
                visitCount.erase(oldestPage);
            }
        }
    }
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<int>> minHeap;
    for(const auto& [page, count] : visitCount){
        minHeap.push({count, page});
        if(minHeap.size() > k){
            minHeap.pop();
        }
    }
    
    vector<pair<string, int>> result;
    while(!minHeap.empty()){
        result.push_back({minHeap.top().second, minHeap.top().first});
        minHeap.pop();
    }
    reverse(result.begin(), result.end());
    return result; 
}