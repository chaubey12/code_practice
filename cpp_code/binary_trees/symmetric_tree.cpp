#include <iostream>

using namespace std;

template <typename T>
struct BinaryTreeNode{
    T data;
    unique_ptr<BinaryTreeNode<T>> left, right;
};

bool CheckSymmetric(const unique_ptr<BinaryTreeNode<int>>& subtree_0,
                     const unique_ptr<BinaryTreeNode<int>>& subtree_1){
        if(subtree_0 == nullptr && subtree_1 == nullptr){
            return true;
        }
        else if(subtree_0 != nullptr && subtree_1 != nullptr){
            return subtree_0->data == subtree_1->data && 
            CheckSymmetric(subtree_0->left, subtree_1->right) &&
            CheckSymmetric(subtree_0->right, subtree_1->left);
        }
        return false;
}

bool IsSymmetric(const unique_ptr<BinaryTreeNode<int>>& tree){
    return tree == nullptr || CheckSymmetric(tree->left, tree->right);
}