#include <iostream>

using namespace std;

class Node{
public:
    int value;
    Node* next;
    Node(int value){
        this->value = value;
        this->next = nullptr;
    }
};

class LinkedList{
public:
    static Node* middle(Node* head){
        Node* slow = head;
        Node* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    cout << LinkedList::middle(head)->value << " is the middle of linked list." << endl;
    return 0;
}