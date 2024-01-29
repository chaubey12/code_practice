#include <iostream>
#include <vector>
#include <memory>

using namespace std;

template <typename T>
struct BinaryTreeNode{
    T data;
    shared_ptr<BinaryTreeNode<T>> left, right, next;
};

void PopulateLowerLevelNextField(BinaryTreeNode<int>* start_node){
    auto iter = start_node;
    while (iter){
        iter->left->next = iter->right;
        if(iter->next){
            iter->right->next = iter->next->left;
        }
        iter = iter->next.get();
    }
}

void ConstructRightSibling(BinaryTreeNode<int>* tree){
    auto left_start = tree;
    while(left_start && left_start->left){
        PopulateLowerLevelNextField(left_start);
        left_start = left_start->left.get();
    }
}

int main(){
    shared_ptr<BinaryTreeNode<int>> tree = make_shared<BinaryTreeNode<int>>(BinaryTreeNode<int>{0});
    tree->left = make_shared<BinaryTreeNode<int>>(BinaryTreeNode<int>{1});
    tree->right = make_shared<BinaryTreeNode<int>>(BinaryTreeNode<int>{2});
    tree->left->left = make_shared<BinaryTreeNode<int>>(BinaryTreeNode<int>{3});
    tree->left->right = make_shared<BinaryTreeNode<int>>(BinaryTreeNode<int>{4});
    tree->right->left = make_shared<BinaryTreeNode<int>>(BinaryTreeNode<int>{5});
    tree->right->right = make_shared<BinaryTreeNode<int>>(BinaryTreeNode<int>{6});
    ConstructRightSibling(tree.get());
    return 0;
}