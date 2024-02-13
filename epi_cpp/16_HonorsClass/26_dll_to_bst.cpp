#include <iostream>
#include <vector>
#include <memory>

using namespace std;

template <typename T>
struct ListNode{
    T data;
    shared_ptr<ListNode<T>> next, prev;
};

shared_ptr<ListNode<int>> BuildBSTFromSortedDoublyListHelper(
    shared_ptr<ListNode<int>> *L_ref,
    int start, int end){
    if(start >= end){
        return nullptr;
    }
    int mid = start + (end - start)/2;
    auto left = BuildBSTFromSortedDoublyListHelper(L_ref, start, mid);
    auto curr = *L_ref;
    *L_ref = (*L_ref)->next;
    curr->prev = left;
    curr->next = BuildBSTFromSortedDoublyListHelper(L_ref, mid+1, end);
    return curr;
}

shared_ptr<ListNode<int>> BuildBSTFromSortedDoublyList(shared_ptr<ListNode<int>> L, int length){
    return BuildBSTFromSortedDoublyListHelper(&L, 0, length);
}

void PrintList(shared_ptr<ListNode<int>> root){
    shared_ptr<ListNode<int>> prev = nullptr;
    while(root){
        cout << root->data << " ";
        prev = root;
        root = root->next;
    }
    cout << endl<<"Going reverse now"<<endl;
    while(prev){
        cout << prev->data << " ";
        prev = prev->prev;
    }
}

void PrintTree(shared_ptr<ListNode<int>> root){
    if(root){
        PrintTree(root->prev);
        cout << root->data << " ";
        PrintTree(root->next);
    }
}

int main(){
    shared_ptr<ListNode<int>> root = make_shared<ListNode<int>>(ListNode<int>{0, nullptr, nullptr});
    root->next = make_shared<ListNode<int>>(ListNode<int>{1, nullptr, nullptr});
    root->next->prev = root;
    root->next->next = make_shared<ListNode<int>>(ListNode<int>{2, nullptr, nullptr});
    root->next->next->prev = root->next;
    root->next->next->next = make_shared<ListNode<int>>(ListNode<int>{3, nullptr, nullptr});
    root->next->next->next->prev = root->next->next;
    root->next->next->next->next = make_shared<ListNode<int>>(ListNode<int>{4, nullptr, nullptr});
    root->next->next->next->next->prev = root->next->next->next;
    root->next->next->next->next->next = make_shared<ListNode<int>>(ListNode<int>{5, nullptr, nullptr});
    root->next->next->next->next->next->prev = root->next->next->next->next;
    root->next->next->next->next->next->next = make_shared<ListNode<int>>(ListNode<int>{6, nullptr, nullptr});
    root->next->next->next->next->next->next->prev = root->next->next->next->next->next;
    root->next->next->next->next->next->next->next = make_shared<ListNode<int>>(ListNode<int>{7, nullptr, nullptr});
    root->next->next->next->next->next->next->next->prev = root->next->next->next->next->next->next;
    PrintList(root);
    cout << endl;
    auto rootTree = BuildBSTFromSortedDoublyList(root, 8);
    PrintTree(rootTree);
    cout << endl;
    return 0;
}