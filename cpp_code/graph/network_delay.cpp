#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;

int NetworkDelayTime(const vector<vector<int>>& times, int n, int k){
    unordered_map<int, vector<pair<int, int>>> adjacency;
    for(auto& time : times){
        int src = time[0];
        int dest = time[1];
        int t = time[2];
        adjacency[src].push_back(make_pair(dest, t));
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, k));
    int delay = 0;
    unordered_set<int> visited;
    while(!pq.empty()){
        int time = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if(visited.count(node)){
            continue;
        }
        visited.insert(node);
        delay = max(delay, time);
        vector<pair<int, int>> neighbors = adjacency[node];
        for(auto& neighbor : neighbors){
            int neighborNode = neighbor.first;
            int neighborTime = neighbor.second;
            if(!visited.count(neighborNode)){
                int newTime = time + neighborTime;
                pq.push(make_pair(newTime, neighborNode));
            }
        }

    }
    return -1;
}

int main(){
    vector<vector<vector<int>>> times = {
        {{2,1,1}, {3,2,1}, {3,4,2}},
        {{2,1,1}, {1,3,1}, {3,4,2}, {5,4,2}},
        {{1,2,1}, {2,3,1}, {3,4,1}},
        {{1,2,1}, {2,3,1}, {3,5,2}},
        {{1,2,2}}
    };
    vector<int> n = {4,5,4,5,2};
    vector<int> k = {3,1,1,1,2};
    for(int i = 0; i < times.size(); ++i){
        cout << i+1 << ".\t times = [";
        for(auto it = times[i].begin(); it != times[i].end(); ++it){
            cout << "[" << (*it)[0] << ", " << (*it)[1] << ", " << (*it)[2] << "]";
            if(it != times[i].end() - 1){
                cout << ", ";
            }
            cout << "]\n";
            cout << "\t number of nodes 'n' = " << n[i] << endl;
            cout << "\t number of nodes 'k' = " << k[i] << endl << endl;
            cout << "\t Minimum amount of time required = " << NetworkDelayTime(times[i], n[i], k[i]) << endl;
            cout << string(100, '-') << endl;
        }
    }
    return 0;
}