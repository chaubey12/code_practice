#include <iostream>
#include <memory>

using namespace std;

template <typename T>
struct BinaryTreeNode{
    T data;
    unique_ptr<BinaryTreeNode<T>> left, right;
    BinaryTreeNode(T val){
        data = val;
    }
};

void TreeTraversal(const unique_ptr<BinaryTreeNode<int>>& root){
    if(root){
        cout << "Preorder: " << root->data << endl;
        TreeTraversal(root->left);
        cout << "Inorder: " << root->data << endl;
        TreeTraversal(root->right);
        cout << "Postorder: " << root->data << endl;
    }
}

int main(){
    unique_ptr<BinaryTreeNode<int>> root = make_unique<BinaryTreeNode<int>>(1);
    root->left = make_unique<BinaryTreeNode<int>>(2);
    root->right = make_unique<BinaryTreeNode<int>>(3);
    root->left->left = make_unique<BinaryTreeNode<int>>(4);
    root->left->right = make_unique<BinaryTreeNode<int>>(5);
    root->right->left = make_unique<BinaryTreeNode<int>>(6);
    root->right->right = make_unique<BinaryTreeNode<int>>(7);
    TreeTraversal(root);
    return 0;
}