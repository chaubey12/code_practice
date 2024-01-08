#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
struct BinaryTreeNode{
    T data;
    unique_ptr<BinaryTreeNode<T>> left, right;
};

unique_ptr<BinaryTreeNode<int>> Clone(const unique_ptr<BinaryTreeNode<int>>& tree){
    return tree ? make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{0, Clone(tree->left), Clone(tree->right)})
                : nullptr;
}

vector<unique_ptr<BinaryTreeNode<int>>> GenerateAllBinaryTrees(int num_nodes){
    vector<unique_ptr<BinaryTreeNode<int>>> result;
    if(num_nodes == 0){
        result.emplace_back(nullptr);
    }
    for(int num_left_tree_nodes=0; num_left_tree_nodes < num_nodes; ++num_left_tree_nodes){
        int num_right_tree_nodes = num_nodes - 1 - num_left_tree_nodes;
        auto left_subtrees = GenerateAllBinaryTrees(num_left_tree_nodes);
        auto right_subtrees = GenerateAllBinaryTrees(num_right_tree_nodes);
        for(auto& left : left_subtrees){
            for(auto& right : right_subtrees){
                result.emplace_back(make_unique<BinaryTreeNode<int>>(
                    BinaryTreeNode<int>{0, }
                ));           
            }
        }
    }
    return result;
}

int main(){
    return 0;
}