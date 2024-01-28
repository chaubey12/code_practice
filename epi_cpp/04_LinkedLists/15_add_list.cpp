#include <iostream>
#include <memory>

using namespace std;

template <typename T>
struct ListNode{
    T data;
    shared_ptr<ListNode<T>> next;
};

shared_ptr<ListNode<int>> AddTwoNumbers(shared_ptr<ListNode<int>> L1, shared_ptr<ListNode<int>> L2){
    shared_ptr<ListNode<int>> dummy_head(new ListNode<int>);
    auto place_iter = dummy_head;
    int carry = 0;
    while(L1 || L2){
        int sum = carry;
        if(L1){
            sum += L1->data;
            L1 = L1->next;
        }
        if(L2){
            sum += L2->data;
            L2 = L2->next;
        }
        place_iter->next = make_shared<ListNode<int>>(sum%10, nullptr);
        carry = sum/10;
        place_iter = place_iter->next;
    }
    if(carry){
        place_iter->next = make_shared<ListNode<int>>(ListNode<int>{carry, nullptr});
    }
    return dummy_head->next;
}

int main(){
    return 0;
}