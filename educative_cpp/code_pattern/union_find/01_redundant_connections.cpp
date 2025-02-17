#include <iostream>
#include <vector>

using namespace std;

class UnionFind{
public:
    vector<int> parent;
    vector<int> rank;

    UnionFind(int n) : parent(n + 1), rank(n + 1, 1){
        for(int i=0; i <= n; i++){
            parent[i] = i;
        }
    }

    int Find(int v){
        if(parent[v] != v){
            parent[v] = Find(parent[v]);
        }
        return parent[v];
    }

    bool Union(int v1, int v2){
        int p1 = Find(v1);
        int p2 = Find(v2);
        if(p1 == p2){
            return false;
        }else if(rank[p1] > rank[p2]){
            parent[p2] = p1;
            rank[p1] += rank[p2];
        }else{
            parent[p1] = p2;
            rank[p2] += rank[p1];
        }
        return true;
    }
};

vector<int> RedundantConnection(vector<vector<int>> edges){
    UnionFind* connections = new UnionFind(edges.size());
    for(int i=0; i < edges.size(); i++){
        int v1 = edges[i][0];
        int v2 = edges[i][1];
        if(!connections->Union(v1, v2)){
            return {v1, v2};
        }
    }
    return {};
}