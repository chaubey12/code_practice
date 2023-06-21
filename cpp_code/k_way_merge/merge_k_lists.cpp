#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class ListNode{
public: 
    int value=0;
    ListNode* next;
    ListNode(int value){
        this->value = value;
        this->next = nullptr;
    }
};

class MergeKLists{
public:
    struct valueCompare{
        bool operator()(const ListNode* a, const ListNode* b){
            return a->value > b->value;
        }
    };

    static ListNode* merge(vector<ListNode*> lists){
        priority_queue<ListNode*, vector<ListNode*>, valueCompare> minHeap;
        for(auto root : lists){
            minHeap.push(root);
        }
        ListNode* resultHead = nullptr, *resultTail = nullptr;
        while(!minHeap.empty()){
            auto node = minHeap.top();
            minHeap.pop();
            if(resultHead == nullptr){
                resultHead = resultTail = node;
            }else{
                resultTail->next = node;
                resultTail = resultTail->next;
            }
            if(node->next != nullptr){
                minHeap.push(node->next);
            }
        }
        return resultHead;
    } 
};

int main(){
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(5);
    l1->next->next = new ListNode(9);
    ListNode* l2 = new ListNode(2);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(10);
    ListNode* l3 = new ListNode(3);
    l2->next = new ListNode(7);
    l2->next->next = new ListNode(11);
    vector<ListNode*> l_arr = {l1, l2, l3};
    auto list = MergeKLists::merge(l_arr);
    while(list != nullptr){
        cout << list->value << " ";
        list = list->next;
    }
    cout << endl;

    return 0;
}