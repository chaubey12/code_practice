#include <iostream>
#include <vector>
#include <memory>
#include <limits>
#include <array>

using namespace std;

struct TreeNode{
    struct Edge{
        const unique_ptr<TreeNode>& root;
        double length;
    };
    vector<Edge> edges;
};

struct HeightAndDiameter{
    double height, diameter;
};

HeightAndDiameter ComputeHeightAndDiameter(const unique_ptr<TreeNode>& r){
    double diameter = numeric_limits<double>::min();
    array<double, 2> heights = {{0.0, 0.0}};
    for(const auto& e : r->edges){
        HeightAndDiameter h_d = ComputeHeightAndDiameter(e.root);
        if(h_d.height + e.length > heights[0]){
            heights[1] = heights[0];
            heights[0] = h_d.height + e.length;
        }else if(h_d.height + e.length > heights[1]){
            heights[1] = h_d.height + e.length; 
        }
        diameter = max(diameter, h_d.diameter);
    }
    return {heights[0], max(diameter, heights[0] + heights[1])};
}

double ComputeDiameter(const unique_ptr<TreeNode>& T){
    return T ? ComputeHeightAndDiameter(T).diameter : 0.0;
}

int main(){
    auto A = make_unique<TreeNode>(TreeNode());
    auto B = make_unique<TreeNode>(TreeNode());
    auto C = make_unique<TreeNode>(TreeNode());
    auto D = make_unique<TreeNode>(TreeNode());
    auto E = make_unique<TreeNode>(TreeNode());
    D->edges.emplace_back(TreeNode::Edge{E, 8});

    return 0;
}