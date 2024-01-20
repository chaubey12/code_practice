#include <iostream>
#include <vector>
#include <memory>

using namespace std;

template <typename T>
struct BinaryTreeNode{
    T data;
    shared_ptr<BinaryTreeNode<T>> left, right, parent;
};

void Inorder(const shared_ptr<BinaryTreeNode<int>>& tree){
    if(tree){
        Inorder(tree->left);
        cout << tree->data << " ";
        Inorder(tree->right);
    }
}

vector<int> InorderTraversal(const shared_ptr<BinaryTreeNode<int>>& tree){
    BinaryTreeNode<int>* prev = nullptr, *curr = tree.get();
    vector<int> result;
    while(curr != nullptr){
        BinaryTreeNode<int>* next;
        if(curr->parent.get() == prev){
            if(curr->left != nullptr){
                next = curr->left.get();
            }else{
                result.emplace_back(curr->data);
                next = (curr->right != nullptr)?curr->right.get() : curr->parent.get();
            }
        } else if(curr->left.get() == prev){
            result.emplace_back(curr->data);
            next = (curr->right != nullptr)? curr->right.get() : curr->parent.get();
        }else{
            next = curr->parent.get();
        }
        prev = curr;
        curr = next;
    } 
    return result;
}

int main(){
    shared_ptr<BinaryTreeNode<int>> tree = make_shared<BinaryTreeNode<int>>(BinaryTreeNode<int>{0});
    tree->left = make_shared<BinaryTreeNode<int>>(BinaryTreeNode<int>{1});
    tree->right = make_shared<BinaryTreeNode<int>>(BinaryTreeNode<int>{2});
    tree->left->left = make_shared<BinaryTreeNode<int>>(BinaryTreeNode<int>{3});
    tree->left->right = make_shared<BinaryTreeNode<int>>(BinaryTreeNode<int>{4});
    tree->right->left = make_shared<BinaryTreeNode<int>>(BinaryTreeNode<int>{5});
    tree->right->right = make_shared<BinaryTreeNode<int>>(BinaryTreeNode<int>{6});
    tree->left->parent = tree->right->parent = tree;
    tree->left->left->parent = tree->left->right->parent = tree->left;
    tree->right->left->parent = tree->right->right->parent = tree->right;
    auto result = InorderTraversal(tree);
    for(auto item : result){
        cout << item << " ";
    }
    cout << endl;
    Inorder(tree);
    cout << endl;
    return 0;
}