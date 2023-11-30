#include <iostream>
#include <memory>

using namespace std;

template <typename T>
struct BinaryTreeNode{
    T data;
    unique_ptr<BinaryTreeNode<T>> left, right;
};

void TreeTraversal(unique_ptr<BinaryTreeNode<int>>& root){
    if(root){
        cout << "Preorder: "<<root->data << endl;
        TreeTraversal(root->left);
        cout << "Inorder: "<<root->data << endl;
        TreeTraversal(root->right);
        cout << "Postrder: "<<root->data << endl;
    }
}

int main(){
    unique_ptr<BinaryTreeNode<int>> tree = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{0});
    tree->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{1});
    tree->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{2});
    tree->left->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{3});
    tree->left->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{4});
    tree->right->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{5});
    tree->right->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{6});
    TreeTraversal(tree);
    return 0;
}