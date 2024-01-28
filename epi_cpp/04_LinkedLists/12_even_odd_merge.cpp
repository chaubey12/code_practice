#include <iostream>
#include <memory>
#include <array>

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

shared_ptr<ListNode<int>> EvenOddMerge(shared_ptr<ListNode<int>>& L){
    if(L == nullptr){
        return L;
    }
    auto even_dummy_head = make_shared<ListNode<int>>(ListNode<int>{0, nullptr});
    auto odd_dummy_head = make_shared<ListNode<int>>(ListNode<int>{0, nullptr});
    array<shared_ptr<ListNode<int>>, 2> tails = {even_dummy_head, odd_dummy_head};
    int turn = 0;
    for(auto iter = L; iter; iter = iter->next){
        tails[turn]->next = iter;
        tails[turn] = tails[turn]->next;
        turn ^= 1;
    }
    tails[1]->next = nullptr;
    tails[0]->next = odd_dummy_head->next;
    return even_dummy_head->next;
}

int main(){
    shared_ptr<ListNode<int>> L1 = make_shared<ListNode<int>>(ListNode<int>{0, nullptr});
    auto temp = L1;
    for(int i=1; i <= 10; ++i){
        temp->next = make_shared<ListNode<int>>(ListNode<int>{i, nullptr});
        temp = temp->next;
    }
    PrintList(L1);
    L1 = EvenOddMerge(L1);
    PrintList(L1);
    return 0;
}