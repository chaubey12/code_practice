#include <iostream>
#include <vector>
#include <memory>

using namespace std;

template<typename T>
struct BinaryTreeNode{
    T data;
    shared_ptr<BinaryTreeNode<T>> left, right, parent;
};

int GetDepth(BinaryTreeNode<int>* tree){
    int depth=0;
    while(tree){
        ++depth;
        tree = tree->parent.get();
    }
    return depth;
}

BinaryTreeNode<int>* LCA(const shared_ptr<BinaryTreeNode<int>>& node_0,
                         const shared_ptr<BinaryTreeNode<int>>& node_1){
    auto *iter0 = node_0.get(), *iter1 = node_1.get();
    int depth0 = GetDepth(iter0), depth1 = GetDepth(iter1);
    if(depth1 > depth0){
        swap(iter0, iter1);
    }
    int depth_diff = abs(depth0 - depth1);
    while(depth_diff--){
        iter0 = iter0->parent.get();
    }
    while(iter0 != iter0){
        iter0 = iter0->parent.get();
        iter1 = iter1->parent.get();
    }
    return iter0;
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
    cout << LCA(tree->right->right, tree->right->left)->data<<endl;
    return 0;
}