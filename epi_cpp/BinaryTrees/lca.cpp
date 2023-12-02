#include <iostream>
#include <memory>

using namespace std;

template <typename T>
struct BinaryTreeNode{
    T data;
    unique_ptr<BinaryTreeNode<T>> left, right;
};

struct Status{
    int num_target_nodes;
    BinaryTreeNode<int>* ancestor;
};

Status LCAHelper(const unique_ptr<BinaryTreeNode<int>>& tree,
                 const unique_ptr<BinaryTreeNode<int>>& node1,
                 const unique_ptr<BinaryTreeNode<int>>& node2){
    if(tree == nullptr){
        return {0, nullptr};
    }
    auto left_result = LCAHelper(tree->left, node1, node2);
    if(left_result.num_target_nodes == 2){
        return left_result;
    }
    auto right_result = LCAHelper(tree->right, node1, node2);
    if(right_result.num_target_nodes == 2){
        return right_result;
    }
    int num_target_nodes = left_result.num_target_nodes + right_result.num_target_nodes + (tree == node1) + (tree == node2);
    return {num_target_nodes, (num_target_nodes == 2) ? tree.get() : nullptr};
}

BinaryTreeNode<int>* LCA(const unique_ptr<BinaryTreeNode<int>>& tree,
                                    const unique_ptr<BinaryTreeNode<int>>& node1,
                                    const unique_ptr<BinaryTreeNode<int>>& node2){
    return LCAHelper(tree, node1, node2).ancestor;
}

int main(){
    unique_ptr<BinaryTreeNode<int>> tree = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{0});
    tree->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{1});
    tree->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{2});
    tree->left->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{3});
    tree->left->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{4});
    tree->right->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{5});
    tree->right->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{6});
    auto result = LCA(tree, tree->left->left, tree->left->right);
    cout << "LCA Node is : " << result->data << endl;
    return 0;
}