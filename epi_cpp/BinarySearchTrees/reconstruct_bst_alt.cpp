#include <iostream>
#include <vector>
#include <memory>
#include <limits>

using namespace std;

template <typename T>
struct BSTNode{
    T data;
    unique_ptr<BSTNode<T>> left_, right_;
};

void Preorder(const unique_ptr<BSTNode<int>>& tree, vector<int>& preorder_sequence){
    if(tree != nullptr){
        preorder_sequence.emplace_back(tree->data);
        Preorder(tree->left_, preorder_sequence);
        Preorder(tree->right_, preorder_sequence);
    }
}

unique_ptr<BSTNode<int>> RebuildBSTFromPreorderOnValueRange(const vector<int>& preorder_sequence, int lower_bound,
    int upper_bound, int* root_idx_pointer){
    int& root_idx = *root_idx_pointer;
    if(root_idx == preorder_sequence.size()){
        return nullptr;
    }
    int root = preorder_sequence[root_idx];
    if(root < lower_bound || root > upper_bound){
        return nullptr;
    }
    ++root_idx;
    auto left_subtree = RebuildBSTFromPreorderOnValueRange(preorder_sequence, lower_bound, root, root_idx_pointer);
    auto right_subtree = RebuildBSTFromPreorderOnValueRange(preorder_sequence, root, upper_bound, root_idx_pointer);
    return make_unique<BSTNode<int>>(BSTNode<int>{root, move(left_subtree), move(right_subtree)});
}


unique_ptr<BSTNode<int>> RebuildBSTFromPreorder(const vector<int>& preorder_sequence){
    int root_idx = 0;
    return RebuildBSTFromPreorderOnValueRange(preorder_sequence, numeric_limits<int>::min(), numeric_limits<int>::max(), &root_idx);
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
    vector<int> preorder_sequence;
    Preorder(tree, preorder_sequence);
    for(auto elem : preorder_sequence){
        cout << elem << " ";
    }
    cout << endl;
    auto tree_rc = RebuildBSTFromPreorder(preorder_sequence);
    vector<int> preorder_recon;
    Preorder(tree_rc, preorder_recon);
    for(auto elem : preorder_recon){
        cout << elem << " ";
    }
    cout << endl;
    return 0;
}