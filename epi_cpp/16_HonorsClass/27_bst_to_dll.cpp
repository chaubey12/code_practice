#include <iostream>
#include <vector>
#include <memory>

using namespace std;

template <typename T>
struct BSTNode{
    T data;
    shared_ptr<BSTNode<T>> left, right;
};

struct HeadAndTail{
    shared_ptr<BSTNode<int>> head, tail;
};

HeadAndTail BSTToDoublyLinkedListHelper(const shared_ptr<BSTNode<int>>& tree){
    if(!tree){
        return {nullptr, nullptr};
    }
    HeadAndTail left = BSTToDoublyLinkedListHelper(tree->left);
    HeadAndTail right = BSTToDoublyLinkedListHelper(tree->right);

    if(left.tail){
        left.tail->right = tree;
    }

    tree->left = left.tail;

    tree->right = right.head;
    if(right.head){
        right.head->left = tree;
    }
    return {left.head ? left.head : tree, right.tail ? right.tail : tree};
}

shared_ptr<BSTNode<int>> BSTToDoublyLinkedList(const shared_ptr<BSTNode<int>>& tree){
    return BSTToDoublyLinkedListHelper(tree).head;
}

int main(){
    return 0;
}