#include <iostream>
#include <memory>

using namespace std;

template <typename T>
struct ListNode{
    T data;
    shared_ptr<ListNode<T>> next;
};

void PrintList(shared_ptr<ListNode<int>> L){
    while(L){
        cout << L->data << " ";
        L = L->next;
    }
    cout << endl;
}

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
        place_iter->next = make_shared<ListNode<int>>(ListNode<int>{sum%10, nullptr});
        carry = sum/10;
        place_iter = place_iter->next;
    }
    if(carry){
        place_iter->next = make_shared<ListNode<int>>(ListNode<int>{carry, nullptr});
    }
    return dummy_head->next;
}

int main(){
    shared_ptr<ListNode<int>> L1 = make_shared<ListNode<int>>(ListNode<int>{1, nullptr});
    L1->next = make_shared<ListNode<int>>(ListNode<int>{1, nullptr});
    L1->next->next = make_shared<ListNode<int>>(ListNode<int>{1, nullptr});
    shared_ptr<ListNode<int>> L2 = make_shared<ListNode<int>>(ListNode<int>{3, nullptr});
    L2->next =make_shared<ListNode<int>>(ListNode<int>{0, nullptr});
    PrintList(L1);
    PrintList(L2);
    auto result = AddTwoNumbers(L1, L2);
    PrintList(result);
    return 0;
}