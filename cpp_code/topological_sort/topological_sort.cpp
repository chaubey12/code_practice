#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;


class TopologicalSort{
public:
    static vector<int> order(const vector<vector<int>>& edges, int vertices){
        vector<int> sortedOrder;
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> inDegree;
        for(int i = 0; i < vertices; i++){
            inDegree[i] = 0;
            graph[i] = vector<int>();
        }
        for(auto edge : edges){
            int parent = edge[0];
            int child = edge[1];
            graph[parent].push_back(child);
            inDegree[child]++;
        }
        queue<int> sources;
        for(auto edge : inDegree){
            if(edge.second == 0){
                sources.push(edge.first);
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

        if(sortedOrder.size() != vertices){
            return vector<int>();
        }
        return sortedOrder;
    }
};


int main(){
    vector<vector<int>> edges1 = {{3,2}, {3,0}, {2,0}, {2,1}};
    int vertices1 = 4;
    auto result = TopologicalSort::order(edges1, vertices1);
    for(int i : result){
        cout << i << " ";
    }
    cout << endl;
    vector<vector<int>> edges2 = {{4, 2}, {4, 3}, {2, 0}, {2, 1}, {3, 1}};
    int vertices2 = 5;
    result = TopologicalSort::order(edges2, vertices2);
    for(int i : result){
        cout << i << " ";
    }
    cout << endl;
    vector<vector<int>> edges3 = {{6, 4}, {6, 2}, {5, 3}, {5, 4}, {3, 0}, {3, 1}, {3, 2}, {4, 1}};
    int vertices3 = 7;
    result = TopologicalSort::order(edges3, vertices3);
    for(int i : result){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}