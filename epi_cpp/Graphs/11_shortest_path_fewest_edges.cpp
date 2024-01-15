#include <iostream>
#include <memory>
#include <vector>
#include <limits>
#include <set>

using namespace std;

struct GraphVertex{
    int id;
    GraphVertex* prev = nullptr;
    struct VertexWithDistance{
        GraphVertex& vertex;
        int distance;
    };
    struct DistanceWithFewestEdges{
        int distance, min_num_edges;
    };
    DistanceWithFewestEdges distance_with_fewest_edges = DistanceWithFewestEdges{numeric_limits<int>::max(), 0};
    vector<VertexWithDistance> edges; 
};

struct Comp{
    bool operator()(const GraphVertex* lhs, const GraphVertex* rhs){
        return lhs->distance_with_fewest_edges.distance < 
               rhs->distance_with_fewest_edges.distance ||
               (lhs->distance_with_fewest_edges.distance == rhs->distance_with_fewest_edges.distance &&
               lhs->distance_with_fewest_edges.min_num_edges < rhs->distance_with_fewest_edges.min_num_edges);
    }
};

void OutputShortestPath(const GraphVertex* v){
    if(v){
        OutputShortestPath(v->prev);
        cout << v->id << " ";
    }
}

void DijkstraShortestPath(GraphVertex* s, GraphVertex* t){
    s->distance_with_fewest_edges = {0, 0};
    set<GraphVertex*, Comp> node_set;
    node_set.emplace(s);
    while(!node_set.empty()){
        GraphVertex * u = *node_set.cbegin();
        if(u->id == t->id){
            break;
        }
        node_set.erase(node_set.cbegin());
        for(const GraphVertex::VertexWithDistance& v : u->edges){
            int v_distance = u->distance_with_fewest_edges.distance + v.distance;
            int v_min_edges = u->distance_with_fewest_edges.min_num_edges + 1;
            if(v_distance < v.vertex.distance_with_fewest_edges.distance ||
               (v_distance == v.vertex.distance_with_fewest_edges.distance &&
                v_min_edges < v.vertex.distance_with_fewest_edges.min_num_edges)){
                    node_set.erase(&v.vertex);
                    v.vertex.prev = u;
                    v.vertex.distance_with_fewest_edges = {v_distance, v_min_edges};
                    node_set.emplace(&v.vertex);
            }
        }
    }
    OutputShortestPath(t);
}

int main(){
    return 0;
}