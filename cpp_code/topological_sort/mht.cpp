#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class MinHeightTree{
public:
    static vector<int> findTrees(vector<vector<int>>& edges, int nodes){
        if(nodes <= 0){
            return vector<int>();
        }
        if(nodes == 1){
            return vector<int>{0};
        }
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> inDegree;
        for(int i = 0; i < nodes; i++){
            graph[i] = vector<int>();
            inDegree[i] = 0;
        }
        for(auto edge : edges){
            int parent = edge[0];
            int child = edge[1];
            graph[parent].push_back(child);
            graph[child].push_back(parent);
            inDegree[child]++;
            inDegree[parent]++;
        }
        queue<int> sources;
        queue<int> leaves;
        for(auto entry : inDegree){
            if(entry.second == 1){
                leaves.push(entry.first);
            }
        }
        int totalNodes = nodes;
        while(totalNodes > 2){
            int leavesSize = leaves.size();
            totalNodes -= leavesSize;
            for(int i = 0; i < leavesSize; i++){
                int parent = leaves.front();
                leaves.pop();
                vector<int> children = graph[parent];
                for(auto child : children){
                    inDegree[child]--;
                    if(inDegree[child] == 1){
                        leaves.push(child);
                    }
                }
            }
        }
        vector<int> result;
        while(!leaves.empty()){
            result.push_back(leaves.front());
            leaves.pop();
        }
        return result;
    }
};

int main(){
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {1, 3}, {2, 4}};
    int nodes = 5;
    auto result = MinHeightTree::findTrees(edges, nodes);
    for(auto node : result){
        cout << node << " ";
    }
    cout << endl;
    return 0;
}