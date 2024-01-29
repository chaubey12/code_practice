#include <iostream>
#include <memory>

using namespace std;

template <typename T>
struct BinaryTreeNode{
    T data;
    unique_ptr<BinaryTreeNode<T>> left, right;
};

bool CheckSymmetric(const unique_ptr<BinaryTreeNode<int>>& a, const unique_ptr<BinaryTreeNode<int>>& b){
    if(a == nullptr && b == nullptr){
        return true;
    } else if(a != nullptr && b != nullptr){
        return (a->data == b->data) 
            && CheckSymmetric(a->left, b->right) 
            && CheckSymmetric(a->right, b->left);
    }   
    return false; 
}

bool IsSymmetric(const unique_ptr<BinaryTreeNode<int>>& tree){
    return (tree == nullptr || CheckSymmetric(tree->left, tree->right));
}

int main(){
    unique_ptr<BinaryTreeNode<int>> tree = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{0});
    tree->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{1});
    tree->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{1});
    tree->left->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{2});
    tree->left->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{3});
    tree->right->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{3});
    tree->right->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{2});
    if(IsSymmetric(tree)){
        cout << "TREE IS SYMMETRIC"<<endl;
    }else{
        cout << "TREE IS NOT SYMMETRIC"<<endl;
    }
    return 0;
}