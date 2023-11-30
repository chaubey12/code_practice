#include <iostream>
#include <memory>

using namespace std;

template <typename T>
struct BinaryTreeNode{
    T data;
    unique_ptr<BinaryTreeNode<T>> left, right;
};

struct BalancedStatusWithHeight{
    bool balanced;
    int height;
};

BalancedStatusWithHeight CheckBalanced(const unique_ptr<BinaryTreeNode<int>>& tree){
    if(tree == nullptr){
        return {true, -1};
    }
    auto left_result = CheckBalanced(tree->left);
    if(!left_result.balanced){
        return {false, 0};
    }
    auto right_result = CheckBalanced(tree->right);
    if(!right_result.balanced){
        return {false, 0};
    }
    int height = max(left_result.height, right_result.height) + 1;
    bool balanced = abs(left_result.height - right_result.height) <= 1;
    return {balanced, height};
}


bool IsBalanced(const unique_ptr<BinaryTreeNode<int>>& tree){
    return CheckBalanced(tree).balanced;
}

int main(){
    unique_ptr<BinaryTreeNode<int>> tree = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{0});
    tree->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{1});
    tree->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{2});
    tree->left->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{3});
    tree->left->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{4});
    tree->right->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{5});
    tree->right->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{6});
    // tree->right->right->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{7});
    // tree->right->right->right->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{8});
    if(IsBalanced(tree)){
        cout << "TREE IS BALANCED"<<endl;
    }else{
        cout << "TREE IS UNBALANCED"<<endl;
    }
    return 0;
}