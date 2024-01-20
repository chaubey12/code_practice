#include <iostream>
#include <vector>
#include <memory>
#include <stack>

using namespace std;

template <typename T>
struct BinaryTreeNode{
    T data;
    unique_ptr<BinaryTreeNode<T>> left, right;
};

void Inorder(const unique_ptr<BinaryTreeNode<int>>& tree){
    if(tree){
        Inorder(tree->left);
        cout << tree->data << " ";
        Inorder(tree->right);
    }
}

vector<int> InorderTraversal(const unique_ptr<BinaryTreeNode<int>>& tree){
    stack<BinaryTreeNode<int>*> s;
    auto* curr = tree.get();
    vector<int> result;
    while(!s.empty() || curr){
        if(curr){
            s.push(curr);
            curr = curr->left.get();
        }else{
            curr = s.top();
            s.pop();
            result.emplace_back(curr->data);
            curr = curr->right.get();
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
    auto result = InorderTraversal(tree);
    for(auto item : result){
        cout << item << " ";
    }
    cout << endl;
    Inorder(tree);
    cout << endl;
    return 0;
}