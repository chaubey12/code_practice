#include <iostream>
#include <vector>
#include <memory>
#include <stack>

using namespace std;

template <typename T>
struct BinaryTreeNode{
    T data;
    unique_ptr<BinaryTreeNode<T>> left_, right_;
};

vector<int> InvertedPreorderTraversal(const unique_ptr<BinaryTreeNode<int>>& tree){
    stack<BinaryTreeNode<int>*> path;
    path.emplace(tree.get());
    vector<int> result;
    while(!path.empty()){
        auto* curr = path.top();
        path.pop();
        if(curr == nullptr){
            continue;
        }
        result.emplace_back(curr->data);
        path.emplace(curr->left_.get());
        path.emplace(curr->right_.get());
    }
    return result;
}

vector<int> PostOrderTraversal(const unique_ptr<BinaryTreeNode<int>>& tree){
    vector<int> sequence = InvertedPreorderTraversal(tree);
    reverse(sequence.begin(), sequence.end());
    return sequence;
}

int main(){
    unique_ptr<BinaryTreeNode<int>> tree = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{0});
    tree->left_ = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{1});
    tree->right_ = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{2});
    tree->left_->left_ = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{3});
    tree->left_->right_ = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{4});
    tree->right_->left_ = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{5});
    tree->right_->right_ = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{6});
    auto result = InvertedPreorderTraversal(tree);
    for(auto item : result){
        cout << item << " ";
    }
    cout << endl;
    result = PostOrderTraversal(tree);
    for(auto item : result){
        cout << item << " ";
    }
    cout << endl;
    return 0;
}