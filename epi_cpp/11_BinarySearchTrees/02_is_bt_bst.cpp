#include <iostream>
#include <vector>
#include <memory>
#include <limits>

using namespace std;

template<typename T>
struct BSTNode{
    T data;
    unique_ptr<BSTNode<T>> left_, right_;
};

bool AreKeysInRange(const unique_ptr<BSTNode<int>>& tree, int low_range, int high_range){
    if(tree == nullptr){
        return true;
    }else if(tree->data < low_range || tree->data > high_range){
        return false;
    }
    return AreKeysInRange(tree->left_, low_range, tree->data) && AreKeysInRange(tree->right_, tree->data, high_range);
}

bool IsBinaryTreeBST(const unique_ptr<BSTNode<int>>& tree){
    return AreKeysInRange(tree, numeric_limits<int>::min(), numeric_limits<int>::max());
}

int main(){
    auto tree = make_unique<BSTNode<int>>(BSTNode<int>{19});
    tree->left_ = make_unique<BSTNode<int>>(BSTNode<int>{7});
    tree->left_->left_ = make_unique<BSTNode<int>>(BSTNode<int>{3});
    tree->left_->left_->left_ = make_unique<BSTNode<int>>(BSTNode<int>{2});
    tree->left_->left_->right_ = make_unique<BSTNode<int>>(BSTNode<int>{5});
    tree->left_->right_ = make_unique<BSTNode<int>>(BSTNode<int>{11});
    tree->left_->right_->right_ = make_unique<BSTNode<int>>(BSTNode<int>{17});
    tree->left_->right_->right_->left_ = make_unique<BSTNode<int>>(BSTNode<int>{13});
    tree->right_ = make_unique<BSTNode<int>>(BSTNode<int>{43});
    tree->right_->right_ = make_unique<BSTNode<int>>(BSTNode<int>{47});
    tree->right_->left_ = make_unique<BSTNode<int>>(BSTNode<int>{23});
    tree->right_->left_->right_ = make_unique<BSTNode<int>>(BSTNode<int>{37});
    tree->right_->left_->right_->right_ = make_unique<BSTNode<int>>(BSTNode<int>{41});
    tree->right_->left_->right_->left_ = make_unique<BSTNode<int>>(BSTNode<int>{29});
    tree->right_->left_->right_->left_->right_ = make_unique<BSTNode<int>>(BSTNode<int>{31});
    if(IsBinaryTreeBST(tree)){
        cout << "BT IS BST"<<endl;
    }else{
        cout << "BT IS NOT BST"<<endl;
    }
    return 0;
}