#include <iostream>

using namespace std;

template <typename T>
struct BinaryTreeNode{
    T data;
    unique_ptr<BinaryTreeNode<T>> left, right;
    BinaryTreeNode(T value){
        this->data = value;
    }
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
    bool is_balanced = abs(left_result.height - right_result.height) <= 1;
    int height = max(left_result.height, right_result.height) + 1;
    return {is_balanced, height};
}

bool IsBalanced(unique_ptr<BinaryTreeNode<int>>& tree){
    return CheckBalanced(tree).balanced;
}

int main(){
    auto root = make_unique<BinaryTreeNode<int>>(1);
    root->left = make_unique<BinaryTreeNode<int>>(2);
    root->right = make_unique<BinaryTreeNode<int>>(3);
    root->left->left = make_unique<BinaryTreeNode<int>>(4);
    root->left->right = make_unique<BinaryTreeNode<int>>(5);
    root->right->left = make_unique<BinaryTreeNode<int>>(6);
    root->right->right = make_unique<BinaryTreeNode<int>>(7);
    root->right->right->right = make_unique<BinaryTreeNode<int>>(8);
    root->right->right->right->right = make_unique<BinaryTreeNode<int>>(9);
    cout << "The treee is balanced: ";
    if(IsBalanced(root)){
        cout << "TRUE";
    }else{
        cout << "FALSE";
    }
    cout << endl;
    return 0;
}