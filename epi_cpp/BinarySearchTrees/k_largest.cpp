#include <iostream>
#include <vector>
#include <memory>

using namespace std;
template <typename T>
struct BSTNode{
    T data;
    unique_ptr<BSTNode<T>> left_, right_;
};

void FindKLargestInBSTHelper(const unique_ptr<BSTNode<int>>& tree, int k, vector<int>* k_largest_elements){
    if(tree && k_largest_elements->size() < k){
        FindKLargestInBSTHelper(tree->right_, k, k_largest_elements);
        if(k_largest_elements->size() < k){
            k_largest_elements->emplace_back(tree->data);
            FindKLargestInBSTHelper(tree->left_, k, k_largest_elements);
        }
    }
}

vector<int> FindKLargestInBST(const unique_ptr<BSTNode<int>>& tree, int k){
    vector<int> k_largest_elements;
    FindKLargestInBSTHelper(tree, k, &k_largest_elements);
    return k_largest_elements;
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
    int k = 5;
    auto result = FindKLargestInBST(tree, k);
    for(auto elem : result){
        cout << elem << " ";
    }
    cout << endl;
    return 0;
}