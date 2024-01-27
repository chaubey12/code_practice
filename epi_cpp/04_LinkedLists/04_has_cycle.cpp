#include <iostream>
#include <memory>

using namespace std;

template <typename T>
struct ListNode{
    T data;
    shared_ptr<ListNode<T>> next;
};

shared_ptr<ListNode<int>> HasCycle(const shared_ptr<ListNode<int>>& head){
    shared_ptr<ListNode<int>> fast = head, slow = head;
    while (fast && fast->next){
        slow = slow->next, fast = fast->next->next;
        if(slow == fast){
            int cycle_len = 0;
            do{
                ++cycle_len;
                fast = fast->next;
            }while(slow != fast);
            auto cycle_len_advance_iter = head;
            while(cycle_len--){
                cycle_len_advance_iter = cycle_len_advance_iter->next;
            }
            auto iter = head;
            while(iter != cycle_len_advance_iter){
                iter = iter->next;
                cycle_len_advance_iter = cycle_len_advance_iter->next;
            }
            return iter;
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