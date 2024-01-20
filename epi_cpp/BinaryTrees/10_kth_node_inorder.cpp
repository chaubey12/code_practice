#include <iostream>
#include <vector>
#include <memory>

using namespace std;

template <typename T>
struct BinaryTreeNode{
    T data;
    int size;
    unique_ptr<BinaryTreeNode<T>> left, right;
};

int ComputeSize(const unique_ptr<BinaryTreeNode<int>>& tree){
    if(tree == nullptr){
        return 0;
    }
    if(tree->left == nullptr && tree->right == nullptr){
        tree->size = 1;
    }
    tree->size = 1 + ComputeSize(tree->left) + ComputeSize(tree->right);
    return tree->size;
}

void Inorder(const unique_ptr<BinaryTreeNode<int>>& tree){
    if(tree){
        Inorder(tree->left);
        cout << tree->size << " ";
        Inorder(tree->right);
    }
}

const BinaryTreeNode<int>* FindKthNodeBinaryTreeNode(const unique_ptr<BinaryTreeNode<int>>& tree, int k){
    auto *iter = tree.get();
    while(iter != nullptr){
        int left_size = iter->left ? iter->left->size : 0;
        if(left_size + 1 < k){
            k -= (left_size + 1);
            iter = iter->right.get();
        }else if(left_size == k - 1){
            return iter;
        }else{
            iter = iter->left.get();
        }
    }
    return nullptr;
}

int main(){
    unique_ptr<BinaryTreeNode<int>> tree = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{0});
    tree->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{1});
    tree->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{2});
    tree->left->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{3});
    tree->left->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{4});
    tree->right->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{5});
    tree->right->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{6});
    ComputeSize(tree);
    Inorder(tree);
    cout << endl;
    cout << "Kth node is " << FindKthNodeBinaryTreeNode(tree, 3)->data << endl;
    return 0;
}