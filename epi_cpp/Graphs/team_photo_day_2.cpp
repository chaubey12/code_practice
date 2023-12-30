#include <iostream>
#include <vector>
#include <memory>
#include <stack>

using namespace std;
struct GraphVertex{
    int max_distance = 1;
    bool visited = false;
    vector<GraphVertex*> edges;
};

void DFS(GraphVertex* curr, stack<GraphVertex*>*vertex_order){
    curr->visited = true;
    for(GraphVertex* next : curr->edges){
        if(!next->visited){
            DFS(next, vertex_order);
        }
    }
    vertex_order->emplace(curr);
}


stack<GraphVertex*> BuildTopologicalOrder(vector<GraphVertex> *G){
    stack<GraphVertex*> vertex_order;
    for(auto& g : *G){
        if(!g.visited){
            DFS(&g, &vertex_order);
        }
    }
    return vertex_order;
}

int FindLongestPath(stack<GraphVertex*> *vertex_order){
    int max_distance=0;
    while(!vertex_order->empty()){
        GraphVertex* u = vertex_order->top();
        max_distance = max(max_distance, u->max_distance);
        for(GraphVertex*& v : u->edges){
            v->max_distance = max(v->max_distance, u->max_distance + 1);
        }
        vertex_order->pop();
    }
    return max_distance;
}

int FindLargestNumberOfTeams(vector<GraphVertex>* G){
    stack<GraphVertex*> vertex_order(BuildTopologicalOrder(G));
    return FindLongestPath(&vertex_order);
}


int main(){
    GraphVertex* a = new GraphVertex{};
    GraphVertex* b = new GraphVertex{};
    GraphVertex* c = new GraphVertex{};
    GraphVertex* d = new GraphVertex{};
    GraphVertex* e = new GraphVertex{};
    GraphVertex* f = new GraphVertex{};
    a->edges.emplace_back(b);
    b->edges.emplace_back(c);
    a->edges.emplace_back(c);
    c->edges.emplace_back(f);
    f->edges.emplace_back(a);
    f->edges.emplace_back(e);
    vector<GraphVertex> input_Set = {*a, *b, *c, *d, *e, *e, *f}; 
    cout << FindLargestNumberOfTeams(&input_Set) << endl;
    return 0;
}