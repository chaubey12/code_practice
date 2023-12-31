#include <iostream>
#include <memory>
#include <vector>

using namespace std;

template <typename T>
struct BSTNode{
    T data;
    unique_ptr<BSTNode<T>> left_, right_;
};

unique_ptr<BSTNode<int>> RebuildBSTFromPreorderHelper(const vector<int>& preorder_sequence, int start, int end){
    if(start >= end){
        return nullptr;
    }
    int transition_point = start + 1;
    while((transition_point < end) && (preorder_sequence[transition_point] < preorder_sequence[start])){
        ++transition_point;
    }
    return make_unique<BSTNode<int>>(
        BSTNode<int>{preorder_sequence[start], 
                     RebuildBSTFromPreorderHelper(preorder_sequence, start+1, transition_point),
                     RebuildBSTFromPreorderHelper(preorder_sequence, transition_point, end)}
    );
}

unique_ptr<BSTNode<int>> RebuildBSTFromPreorder(const vector<int>& preorder_sequence){
    return RebuildBSTFromPreorderHelper(preorder_sequence, 0, preorder_sequence.size());
}

void Preorder(const unique_ptr<BSTNode<int>>& tree, vector<int>& preorder_sequence){
    if(tree != nullptr){
        preorder_sequence.emplace_back(tree->data);
        Preorder(tree->left_, preorder_sequence);
        Preorder(tree->right_, preorder_sequence);
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
    vector<int> preorder_sequence;
    vector<int> preorder_recon;
    Preorder(tree, preorder_sequence);
    for(auto el : preorder_sequence){
        cout << el << " ";
    }
    cout << endl;
    auto tree_rc = RebuildBSTFromPreorder(preorder_sequence);
    Preorder(tree_rc, preorder_recon);
    for(auto el : preorder_recon){
        cout << el << " ";
    }
    cout << endl;
    return 0;
}