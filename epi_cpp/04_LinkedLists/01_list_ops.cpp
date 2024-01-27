#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

template <typename T>
struct ListNode{
    T data;
    shared_ptr<ListNode<T>> next;
};

void PrintList(shared_ptr<ListNode<int>> head){
    auto temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

shared_ptr<ListNode<int>> SearchList(shared_ptr<ListNode<int>> head, int key){
    auto temp = head;
    while(temp && temp->data != key){
        temp = temp->next;
    }
    return temp;
}

void InsertAfter(shared_ptr<ListNode<int>> node, shared_ptr<ListNode<int>> insert_node){
    insert_node->next = node->next;
    node->next = insert_node;
}

void DeleteAfter(shared_ptr<ListNode<int>> node){
    node->next = node->next->next;
}

int main(){
    shared_ptr<ListNode<int>> head = make_shared<ListNode<int>>(ListNode<int>{0, nullptr});
    head->next = make_shared<ListNode<int>>(ListNode<int>{1, nullptr});
    head->next->next = make_shared<ListNode<int>>(ListNode<int>{2, nullptr});
    head->next->next->next = make_shared<ListNode<int>>(ListNode<int>{3, nullptr});
    head->next->next->next->next = make_shared<ListNode<int>>(ListNode<int>{4, nullptr});
    head->next->next->next->next->next = make_shared<ListNode<int>>(ListNode<int>{5, nullptr});
    head->next->next->next->next->next->next = make_shared<ListNode<int>>(ListNode<int>{6, nullptr});
    cout << SearchList(head, 6)->data << " is the data stored " << endl; 
    PrintList(head);
    cout << "Inserting" << endl;
    InsertAfter(head->next->next, make_shared<ListNode<int>>(ListNode<int>{20, nullptr}));
    cout << "After insertion" << endl;
    PrintList(head);
    cout << "Deleting" << endl;
    DeleteAfter(head->next->next);
    cout << "After Deletion"<<endl;
    PrintList(head);
    return 0;
}