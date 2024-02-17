#include <iostream>
#include <vector>
#include <memory>

using namespace std;

template <typename T>
struct BSTNode{
    T data;
    shared_ptr<BSTNode<T>> left, right;
};

template <typename T>
struct ListNode{
    T data;
    shared_ptr<ListNode<T>> next, prev;
};

shared_ptr<BSTNode<int>> BuildBSTFromSortedDoublyListHelper(
    shared_ptr<BSTNode<int>> *L_ref,
    int start, int end){
    if(start >= end){
        return nullptr;
    }
    int mid = start + (end - start)/2;
    auto left = BuildBSTFromSortedDoublyListHelper(L_ref, start, mid);
    auto curr = *L_ref;
    *L_ref = (*L_ref)->right;
    curr->left = left;
    curr->right = BuildBSTFromSortedDoublyListHelper(L_ref, mid+1, end);
    return curr;
}

shared_ptr<BSTNode<int>> BuildBSTFromSortedDoublyList(shared_ptr<BSTNode<int>> L, int length){
    return BuildBSTFromSortedDoublyListHelper(&L, 0, length);
}

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

int CountLength(shared_ptr<BSTNode<int>> tree){
    int length = 0;
    while(tree){
        ++length;
        tree = tree->right;
    }
    return length;
}

void AppendNode(shared_ptr<BSTNode<int>>* node, shared_ptr<BSTNode<int>>* tail){
    (*tail)->right = *node;
    (*tail)->right->left = (*tail);
    *tail = *node;
    (*node) = (*node)->right;
}


shared_ptr<BSTNode<int>> MergeTwoSortedLists(shared_ptr<BSTNode<int>> L1, shared_ptr<BSTNode<int>> L2){
    shared_ptr<BSTNode<int>> dummy_head(new BSTNode<int>());
    auto tail = dummy_head;
    while(L1 && L2){
        AppendNode(L1->data <= L2->data ? &L1 : &L2, &tail);
    }
    return dummy_head->right;
}

shared_ptr<BSTNode<int>> MergeTwoBSTs(shared_ptr<BSTNode<int>> A, shared_ptr<BSTNode<int>> B){
    A = BSTToDoublyLinkedList(A), B = BSTToDoublyLinkedList(B);
    int A_length = CountLength(A), B_length = CountLength(B);
    return BuildBSTFromSortedDoublyList(MergeTwoSortedLists(A, B), A_length + B_length);
}


int main(){
    return 0;
}