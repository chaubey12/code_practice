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

void AppendNode(shared_ptr<ListNode<int>>* node, shared_ptr<ListNode<int>>* tail){
    (*tail)->next = *node;
    *tail = *node;
    *node = (*node)->next;
}

shared_ptr<ListNode<int>> ListPivoting(const shared_ptr<ListNode<int>>& L, int x){
    shared_ptr<ListNode<int>> less_head(new ListNode<int>), equal_head(new ListNode<int>), greater_head(new ListNode<int>);
    shared_ptr<ListNode<int>> less_iter = less_head, equal_iter = equal_head, greater_iter = greater_head;
    shared_ptr<ListNode<int>> iter = L;
    while(iter){
        AppendNode(&iter, iter->data < x ? &less_iter : (iter->data == x ? &equal_iter : &greater_iter));
    }
    greater_iter->next = nullptr;
    equal_iter->next = greater_head->next;
    less_iter->next = equal_head->next;
    return less_head->next;
}

int main(){
    shared_ptr<ListNode<int>> L = make_shared<ListNode<int>>(ListNode<int>{5, nullptr});
    L->next = make_shared<ListNode<int>>(ListNode<int>{8, nullptr});
    L->next->next = make_shared<ListNode<int>>(ListNode<int>{6, nullptr});
    L->next->next->next = make_shared<ListNode<int>>(ListNode<int>{2, nullptr});
    L->next->next->next->next = make_shared<ListNode<int>>(ListNode<int>{4, nullptr});
    L->next->next->next->next->next = make_shared<ListNode<int>>(ListNode<int>{1, nullptr});
    PrintList(L);
    ListPivoting(L, 6);
    PrintList(L);
    return 0;
}