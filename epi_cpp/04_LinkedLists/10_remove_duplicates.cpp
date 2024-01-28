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

shared_ptr<ListNode<int>> RemoveDuplicates(const shared_ptr<ListNode<int>>& L){
    auto iter = L;
    while(iter){
        auto next_distinct = iter->next;
        while(next_distinct && (next_distinct->data == iter->data)){
            next_distinct = next_distinct->next;
        }
        iter->next = next_distinct;
        iter = next_distinct;
    }
    return L;
}

int main(){
    shared_ptr<ListNode<int>> L1 = make_shared<ListNode<int>>(ListNode<int>{0, nullptr});
    auto temp = L1;
    for(int i=1; i <= 5; ++i){
        temp->next = make_shared<ListNode<int>>(ListNode<int>{i, nullptr});
        temp = temp->next;
        temp->next = make_shared<ListNode<int>>(ListNode<int>{i, nullptr});
        temp = temp->next;
    }
    PrintList(L1);
    RemoveDuplicates(L1);
    PrintList(L1);
    return 0;
}