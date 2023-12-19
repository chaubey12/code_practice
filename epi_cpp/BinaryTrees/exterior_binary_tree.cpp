#include <iostream>
#include <vector>
#include <list>
#include <memory>

using namespace std;

template <typename T>
struct BinaryTreeNode{
    T data;
    unique_ptr<BinaryTreeNode<int>> left, right;
};

bool IsLeaf(const unique_ptr<BinaryTreeNode<int>>& node){
    return node->left == nullptr && node->right == nullptr;
}

list<const unique_ptr<BinaryTreeNode<int>>*> LeftBoundaryAndLeaves(const unique_ptr<BinaryTreeNode<int>>& subtree, bool is_boundary){
    list<const unique_ptr<BinaryTreeNode<int>>*> result;
    if(subtree != nullptr){
        if(is_boundary || IsLeaf(subtree)){
            result.emplace_back(&subtree);
        }
        result.splice(result.end(), LeftBoundaryAndLeaves(subtree->left, is_boundary));
        result.splice(result.end(), LeftBoundaryAndLeaves(subtree->right, is_boundary && subtree->left == nullptr));
    }
    return result;
}

list<const unique_ptr<BinaryTreeNode<int>>*> RightBoundaryAndLeaves(const unique_ptr<BinaryTreeNode<int>>& subtree, bool is_boundary){
    list<const unique_ptr<BinaryTreeNode<int>>*> result;
    if(subtree != nullptr){
        result.splice(result.end(), RightBoundaryAndLeaves(subtree->left, is_boundary && subtree->right == nullptr));
        result.splice(result.end(), RightBoundaryAndLeaves(subtree->right, is_boundary));
        if(is_boundary || IsLeaf(subtree)){
            result.emplace_back(&subtree);
        }
    }
    return result;
}

list<const unique_ptr<BinaryTreeNode<int>>*> ExteriorBinaryTree(
    const unique_ptr<BinaryTreeNode<int>>& tree
){
    list<const unique_ptr<BinaryTreeNode<int>>*> exterior;
    if(tree != nullptr){
        exterior.emplace_back(&tree);
        exterior.splice(exterior.end(), LeftBoundaryAndLeaves(tree->left, true));
        exterior.splice(exterior.end(), RightBoundaryAndLeaves(tree->right, true));
    }
    return exterior;
}


int main(){
    unique_ptr<BinaryTreeNode<int>> tree = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{0});
    tree->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{1});
    tree->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{2});
    tree->left->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{3});
    tree->left->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{4});
    tree->right->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{5});
    tree->right->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{6});
    auto result = ExteriorBinaryTree(tree);
    for(auto item : result){
        cout << (*item)->data << " ";
    }
    cout << endl;
    return 0;
}