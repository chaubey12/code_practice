#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

vector<string> KMostFrequentQueries(const vector<string>& queries, int k){
    unordered_map<string, int> query_freq_map;
    priority_queue<pair<string, int>, vector<pair<string, int>>, function<bool(pair<string, int>&, pair<string, int>&)>>minHeap
    ([](const pair<string, int>& a, const pair<string, int>& b) -> bool{
       return a.second >= b.second; 
    });
    for(const string& query : queries){
        ++query_freq_map[query];
    }
    vector<string> result;
    for(auto& entry : query_freq_map){
        if(minHeap.size() < k){
            minHeap.emplace(entry);
        }else{
            if(entry.second > minHeap.top().second){
                minHeap.emplace(entry);
                minHeap.pop();
            }
        }
    }
    while(!minHeap.empty()){
        result.push_back(minHeap.top().first);
        minHeap.pop();
    }
    return result;
}

int main(){
    vector<string> queries;
    for(int i=0; i < 7; ++i){
        queries.emplace_back("GET");
    }
    for(int i=0; i < 4; ++i){
        queries.emplace_back("PUT");
    }
    for(int i=0; i < 5; ++i){
        queries.emplace_back("PATCH");
    }
    for(int i=0; i < 6; ++i){
        queries.emplace_back("DELETE");
    }
    auto result = KMostFrequentQueries(queries, 3);
    for(auto entry : result){
        cout << entry << " ";
    }
    cout << endl;
    return 0;
}