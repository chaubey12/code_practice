#include <iostream>
#include <memory>

using namespace std;

template<typename T>
struct ListNode{
    T data;
    shared_ptr<ListNode<T>> next;
};

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

bool IsLinkedListPalindrome(shared_ptr<ListNode<int>> L){
    if(L == nullptr){
        return true;
    }
    shared_ptr<ListNode<int>> slow = L, fast = L;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    auto first_half_iter = L, second_half_iter = ReverseLinkedList(slow);
    while(second_half_iter && first_half_iter){
        if(second_half_iter->data != first_half_iter->data){
            return false;
        }
        second_half_iter = second_half_iter->next;
        first_half_iter = first_half_iter->next;
    }
    return true;
}

int main(){
    shared_ptr<ListNode<int>> L = make_shared<ListNode<int>>(ListNode<int>{1, nullptr});
    L->next = make_shared<ListNode<int>>(ListNode<int>{2, nullptr});
    L->next->next = make_shared<ListNode<int>>(ListNode<int>{3, nullptr});
    L->next->next->next = make_shared<ListNode<int>>(ListNode<int>{2, nullptr});
    L->next->next->next->next = make_shared<ListNode<int>>(ListNode<int>{1, nullptr});
    if(IsLinkedListPalindrome(L)){
        cout << "IS PALINDROME"<<endl;
    }else{
        cout << "IS NOT PALINDROME"<<endl;
    }
    return 0;
}