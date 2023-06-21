#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class ListNode{
public:
    int value;
    ListNode* next;
    ListNode(int value){
        this->value = value;
        this->next = nullptr;
    }
};

class MergeKSortedLists{
public:
    struct valueCompare{
        bool operator()(const ListNode* x, const ListNode* y){
            return x->value > y->value;
        }
    };

    static ListNode* merge(const vector<ListNode*>& lists){
        priority_queue<ListNode*, vector<ListNode*>, valueCompare> minHeap;
        for(auto list : lists){
            if(list != nullptr){
                minHeap.push(list);
            }
        }
        ListNode* resultHead = nullptr, *resultTail = nullptr;
        while(!minHeap.empty()){
            ListNode* node = minHeap.top();
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
    return 0;
}