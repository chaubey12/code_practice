#include <iostream>
#include <memory>

using namespace std;

template <typename T>
struct ListNode{
    T data;
    shared_ptr<ListNode<int>> next;
};

void PrintList(shared_ptr<ListNode<int>> node){
    while(node){
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

shared_ptr<ListNode<int>> RemoveKthLast(shared_ptr<ListNode<int>>& L, int k){
    auto dummy_head = make_shared<ListNode<int>>(ListNode<int>{0, L});
    auto first = dummy_head->next;
    while(k--){
        first = first->next;
    }
    auto second = dummy_head;
    while(first){
        first = first->next;
        second = second->next;
    }
    second->next = second->next->next;
    return dummy_head->next;
}

int main(){
    shared_ptr<ListNode<int>> L1 = make_shared<ListNode<int>>(ListNode<int>{0, nullptr});
    auto temp = L1;
    for(int i=1; i <= 10; ++i){
        temp->next = make_shared<ListNode<int>>(ListNode<int>{i, nullptr});
        temp = temp->next;
    }
    int k = 3;
    PrintList(L1);
    auto result = RemoveKthLast(L1, k);
    PrintList(result);
    return 0;
}