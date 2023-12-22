#include <iostream>
#include <vector>
#include <memory>
#include <queue>
#include <limits>

using namespace std;

template <typename T>
struct BSTNode{
    T data;
    unique_ptr<BSTNode<T>> left_, right_;
};

struct QueueEntry{
    const unique_ptr<BSTNode<int>>& tree_node;
    int lower_bound, upper_bound;
};

bool IsBinaryTreeBST(const unique_ptr<BSTNode<int>>& tree){
    queue<QueueEntry> BFS_queue;
    BFS_queue.emplace(QueueEntry{tree, numeric_limits<int>::min(), numeric_limits<int>::max()});
    while(!BFS_queue.empty()){
        if(BFS_queue.front().tree_node.get()){
            if(BFS_queue.front().tree_node->data < BFS_queue.front().lower_bound ||
               BFS_queue.front().tree_node->data > BFS_queue.front().upper_bound){
                return false;
            }
            BFS_queue.emplace(QueueEntry{BFS_queue.front().tree_node->left_, BFS_queue.front().lower_bound, BFS_queue.front().tree_node->data});
            BFS_queue.emplace(QueueEntry{BFS_queue.front().tree_node->right_, BFS_queue.front().tree_node->data, BFS_queue.front().upper_bound});
        }
        BFS_queue.pop();
    }
    return true;
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