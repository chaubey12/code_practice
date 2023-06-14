#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class TopologicalSort{
public:
    static vector<int> sort(int vertices, vector<vector<int>>& edges){
        vector<int> sortedOrder;
        unordered_map<int, int> inDegree;
        unordered_map<int, vector<int>> graph;
        for(int i = 0; i < vertices; i++){
            inDegree[i] = 0;
            graph[i] = vector<int>();
        }
        for(int i = 0; i < edges.size(); i++){
            int parent = edges[i][0], child = edges[i][1];
            inDegree[child]++;
            graph[parent].push_back(child);
        }
        queue<int> sources;
        for(auto entry : inDegree){
            if(entry.second == 0){
                sources.push(entry.first);
            }
        }
        while(!sources.empty()){
            int vertex = sources.front();
            sources.pop();
            sortedOrder.push_back(vertex);
            vector<int> children = graph[vertex];
            for(auto child : children){
                inDegree[child]--;
                if(inDegree[child] == 0){
                    sources.push(child);
                }
            }
        }
        if(sortedOrder.size() != vertices){
            return vector<int>();
        }
        return sortedOrder;
    }
};

int main(){

    return 0;
}