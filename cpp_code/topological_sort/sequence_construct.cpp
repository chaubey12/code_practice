#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class SequenceReconstruction{
public:
    static bool canMakeUnique(const vector<vector<int>>& sequences, vector<int>& unique){
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> inDegree;
        for(auto sequence : sequences){
            for(int num : sequence){
                graph[num] = vector<int>();
                inDegree[num] = 0;
            }
        }
        for(auto sequence : sequences){
            for(int i = 0; i < sequence.size() - 1; i++){
                int parent = sequence[i];
                int child = sequence[i+1];
                graph[parent].push_back(child);
                inDegree[child]++;
            }
        }
        queue<int> sources;
        for(auto entry : inDegree){
            if(entry.second == 0){
                sources.push(entry.first);
            }
        }
        int idx = 0;
        while(!sources.empty()){
            if(sources.size() != 1){
                return false;
            }
            int parent = sources.front();
            sources.pop();
            if(parent != unique[idx]){
                return false;
            }
            idx++;
            vector<int> children = graph[parent];
            for(auto child : children){
                inDegree[child]--;
                if(inDegree[child] == 0){
                    sources.push(child);
                }
            }
        }
        return true;
    }
};

int main(){
    vector<vector<int>> sequences = {{1, 2}, {2, 3}, {3, 4}};
    vector<int> unique = {1, 2, 3, 4};
    if(SequenceReconstruction::canMakeUnique(sequences, unique)){
        cout << "CAN MAKE UNIQUE" << endl;
    }else{
        cout << "CANNOT MAKE UNIQUE" << endl;
    }
    sequences = {{1, 2}, {2, 3}, {2, 4}};
    unique = {1, 2, 3, 4};
    if(SequenceReconstruction::canMakeUnique(sequences, unique)){
        cout << "CAN MAKE UNIQUE" << endl;
    }else{
        cout << "CANNOT MAKE UNIQUE" << endl;
    }
    return 0;
}