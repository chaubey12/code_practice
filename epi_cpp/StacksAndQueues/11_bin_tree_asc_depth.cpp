#include <iostream>
#include <vector>
#include <queue>

using namespace std;

template<typename T>
struct BinaryTreeNode{
    T data;
    unique_ptr<BinaryTreeNode<T>> left, right;
};

vector<vector<int>> BinaryTreeDepthOrder(
    const unique_ptr<BinaryTreeNode<int>>& tree
){
    queue<BinaryTreeNode<int>*> processing_nodes;
    processing_nodes.emplace(tree.get());
    int num_nodes_to_process_at_current_level = processing_nodes.size();
    vector<vector<int>> result;
    vector<int> one_level;
    while(!processing_nodes.empty()){
        auto curr = processing_nodes.front();
        processing_nodes.pop();
        -- num_nodes_to_process_at_current_level;
        if(curr){
            one_level.emplace_back(curr->data);
            processing_nodes.emplace(curr->left.get());
            processing_nodes.emplace(curr->right.get());
        }
        if(!num_nodes_to_process_at_current_level){
            num_nodes_to_process_at_current_level = processing_nodes.size();
            if(!one_level.empty()){
                result.emplace_back(move(one_level));
            }
        }
    }
    return result;
}

int main(){
    return 0;
}