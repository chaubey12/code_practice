#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class TaskScheduling{
public:
    static bool isSchedulingPossible(vector<vector<int>>& prerequisutes, int tasks){
        vector<int> sortedOrder;
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> inDegree;
        for(int i = 0; i < tasks; i++){
            graph[i] = vector<int>();
            inDegree[i] = 0;
        }
        for(auto pre : prerequisutes){
            int parent = pre[0];
            int child = pre[1];
            graph[parent].push_back(child);
            inDegree[child]++;
        }
        queue<int> sources;
        for(auto entry : inDegree){
            if(entry.second == 0){
                sources.push(entry.first);
            }
        }
        while(!sources.empty()){
            int parent = sources.front();
            sources.pop();
            sortedOrder.push_back(parent);
            vector<int> children = graph[parent];
            for(auto child : children){
                inDegree[child]--;
                if(inDegree[child] == 0){
                    sources.push(child);
                }
            }
        }
        cout << sortedOrder.size() << endl;
        if(sortedOrder.size() != tasks){
            return false;
        }
        return true;
    }
};


int main(){
    vector<vector<int>> edges1 = {{3,2}, {3,0}, {2,0}, {2,1}};
    int vertices1 = 4;
    auto result = TaskScheduling::isSchedulingPossible(edges1, vertices1);
    if(result){
        cout << "POSSIBLE" << endl;
    }else{
        cout << "NOT POSSIBLE" << endl;
    }
    vector<vector<int>> edges2 = {{4, 2}, {4, 3}, {2, 0}, {2, 1}, {3, 1}};
    int vertices2 = 5;
    result = TaskScheduling::isSchedulingPossible(edges2, vertices2);
    if(result){
        cout << "POSSIBLE" << endl;
    }else{
        cout << "NOT POSSIBLE" << endl;
    }
    vector<vector<int>> edges3 = {{6, 4}, {6, 2}, {5, 3}, {5, 4}, {3, 0}, {3, 1}, {3, 2}, {4, 1}};
    int vertices3 = 7;
    result = TaskScheduling::isSchedulingPossible(edges3, vertices3);
    if(result){
        cout << "POSSIBLE" << endl;
    }else{
        cout << "NOT POSSIBLE" << endl;
    }
    return 0;
}