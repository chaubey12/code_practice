#include <iostream>

using namespace std;

class Node{
public:
    int value = 0;
    Node* next;
    Node(int value){
        this->value = value;
        this->next = nullptr;
    }
};

class LinkedList{
public:
    static Node* reverse(Node* head){
        Node* current = head;
        Node* prev = nullptr;
        Node* n = nullptr;
        while(current != nullptr){
            n = current->next;
            current->next = prev;
            prev = current;
            current = n;
        }
        return prev;
    }

    static void print(Node* head){
        while(head){
            cout << head->value <<" ";
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
    LinkedList::print(head);
    head = LinkedList::reverse(head);
    LinkedList::print(head);
    return 0;
}