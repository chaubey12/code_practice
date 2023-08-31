#include <iostream>

using namespace std;

class Node{
public:
    int value=0;
    Node* next = nullptr;
    Node(int value){
        this->value = value;
        this->next = nullptr;
    }
};

class LinkedList{
public:
    static Node* reverseSublist(Node* head, int p, int q){
        if(p == q){
            return head;
        }
        if(p < 1 || q < 2){
            return head;
        }
        Node* nodeForHead = head;
        Node* nodeForTail = head;
        Node* listHead = head;
        int count = p;
        if(count == 1){
            listHead = nodeForHead;
        }else{
            while(count > 2){
                nodeForHead = nodeForHead->next;
                count--;
            }
            listHead = nodeForHead->next;
        }
        
        Node* listTail = listHead;
        count = p;
        while(count < q){
            listTail = listTail->next;
            count++;
        } 
        nodeForTail = listTail->next;
        listTail->next = nullptr;
        nodeForHead->next = nullptr;
        Node* origHead = listHead;
        listHead = reverse(listHead);
        nodeForHead->next = listHead;
        origHead->next = nodeForTail;
        return head;
    }

    static void printList(Node* head){
        while(head){
            cout << head->value << " ";
            head = head->next;
        }
        cout << endl;
    }
private:
    static Node* reverse(Node* head){
        Node* curr = head;
        Node* prev = nullptr;
        Node* n = nullptr;
        while(curr){
            n = curr->next;
            curr->next = prev;
            prev = curr;
            curr = n;
        }
        return prev;
    }
};

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    LinkedList::printList(LinkedList::reverseSublist(head, 1, 3));
    return 0;
}