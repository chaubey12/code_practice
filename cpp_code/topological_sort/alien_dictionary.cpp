#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

class AlienDictionary{
public:
    static string getOrder(vector<string>& words){
        string wordOrder;
        unordered_map<char, vector<char>> graph;
        unordered_map<char, int> inDegree;
        for(auto word : words){
            for(auto ch : word){
                graph[ch] = vector<char>();
                inDegree[ch] = 0;
            }
        }
        for(int i = 0; i < words.size() - 1; i++){
            string w1 = words[i];
            string w2 = words[i+1];
            for(int j = 0; j < min(w1.length(), w2.length()); j++){
                if(w1[j] != w2[j]){
                    graph[w1[j]].push_back(w2[j]);
                    inDegree[w2[j]]++;
                    break;
                }
            }
        }
        queue<char> sources;
        for(auto entry : inDegree){
            if(entry.second == 0){
                sources.push(entry.first);
            }
        }
        while(!sources.empty()){
            char parent = sources.front();
            sources.pop();
            wordOrder += parent;
            vector<char> children = graph[parent];
            for(auto child : children){
                inDegree[child]--;
                if(inDegree[child] == 0){
                    sources.push(child);
                }
            }
        }
        return (wordOrder.length() == graph.size()) ? wordOrder : "";
    }
};

int main(){
    vector<string> words = {"ba", "bc", "ac", "cab"};
    cout << AlienDictionary::getOrder(words) << endl;
    words = {"cab", "aaa", "aab"};
    cout << AlienDictionary::getOrder(words) << endl;
    words = {"ywx", "wz", "xww", "xz", "zyy", "zwz"};
    cout << AlienDictionary::getOrder(words) << endl;
    return 0;
}
