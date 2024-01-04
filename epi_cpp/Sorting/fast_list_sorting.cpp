#include <iostream>
#include <vector>
#include <memory>

using namespace std;

template <typename T>
struct ListNode{
    T data;
    shared_ptr<ListNode<T>> next;
};

shared_ptr<ListNode<int>> InsertionSort(const shared_ptr<ListNode<int>>& L){
    auto dummy_head = make_shared<ListNode<int>>(ListNode<int>{0, L});
    auto iter = L;
    while(iter && iter->next){
        if(iter->data > iter->next->data){
            auto target = iter->next, pre = dummy_head;
            while(pre->next->data < target->data){
                pre = pre->next;
            }
            auto temp = pre->next;
            pre->next = target;
            iter->next = target->next;
            target->next = temp;
        }else{
            iter = iter->next;
        }
    }
    return dummy_head->next;
}

void AppendNode(shared_ptr<ListNode<int>>* node, shared_ptr<ListNode<int>>* tail){
    (*tail)->next = *node;
    *tail = *node;
    *node = (*node)->next;
}

shared_ptr<ListNode<int>> MergeTwoSortedLists(shared_ptr<ListNode<int>> L1, shared_ptr<ListNode<int>> L2){
    shared_ptr<ListNode<int>> dummy_head(new ListNode<int>);
    auto tail = dummy_head;
    while(L1 && L2){
        AppendNode(L1->data < L2->data ? &L1 : &L2, &tail);
    }
    tail->next = L1?L1:L2;
    return dummy_head->next;
}


shared_ptr<ListNode<int>> StableSortList(const shared_ptr<ListNode<int>>& L){
    if(L == nullptr || L->next == nullptr){
        return L;
    }
    shared_ptr<ListNode<int>> pre_slow = nullptr, slow = L, fast = L;
    while(fast && fast->next){
        pre_slow = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    pre_slow->next = nullptr;
    return MergeTwoSortedLists(StableSortList(L), StableSortList(slow));
}

int main(){
    shared_ptr<ListNode<int>> head = make_shared<ListNode<int>>(ListNode<int>{1});
    head->next = make_shared<ListNode<int>>(ListNode<int>{4});
    head->next->next = make_shared<ListNode<int>>(ListNode<int>{3});
    head->next->next->next = make_shared<ListNode<int>>(ListNode<int>{7});
    head->next->next->next->next = make_shared<ListNode<int>>(ListNode<int>{5});
    auto temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    temp = StableSortList(head);
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}