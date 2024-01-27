#include <iostream>
#include <memory>

using namespace std;

template<typename T>
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

void DeletionFromList(const shared_ptr<ListNode<int>>& node_to_delete){
    if(node_to_delete->next){
        node_to_delete->data = node_to_delete->next->data;
        node_to_delete->next = node_to_delete->next->next;
    }
}

int main(){
    shared_ptr<ListNode<int>> L1 = make_shared<ListNode<int>>(ListNode<int>{0, nullptr});
    auto temp = L1;
    for(int i=1; i <= 10; ++i){
        temp->next = make_shared<ListNode<int>>(ListNode<int>{i, nullptr});
        temp = temp->next;
    }
    PrintList(L1);
    DeletionFromList(L1->next->next->next);
    PrintList(L1);
    return 0;
}