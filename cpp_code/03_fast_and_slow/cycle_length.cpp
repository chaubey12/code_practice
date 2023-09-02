#include <iostream>
#include <vector>

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
    static int findCycleLength(Node* head){
        Node* slow = head;
        Node* fast = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                return calculateLength(slow);
            }
        }
        return 0;
    }

    static int calculateLength(Node* slow){
        Node* current = slow;
        int cycleLength = 0;
        while(true){
            current = current->next;
            cycleLength++;
            if(current == slow){
                break;
            }
        }
        return cycleLength;
    }
};


int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    cout << LinkedList::findCycleLength(head) << endl;
    head->next->next->next->next->next->next = head->next->next;
    cout << LinkedList::findCycleLength(head) << endl;
    return 0;
}