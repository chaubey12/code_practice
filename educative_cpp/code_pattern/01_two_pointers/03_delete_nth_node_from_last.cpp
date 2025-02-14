#include <iostream>
#include <vector>

using namespace std;

struct EduLinkedListNode{
    int data;
    EduLinkedListNode *next;
    EduLinkedListNode(int d){
        data = d;
        next = nullptr;
    }
};

class EduLinkedList{
public:
    EduLinkedListNode *head;
    EduLinkedList(){
        head = nullptr;
    }
    void InsertNodeAtHead(EduLinkedListNode *node){
        if(head != nullptr){
            node->next = head;
            head = node;
        }else{
            head = node;
        }
    }
    void CreateLinkedList(vector<int> vec){
        for(int i=vec.size()-1; i >= 0; i--){
            EduLinkedListNode *node = new EduLinkedListNode(vec[i]);
            InsertNodeAtHead(node);
        }
    }

    int GetLength(EduLinkedListNode* h){
        EduLinkedListNode *temp = h;
        int length = 0;
        while(temp != nullptr){
            length += 1;
            temp = temp->next;
        }
        return length;
    }

    EduLinkedListNode* GetNode(EduLinkedListNode *h, int pos){
        if(pos != -1){
            int p = 0;
            EduLinkedListNode *ptr = h;
            while(p < pos){
                ptr = ptr->next;
                p += 1;
            }
            return ptr;
        }
        return h;
    }

    string ToString(){
        string result;
        EduLinkedListNode *temp = head;
        while(temp != nullptr){
            result += to_string(temp->data);
            if(temp != nullptr){
                result += ", ";
            }
        }
        result += "";
        return result;
    }
};

EduLinkedListNode* RemoveNthLastNode(EduLinkedListNode *head, int n){
    EduLinkedListNode *right = head;
    EduLinkedListNode *left = head;
    for(int i=0; i < n; i++){
        right = right->next;
    }
    if(!right){
        return head->next;
    }
    while(right->next){
        right = right->next;
        left = left->next;
    }
    left->next = left->next->next;
    return head;
}