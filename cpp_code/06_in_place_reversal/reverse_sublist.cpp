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
        if(p >= q){
            return head;
        }
        Node* current = head;
        Node* previous = nullptr;

        int i = 0;
        while((current != nullptr) && (i < p-1)){
            
        }
    }

    static Node* reverse(Node* head){
        Node* curr = head;
        Node* prev = nullptr;
        Node* n = nullptr;
        while(curr != nullptr){
            n = curr->next;
            curr->next = prev;
            prev = curr;
            curr = n;
        }
        return prev;
    }

    static void printList(Node* head){
        while(head){
            cout << head->value << " ";
            head = head->next;
        }
        cout << endl;
    }
};

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    LinkedList::printList(head);
    Node* result = LinkedList::reverseSublist(head, 2, 4);
    LinkedList::printList(result);
    return 0;
}