#include <iostream>

using namespace std;

template <typename T>
struct BinaryTreeNode{
    T data;
    unique_ptr<BinaryTreeNode<int>> left, right;
};

struct Status{
    int num_target_nodes;
    BinaryTreeNode<int>* ancestor;
};

Status LCAHelper(const unique_ptr<BinaryTreeNode<int>>& tree,
                 const unique_ptr<BinaryTreeNode<int>>& node0,
                 const unique_ptr<BinaryTreeNode<int>>& node1){
    if(tree == nullptr){
        return {0, nullptr};
    }
    auto left_result = LCAHelper(tree->left, node0, node1);
    if(left_result.num_target_nodes == 2){
        return left_result;
    }
    auto right_result = LCAHelper(tree->right, node0, node1);
    if(right_result.num_target_nodes == 2){
        return right_result;
    }
    int num_target_nodes = left_result.num_target_nodes + right_result.num_target_nodes + 
    (tree == node1) + (tree == node0);
    return {num_target_nodes, num_target_nodes == 2 ? tree.get() : nullptr};
}


BinaryTreeNode<int>* LCA(const unique_ptr<BinaryTreeNode<int>>& tree,
                         const unique_ptr<BinaryTreeNode<int>>& node0,
                         const unique_ptr<BinaryTreeNode<int>>& node1){
    return LCAHelper(tree, node0, node1).ancestor;
}