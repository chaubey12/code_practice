#include <iostream>
#include <memory>

using namespace std;

template <typename T>
struct ListNode{
    T data;
    shared_ptr<ListNode<int>> next;
};

int Length(shared_ptr<ListNode<int>>& L){
    int length = 0;
    while(L){
        ++length;
        L = L->next;
    }
    return length;
}

void AdvanceListByK(int k, shared_ptr<ListNode<int>>* L){
    while(k--){
        *L = (*L)->next;
    }
}

shared_ptr<ListNode<int>> OverlappingNoCycleLists(shared_ptr<ListNode<int>>& L1,
                                                  shared_ptr<ListNode<int>>& L2){
    int L1_len = Length(L1);
    int L2_len = Length(L2);
    cout << L1->data << endl;
    AdvanceListByK(abs(L1_len - L2_len), L1_len > L2_len ? &L1: &L2);
    while((L1 && L2) && (L1 != L2)){
        L1 = L1->next;
        L2 = L2->next;
    }
    return L1;
}

int main(){
    shared_ptr<ListNode<int>> L1 = make_shared<ListNode<int>>(ListNode<int>{0, nullptr});
    auto temp1 = L1;
    for(int i=1; i <= 10; ++i){
        temp1->next = make_shared<ListNode<int>>(ListNode<int>{i, nullptr});
        temp1 = temp1->next;
    }
    shared_ptr<ListNode<int>> L2 = make_shared<ListNode<int>>(ListNode<int>{10, nullptr});
    auto temp2 = L1;
    for(int i=1; i <= 3; ++i){
        temp2->next = make_shared<ListNode<int>>(ListNode<int>{i, nullptr});
        temp2 = temp2->next;
    }
    temp2->next = L1->next->next->next;
    auto result = OverlappingNoCycleLists(L1, L2);
    cout << result->data << endl;
    return 0;
}