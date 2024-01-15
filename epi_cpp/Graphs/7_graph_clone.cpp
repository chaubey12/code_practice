#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

struct GraphVertex{
    GraphVertex(int val){
        label = val;
    }
    int label;
    bool visited = false;
    vector<GraphVertex*> edges;
};

void DFS(GraphVertex* graph){
    if(graph == nullptr){
        return;
    }
    if(!graph->visited){
        cout << graph->label <<" ";
        graph->visited = true;
        for(GraphVertex* e : graph->edges){
            DFS(e);
        }
    }
}

GraphVertex* CloneGraph(GraphVertex* G){
    if(!G){
        return nullptr;
    }
    unordered_map<GraphVertex*, GraphVertex*> vertex_map;
    queue<GraphVertex*> q;
    q.emplace(G);
    vertex_map.emplace(G, new GraphVertex{G->label});
    while(!q.empty()){
        auto v = q.front();
        q.pop();
        for(GraphVertex* e : v->edges){
            if(vertex_map.find(e) == vertex_map.end()){
                vertex_map.emplace(e, new GraphVertex{e->label});
                q.emplace(e);
            }
            vertex_map[v]->edges.emplace_back(vertex_map[e]);
        }
    }
    return vertex_map[G];
}

int main(){
    GraphVertex *A = new GraphVertex(1);
    GraphVertex *B = new GraphVertex(2);
    GraphVertex *C = new GraphVertex(3);
    GraphVertex *D = new GraphVertex(4);
    GraphVertex *E = new GraphVertex(5);
    A->edges.emplace_back(B);
    A->edges.emplace_back(C);
    A->edges.emplace_back(D);
    C->edges.emplace_back(D);
    D->edges.emplace_back(E);
    E->edges.emplace_back(A);
    auto cloneA = CloneGraph(A);
    DFS(A);
    cout << endl;
    DFS(cloneA);
    cout << endl;
    return 0;
}