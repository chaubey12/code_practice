#include <iostream>

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

void AppendNode(shared_ptr<ListNode<int>>* node, shared_ptr<ListNode<int>>* tail){
    (*tail)->next = *node;
    *tail = *node;
    (*node) = (*node)->next;
}


shared_ptr<ListNode<int>> MergeTwoLists(shared_ptr<ListNode<int>> L1, shared_ptr<ListNode<int>> L2){
    shared_ptr<ListNode<int>> dummy_head(new ListNode<int>());
    auto tail = dummy_head;
    while(L1 && L2){
        AppendNode(L1->data <= L2->data ? &L1 : &L2, &tail);
    }
    return dummy_head->next;
}

int main(){
    shared_ptr<ListNode<int>> L1 = make_shared<ListNode<int>>(ListNode<int>{0, nullptr});
    L1->next = make_shared<ListNode<int>>(ListNode<int>{2, nullptr});
    L1->next->next = make_shared<ListNode<int>>(ListNode<int>{4, nullptr});
    L1->next->next->next = make_shared<ListNode<int>>(ListNode<int>{6, nullptr});
    shared_ptr<ListNode<int>> L2 = make_shared<ListNode<int>>(ListNode<int>{1, nullptr});
    L2->next = make_shared<ListNode<int>>(ListNode<int>{3, nullptr});
    L2->next->next = make_shared<ListNode<int>>(ListNode<int>{5, nullptr});
    L2->next->next->next = make_shared<ListNode<int>>(ListNode<int>{7, nullptr});
    PrintList(L1);
    PrintList(L2);
    PrintList(MergeTwoLists(L1, L2));
    return 0;
}