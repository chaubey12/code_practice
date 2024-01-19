#include <iostream>
#include <memory>
#include <vector>

using namespace std;

struct Interval{
    int left, right;
};

template <typename T>
struct BSTNode{
    T data;
    unique_ptr<BSTNode<T>> left_, right_;
};

void RangeLookupInBSTHelper(const unique_ptr<BSTNode<int>>& tree, Interval& interval,
    vector<int>* result){
    if(tree == nullptr){
        return;
    }
    if(interval.left <= tree->data && tree->data <= interval.right){
        RangeLookupInBSTHelper(tree->left_, interval, result);
        result->emplace_back(tree->data);
        RangeLookupInBSTHelper(tree->right_, interval, result);
    } else if(interval.left > tree->data){
        RangeLookupInBSTHelper(tree->right_, interval, result);
    } else{
        RangeLookupInBSTHelper(tree->left_, interval, result);
    }
}


vector<int> RangeLookupInBST(const unique_ptr<BSTNode<int>>& tree, Interval& interval){
    vector<int> result;
    RangeLookupInBSTHelper(tree, interval,&result);
    return result;
}

void Inorder(const unique_ptr<BSTNode<int>>& tree){
    if(tree){
        Inorder(tree->left_);
        cout << tree->data << " ";
        Inorder(tree->right_);
    }
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
    Inorder(tree);
    cout << endl;
    Interval interval = Interval{3, 23};
    auto result = RangeLookupInBST(tree, interval);
    for(auto elem : result){
        cout << elem << " ";
    }
    cout << endl;
    return 0;
}