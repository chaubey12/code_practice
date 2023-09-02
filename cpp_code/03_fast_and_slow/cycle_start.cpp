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
    static Node* cycleStart(Node* head){
        int k = findCycleLength(head);
        Node* ptr1 = head;
        Node* ptr2 = head;
        while(k > 0){
            ptr2 = ptr2->next;
            k--;
        }

        while(ptr1 != ptr2){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return ptr1;
    }
private:
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
    head->next->next->next->next->next->next = head->next->next;
    cout << LinkedList::cycleStart(head)->value << " is the start of cycle." << endl;
    return 0;
}