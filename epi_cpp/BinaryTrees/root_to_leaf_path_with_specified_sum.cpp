#include <iostream>
#include <memory>

using namespace std;

template <typename T>
struct BinaryTreeNode{
    T data;
    unique_ptr<BinaryTreeNode<T>> left, right;
};

bool HasPathSumHelper(const unique_ptr<BinaryTreeNode<int>>& tree, int partial_path_sum, int target_sum){
    if(tree == nullptr){
        return false;
    }
    partial_path_sum += tree->data;
    if(tree->left == nullptr && tree->right == nullptr){
        return partial_path_sum == target_sum;
    }
    return HasPathSumHelper(tree->left, partial_path_sum, target_sum) || HasPathSumHelper(tree->right, partial_path_sum, target_sum);
}

bool HasPathSum(const unique_ptr<BinaryTreeNode<int>>& tree, int target_sum){
    return HasPathSumHelper(tree, 0, target_sum);
}

int main(){
    unique_ptr<BinaryTreeNode<int>> tree = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{0});
    tree->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{1});
    tree->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{2});
    tree->left->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{3});
    tree->left->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{4});
    tree->right->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{5});
    tree->right->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{6});
    int target_sum = 17;
    if(HasPathSum(tree, target_sum)){
        cout << "HAS PATH WITH SUM "<<target_sum<<endl;
    }else{
        cout << "DOES NOT HAVE PATH WITH SUM "<<target_sum<<endl;
    }
    return 0;
}