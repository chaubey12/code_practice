#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class AllSchedulingOrder{
public:
    static vector<vector<int>> getAll(const vector<vector<int>>& prerequisites, int tasks){
        vector<vector<int>> allOrders;
        vector<int> currOrder;
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> inDegree;
        for(int i = 0; i < tasks; i++){
            graph[i] = vector<int>();
            inDegree[i] = 0;
        }
        for(auto pre : prerequisites){
            int parent = pre[0];
            int child = pre[1];
            graph[parent].push_back(child);
            inDegree[child]++;
        }
        vector<int> sources;
        for(auto entry : inDegree){
            if(entry.second == 0){
                sources.push_back(entry.first);
            }
        }
        getAllSorts(graph, inDegree, sources, allOrders, currOrder);
        return allOrders;
    }
private:
    static void getAllSorts(unordered_map<int, vector<int>>& graph, unordered_map<int, int>& inDegree, vector<int>& sources, vector<vector<int>>& allOrders, vector<int>& currOrder){
        if(sources.size() > 0){
            for(int i = 0; i < sources.size(); i++){
                int parent = sources[i];
                currOrder.push_back(parent);
                vector<int> nextSource(sources);
                nextSource.erase(nextSource.begin() + i);
                vector<int> children = graph[parent];
                for(auto child : children){
                    inDegree[child]--;
                    if(inDegree[child] == 0){
                        nextSource.push_back(child);
                    }
                }
                getAllSorts(graph, inDegree, nextSource, allOrders, currOrder);
                currOrder.pop_back();
                for(auto child : children){
                    inDegree[child]++;
                }
            }
        }
        if(currOrder.size() == graph.size()){
            allOrders.push_back(currOrder);
        }
    }
};


int main(){
    vector<vector<int>> prerequisites1 = {{2, 5}, {0, 5}, {0, 4}, {1, 4}, {3, 2}, {1,3}}; 
    int tasks1 = 6;
    auto results = AllSchedulingOrder::getAll(prerequisites1, tasks1);
    for(auto result : results){
        for(int val : result){
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;
    vector<vector<int>> prerequisites2 = {{3, 2}, {3, 0}, {2, 0}, {2, 1}}; 
    int tasks2 = 4;
    results = AllSchedulingOrder::getAll(prerequisites2, tasks2);
    for(auto result : results){
        for(int val : result){
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}