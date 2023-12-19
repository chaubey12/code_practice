#include <iostream>
#include <vector>
#include <memory>
#include <list>

using namespace std;

template <typename T>
struct BinaryTreeNode{
    T data;
    unique_ptr<BinaryTreeNode<int>> left, right;
};

list<const unique_ptr<BinaryTreeNode<int>>*> CreateListOfLeaves(
    const unique_ptr<BinaryTreeNode<int>>& tree){
    list<const unique_ptr<BinaryTreeNode<int>>*> leaves;
    if(tree != nullptr){
        if(tree->left == nullptr && tree->right == nullptr){
            leaves.emplace_back(&tree);
        }else{
            leaves.splice(leaves.end(), CreateListOfLeaves(tree->left));
            leaves.splice(leaves.end(), CreateListOfLeaves(tree->right));
        }
    }
    return leaves;
}


int main(){
    unique_ptr<BinaryTreeNode<int>> tree = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{0});
    tree->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{1});
    tree->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{2});
    tree->left->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{3});
    tree->left->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{4});
    tree->right->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{5});
    tree->right->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{6});
    auto result = CreateListOfLeaves(tree);
    for(auto item : result){
        cout << (*item)->data << " ";
    }
    cout << endl;
    return 0;
}