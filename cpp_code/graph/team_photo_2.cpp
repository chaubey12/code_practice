#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct GraphVertex{
    vector<GraphVertex*> edges;
    int max_distance = 1;
    bool visited = false;
};

int FinaMaximumTeamNumber(vector<GraphVertex*> G){
    stack<GraphVertex*> visited_order(BuildTopologicalOrdering(G)); 
    return FindMaxLength(&visited_order);
}

stack<GraphVertex*> BuildTopologicalOrdering(vector<GraphVertex*> G){
    stack<GraphVertex*> visited_order;
    for(auto& g : G){
        if(!g->visited){
            DFS(g, &visited_order);
        }
    }
    return visited_order;
}

void DFS(GraphVertex* cur, stack<GraphVertex*>* visited_order){
    cur->visited = true;
    for(auto& v : cur->edges){
        if(!v->visited){
            DFS(v, visited_order);
        }
    }
    visited_order->emplace(cur);
}

int FindMaxLength(stack<GraphVertex*>* visited_order){
    int max_distance = 0;
    while (!visited_order->empty())
    {
        GraphVertex* u = visited_order->top();
        max_distance = max(max_distance, u->max_distance);
        for(GraphVertex* v : u->edges){
            max_distance = max(max_distance, v->max_distance);
        }
        visited_order->pop();
    }
    return max_distance;
}

int main(){
    return 0;
}