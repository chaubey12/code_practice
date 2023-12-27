#include <iostream>
#include <vector>
#include <memory>
#include <queue>

using namespace std;

struct GraphVertex{
    int d = -1;
    vector<GraphVertex*> edges;
};

bool BFS(GraphVertex  *s){
    queue<GraphVertex*> q;
    q.emplace(s);
    while(!q.empty()){
        for(GraphVertex*& t : q.front()->edges){
            if(t->d == -1){
                t->d = q.front()->d + 1;
                q.emplace(t);
            }else if(t->d == q.front()->d){
                return false;
            }
        }
        q.pop();
    }
    return true;
}

bool IsAnyPlacementFeasible(vector<GraphVertex> *G){
    for(GraphVertex& v : *G){
        if(v.d == -1){
            v.d = 0;
            if(!BFS(&v)){
                return false;
            }
        }
    }
    return true;
}

int main(){

    return 0;
}