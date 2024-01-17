#include <iostream>
#include <unordered_set>
#include <memory>

using namespace std;

template<typename T>
struct BinaryTreeNode{
    T data;
    BinaryTreeNode<T> *left, *right, *parent;
};

BinaryTreeNode<int>* LCA(BinaryTreeNode<int>* node_0, BinaryTreeNode<int>* node_1){
    auto *iter1 = node_0, *iter2 = node_1;
    unordered_set<BinaryTreeNode<int>*> nodes_on_path_to_root;
    while(iter1 && iter2){
        if(iter1){
            if(nodes_on_path_to_root.emplace(iter1).second == false){
                return iter1;
            }
            iter1 = iter1->parent;
        }
        if(iter2){
            if(nodes_on_path_to_root.emplace(iter2).second == false){
                return iter2;
            }
            iter2 = iter2->parent;
        }
    }
    throw invalid_argument("node_0 and node_1 are not in same tree");
}



int main(){
    auto tree = new BinaryTreeNode<int>{0};
    tree->left = new BinaryTreeNode<int>{1};
    tree->right = new BinaryTreeNode<int>{2};
    tree->left->parent = tree->right->parent = tree;
    tree->left->left = new BinaryTreeNode<int>{3};
    tree->left->right = new BinaryTreeNode<int>{4};
    tree->left->left->parent = tree->left->right->parent = tree->left;
    tree->right->left = new BinaryTreeNode<int>{5};
    tree->right->right = new BinaryTreeNode<int>{6};
    tree->right->left->parent = tree->right->right->parent = tree->right;
    cout <<"LCA is :"<<LCA(tree->right->right, tree->right->left)->data << endl;
    return 0;
}