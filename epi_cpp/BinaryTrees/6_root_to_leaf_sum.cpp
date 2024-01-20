#include <iostream>
#include <memory>

using namespace std;

template <typename T>
struct BinaryTreeNode{
    T data;
    unique_ptr<BinaryTreeNode<T>> left, right;
};
int SumRootToLeafHelper(const unique_ptr<BinaryTreeNode<int>>& tree, int partial_path_sum){
    if(tree == nullptr){
        return 0;
    }
    partial_path_sum = partial_path_sum*2 + tree->data;
    if(tree->left == nullptr && tree->right == nullptr){
        return partial_path_sum;
    }
    return SumRootToLeafHelper(tree->left, partial_path_sum) + SumRootToLeafHelper(tree->right, partial_path_sum);
}


int SumRootToLeaf(const unique_ptr<BinaryTreeNode<int>>& tree){
    return SumRootToLeafHelper(tree, 0);
}

int main(){
    unique_ptr<BinaryTreeNode<int>> tree = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{1});
    tree->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{0});
    tree->left->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{0});
    tree->left->left->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{0});
    tree->left->left->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{1});
    tree->left->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{1});
    tree->left->right->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{1});
    tree->left->right->right->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{0});

    tree->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{1});
    tree->right->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{0});
    tree->right->left->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{0});
    tree->right->left->right->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{0});
    tree->right->left->right->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{1});
    tree->right->left->right->left->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{1});
    cout << "Sum of root to leaf path :"<<SumRootToLeaf(tree)<<endl;
    return 0;
}