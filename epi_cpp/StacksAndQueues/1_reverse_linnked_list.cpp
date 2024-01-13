#include <iostream>
#include <memory>
#include <stack>

using namespace std;

template<typename T>
struct ListNode{
    T data;
    shared_ptr<ListNode<T>> next;
};

void PrintList(shared_ptr<ListNode<int>> head){
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void PrintLinkedListInReverse(shared_ptr<ListNode<int>> head){
    stack<int> nodes;
    while(head){
        nodes.emplace(head->data);
        head = head->next;
    }
    while(!nodes.empty()){
        cout << nodes.top() << " ";
        nodes.pop();
    }
    cout << endl;
}

int main(){
    auto head = make_shared<ListNode<int>>(ListNode<int>{0});
    head->next = make_shared<ListNode<int>>(ListNode<int>{1});
    head->next->next = make_shared<ListNode<int>>(ListNode<int>{2});
    head->next->next->next = make_shared<ListNode<int>>(ListNode<int>{3});
    head->next->next->next->next = make_shared<ListNode<int>>(ListNode<int>{4});
    PrintList(head);
    PrintLinkedListInReverse(head);
    return 0;
}
