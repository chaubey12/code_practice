#include <iostream>
#include <memory>

using namespace std;

template<typename T>
struct ListNode{
    T data;
    shared_ptr<ListNode<T>> next;
};

int Length(shared_ptr<ListNode<int>> L){
    int length = 0;
    while(L){
        ++length;
        L = L->next;
    }
    return length;
}

void AdvanceListByK(int k, shared_ptr<ListNode<int>>* L){
    while(k--){
        *L = (*L)->next;
    }
}

shared_ptr<ListNode<int>> OverlappingNoCycleLists(shared_ptr<ListNode<int>>& L1,
                                                  shared_ptr<ListNode<int>>& L2){
    int L1_len = Length(L1);
    int L2_len = Length(L2);
    AdvanceListByK(abs(L1_len - L2_len), (L1_len > L2_len) ? &L1: &L2);
    while((L1 && L2) && (L1 != L2)){
        L1 = L1->next;
        L2 = L2->next;
    }
    return L1;
}

shared_ptr<ListNode<int>> HasCycle(shared_ptr<ListNode<int>>& head){
    shared_ptr<ListNode<int>> fast = head, slow = head;
    while (fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            int cycle_len=0;
            do{
                ++cycle_len;
                fast = fast->next;
            }while(slow != fast);
            auto cycle_len_advanced_iter = head;
            while(cycle_len--){
                cycle_len_advanced_iter = cycle_len_advanced_iter->next;
            }
            auto iter = head;
            while(iter != cycle_len_advanced_iter){
                iter = iter->next;
                cycle_len_advanced_iter = cycle_len_advanced_iter->next;
            }
            return iter;
        }
    }
    return nullptr;
}

int Distance(shared_ptr<ListNode<int>> a, shared_ptr<ListNode<int>> b){
    int dis=0;
    while(a != b){
        a = a->next;
        ++dis;
    }
    return dis;
}

shared_ptr<ListNode<int>> OverlappingLists(shared_ptr<ListNode<int>> L1,
                                           shared_ptr<ListNode<int>> L2){
    auto root1 = HasCycle(L1), root2 = HasCycle(L2);
    if(!root1 && !root2){
        return OverlappingNoCycleLists(L1, L2);
    }else if((root1 && !root2) || (!root1 && root2)){
        return nullptr;
    }
    auto temp = root2;
    do{
        temp = temp->next;
    }while(temp != root1 && temp != root2);
    if(temp != root1){
        return nullptr;
    }
    int stem1_length = Distance(L1, root1), stem2_length = Distance(L2, root2);
    AdvanceListByK(abs(stem1_length - stem2_length), stem1_length > stem2_length ? &L1 : &L2);
    while((L1 != L2) && (L1 != root1) && (L2 != root2)){
        L1 = L1->next, L2 = L2->next;
    }
    return L1 == L2 ? L1 : root1;
}

int main(){
    return 0;
}