#include <iostream>
#include <vector>
#include <memory>

using namespace std;

template <typename T>
struct BinaryTreeNode{
    T data;
    shared_ptr<BinaryTreeNode<T>> left, right, parent;
};

void Inorder(const shared_ptr<BinaryTreeNode<int>>& tree){
    if(tree){
        Inorder(tree->left);
        cout << tree->data << " ";
        Inorder(tree->right);
    }
}

BinaryTreeNode<int>* FindSuccessor(const shared_ptr<BinaryTreeNode<int>> tree){
    auto *iter = tree.get();
    if(iter->right != nullptr){
        iter = iter->right.get();
        while(iter){
            iter = iter->left.get();
        }
        return iter;
    }
    while(iter->parent != nullptr && iter->parent->right.get() == iter){
        iter = iter->parent.get();
    }
    return iter->parent.get();   
} 


int main(){
    shared_ptr<BinaryTreeNode<int>> tree = make_shared<BinaryTreeNode<int>>(BinaryTreeNode<int>{0});
    tree->left = make_shared<BinaryTreeNode<int>>(BinaryTreeNode<int>{1});
    tree->right = make_shared<BinaryTreeNode<int>>(BinaryTreeNode<int>{2});
    tree->left->left = make_shared<BinaryTreeNode<int>>(BinaryTreeNode<int>{3});
    tree->left->right = make_shared<BinaryTreeNode<int>>(BinaryTreeNode<int>{4});
    tree->right->left = make_shared<BinaryTreeNode<int>>(BinaryTreeNode<int>{5});
    tree->right->right = make_shared<BinaryTreeNode<int>>(BinaryTreeNode<int>{6});
    tree->left->parent = tree->right->parent = tree;
    tree->left->left->parent = tree->left->right->parent = tree->left;
    tree->right->left->parent = tree->right->right->parent = tree->right;
    Inorder(tree);
    cout << endl;
    cout << "Inorder successor of node is "<<FindSuccessor(tree->left->right)->data << endl;
    return 0;
}