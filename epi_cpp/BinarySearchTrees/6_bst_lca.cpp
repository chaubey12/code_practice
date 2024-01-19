#include <iostream>
#include <memory>
#include <vector>

using namespace std;

template <typename T>
struct BSTNode{
    T data;
    unique_ptr<BSTNode<T>> left_, right_;
};

BSTNode<int>* FindLCA(const unique_ptr<BSTNode<int>>& tree,
                      const unique_ptr<BSTNode<int>>& s,
                      const unique_ptr<BSTNode<int>>& b){
    auto *p = tree.get();
    while(p->data < s->data || p->data > b->data){
        while(p->data < s->data){
            p = p->right_.get();
        }
        while(p->data > b->data){
            p = p->left_.get();
        }
    }
    return p;
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
    cout << FindLCA(tree, tree->right_->left_, tree->right_->right_)->data << endl;
    return 0;
}