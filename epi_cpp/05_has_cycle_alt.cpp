#include <iostream>
#include <memory>

using namespace std;

template <typename T>
struct ListNode{
    T data;
    shared_ptr<ListNode<T>> next;
};

shared_ptr<ListNode<int>> HasCycle(shared_ptr<ListNode<int>>& head){
    shared_ptr<ListNode<int>> fast = head, slow = head;
    while(fast && fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return nullptr;
}

int main(){
    shared_ptr<ListNode<int>> L1 = make_shared<ListNode<int>>(ListNode<int>{0, nullptr});
    auto temp = L1;
    for(int i=1; i <= 10; ++i){
        temp->next = make_shared<ListNode<int>>(ListNode<int>{i, nullptr});
        temp = temp->next;
    }
    temp->next = L1->next->next;
    auto result = HasCycle(L1);
    cout << result->data<<endl;
    return 0;
}