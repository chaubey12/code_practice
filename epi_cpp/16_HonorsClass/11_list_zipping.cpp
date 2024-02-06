#include <iostream>
#include <vector>
#include <memory>

using namespace std;

template <typename T>
struct ListNode{
    T data;
    shared_ptr<ListNode<T>> next;
};

void PrintList(shared_ptr<ListNode<int>> node){
    while(node){
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

shared_ptr<ListNode<int>> ReverseLinkedList(shared_ptr<ListNode<int>> L){
    shared_ptr<ListNode<int>> curr = L, prev = nullptr, n;
    while(curr != nullptr){
        n = curr->next;
        curr->next = prev;
        prev = curr;
        curr = n;
    }
    return prev;
}

shared_ptr<ListNode<int>> ZippingLinkedList(const shared_ptr<ListNode<int>>& L){
    if(!L || !L->next){
        return L;
    }
    auto slow = L, fast = L;
    while(fast && fast->next){
        fast=fast->next->next, slow=slow->next;
    }
    auto first_half_head = L,second_half_head = slow->next;
    slow->next = nullptr;
    second_half_head = ReverseLinkedList(second_half_head);
    auto first_half_iter  = first_half_head, second_half_iter = second_half_head;
    while(second_half_iter){
        auto temp = second_half_iter->next;
        second_half_iter->next = first_half_iter->next;
        first_half_iter->next = second_half_iter;
        first_half_iter = first_half_iter->next->next;
        second_half_iter = temp;
    }
    return first_half_head;
}

int main(){
    shared_ptr<ListNode<int>> L = make_shared<ListNode<int>>(ListNode<int>{1, nullptr});
    L->next = make_shared<ListNode<int>>(ListNode<int>{2, nullptr});
    L->next->next = make_shared<ListNode<int>>(ListNode<int>{3, nullptr});
    L->next->next->next = make_shared<ListNode<int>>(ListNode<int>{2, nullptr});
    L->next->next->next->next = make_shared<ListNode<int>>(ListNode<int>{1, nullptr});
    PrintList(L);
    auto result = ZippingLinkedList(L);
    PrintList(result);
    return 0;
}