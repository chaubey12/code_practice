#include <iostream>
#include <vector>

using namespace std;

struct GraphVertex{
    enum Color {white, grey, black} color = white;
    vector<GraphVertex*> edges;
};

bool HasCycle(GraphVertex* cur, GraphVertex* prev){
    if(cur->color == GraphVertex::grey){
        return true;
    }
    cur->color = GraphVertex::grey;
    for(GraphVertex*& next : cur->edges){
        if(next != prev && next->color != GraphVertex::black){
            if(HasCycle(next, cur)){
                return true;
            }
        }
    }
    cur->color = GraphVertex::black;
    return false;
}

bool IsDeadlocked(vector<GraphVertex>* G){
    for(GraphVertex& vertex : *G){
        if(vertex.color == GraphVertex::white && HasCycle(&vertex, nullptr)){
            return true;
        }
    }
    return false;
}

int main(){
    GraphVertex* A = new GraphVertex();
    GraphVertex* B = new GraphVertex();
    GraphVertex* C = new GraphVertex();
    GraphVertex* D = new GraphVertex();
    GraphVertex* E = new GraphVertex();
    A->edges.emplace_back(B);
    A->edges.emplace_back(C);
    A->edges.emplace_back(D);
    C->edges.emplace_back(D);
    D->edges.emplace_back(E);
    E->edges.emplace_back(A);
    vector<GraphVertex>V{*A, *B, *C, *D, *E};
    if(IsDeadlocked(&V)){
        cout << "DEADLOCKED"<<endl;
    }else{
        cout << "NOT DEADLOCKED" <<endl;
    }
    return 0;
}