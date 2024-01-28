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

shared_ptr<ListNode<int>> CyclicallyRightShiftList(shared_ptr<ListNode<int>> L, int k){
    if(L == nullptr){
        return L;
    }
    auto tail = L;
    int n=1;
    while(tail->next){
        ++n;
        tail = tail->next;
    }
    k %= n;
    if(k == 0){
        return L;
    }
    tail->next = L;
    int steps_to_new_head = n-k;
    auto new_tail = tail;
    while(steps_to_new_head--){
        new_tail = new_tail->next;
    }
    auto new_head = new_tail->next;
    new_tail->next = nullptr;
    return new_head;
}

int main(){
    shared_ptr<ListNode<int>> L1 = make_shared<ListNode<int>>(ListNode<int>{0, nullptr});
    auto temp = L1;
    for(int i=1; i <= 10; ++i){
        temp->next = make_shared<ListNode<int>>(ListNode<int>{i, nullptr});
        temp = temp->next;
    }
    PrintList(L1);
    L1 = CyclicallyRightShiftList(L1, 4);
    PrintList(L1);
    return 0;
}