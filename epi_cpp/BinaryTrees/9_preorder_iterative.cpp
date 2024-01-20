#include <iostream>
#include <vector>
#include <memory>
#include <stack>

using namespace std;

template<typename T>
struct BinaryTreeNode{
    T data;
    unique_ptr<BinaryTreeNode<T>> left, right;
};

void Preorder(const unique_ptr<BinaryTreeNode<int>>& tree){
    if(tree){
        cout << tree->data << " ";
        Preorder(tree->left);
        Preorder(tree->right);
    }
}

vector<int> PreorderTraversal(const unique_ptr<BinaryTreeNode<int>>& tree){
    stack<BinaryTreeNode<int>*> path;
    path.emplace(tree.get());
    vector<int> result;
    while(!path.empty()){
        auto curr = path.top();
        path.pop();
        if(curr != nullptr){
            result.emplace_back(curr->data);
            path.emplace(curr->right.get());
            path.emplace(curr->left.get());
        }
    }
    return result;
}

int main(){
    unique_ptr<BinaryTreeNode<int>> tree = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{0});
    tree->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{1});
    tree->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{2});
    tree->left->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{3});
    tree->left->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{4});
    tree->right->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{5});
    tree->right->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{6});
    auto result = PreorderTraversal(tree);
    for(auto item : result){
        cout << item << " ";
    }
    cout << endl;
    Preorder(tree);
    cout << endl;
    return 0;
}