#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class SchedulingOrder{
public:
    static vector<int> get(const vector<vector<int>>& prerequisites, int tasks){
        vector<int> scheduleOrder;
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> inDegree;
        for(int i=0; i < tasks; i++){
            graph[i] = vector<int>();
            inDegree[i] = 0;
        }
        for(auto pre : prerequisites){
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
            scheduleOrder.push_back(parent);
            vector<int> children = graph[parent];
            for(auto child : children){
                inDegree[child]--;
                if(inDegree[child] == 0){
                    sources.push(child);
                }
            }
        }
        if(scheduleOrder.size() != tasks){
            return vector<int>();
        }
        return scheduleOrder;
    }
};

int main(){
    vector<vector<int>> prerequisites = {{2, 5}, {0, 5}, {0, 4}, {1, 4}, {3, 2}, {1,3}}; 
    int tasks = 6;
    auto result = SchedulingOrder::get(prerequisites, tasks);
    for(int val : result){
        cout << val << " ";
    }
    cout << endl;
    return 0;
}