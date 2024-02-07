#include <iostream>
#include <vector>
#include <stack>

using namespace std;

template <typename T>
struct BinaryTreeNode{
    T data;
    unique_ptr<BinaryTreeNode<T>> left_, right_;
};

vector<int> PostOrderTraversal(const unique_ptr<BinaryTreeNode<int>>& tree){
    if(tree == nullptr){
        return {};
    }
    stack<BinaryTreeNode<int>*> path;
    BinaryTreeNode<int>* prev = nullptr;
    path.emplace(tree.get());
    vector<int> postorder_sequence;
    while(!path.empty()){
        auto curr = path.top();
        if(prev == nullptr || prev->left_.get() == curr || prev->right_.get() == curr){
            if(curr->left_ != nullptr){
                path.emplace(curr->left_.get());
            }else if(curr->right_ != nullptr){
                path.emplace(curr->right_.get());
            }else{
                postorder_sequence.emplace_back(curr->data);
                path.pop();
            }
        }else if(curr->left_.get() == prev){
            if(curr->right_.get() != nullptr){
                path.emplace(curr->right_.get());
            }else{
                postorder_sequence.emplace_back(curr->data);
                path.pop();
            }
        }else{
            postorder_sequence.emplace_back(curr->data);
            path.pop();
        }
        prev = curr;
    }
    return postorder_sequence;
}

int main(){
    unique_ptr<BinaryTreeNode<int>> tree = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{0});
    tree->left_ = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{1});
    tree->right_ = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{2});
    tree->left_->left_ = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{3});
    tree->left_->right_ = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{4});
    tree->right_->left_ = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{5});
    tree->right_->right_ = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{6});
    auto result = PostOrderTraversal(tree);
    for(auto item : result){
        cout << item << " ";
    }
    cout << endl;
    return 0;
}