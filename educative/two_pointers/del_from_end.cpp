#include <iostream>
#include <vector>

using namespace std;

struct LinkedListNode{
    int data;
    LinkedListNode *next;
    LinkedListNode(int d){
        data = d;
        next = nullptr;
    }
};

class LinkedList{
public:
    LinkedListNode *head;
    LinkedList(){
        head = nullptr;
    }

    void InsertNodeAtHead(LinkedListNode *node){
        if(head != nullptr){
            node->next = head;
            head = node;
        }else{
            head = node;
        }
    }

    void CreateLinkedList(vector<int> &vec){
        for(int i=vec.size()-1; i >= 0; i--){
            LinkedListNode *node = new LinkedListNode(vec[i]);
            InsertNodeAtHead(node);
        }
    }

    int GetLength(LinkedListNode *h){
        LinkedListNode *temp = head;
        int length = 0;
        while(temp != nullptr){
            ++length;
            temp = temp->next;
        }
        return length;
    }

    LinkedListNode* GetNode(LinkedListNode* h, int pos){
        if(pos != -1){
            int p = 0;
            LinkedListNode *ptr = h;
            while(p < pos){
                ptr = ptr->next;
                p += 1;
            }
            return ptr;
        }
        return h;
    }

    string ToString(){
        string result = "";
        LinkedListNode* temp = head;
        while(temp != nullptr){
            result += to_string(temp->data);
            temp = temp->next;
            if(temp){
                result += ", ";
            }
        }
        result += "";
        return result;
    }
};

void PrintList(LinkedListNode* head){
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

LinkedListNode* RemoveNthLastNode(LinkedListNode *head, int n){
    LinkedListNode* left = head;
    LinkedListNode* right = head;

    for(int i=0; i < n; i++){
        right = right->next;
    }
    if(!right){
        return head->next;
    }

    while(right->next){
        left = left->next;
        right = right->next;
    }
    left->next = left->next->next;
    return head;
}

int main(){
    vector<int> vec = {1,2,3,4,5,6,7,8,9};
    int k=3;
    LinkedList *ll = new LinkedList();
    ll->CreateLinkedList(vec);
    PrintList(ll->head);
    PrintList(RemoveNthLastNode(ll->head, 3));
    return 0;
}