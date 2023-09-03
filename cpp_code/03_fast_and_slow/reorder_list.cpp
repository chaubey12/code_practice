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
    static Node* reorder(Node* head){
        Node* mid = middle(head);
        Node* l1 = head;
        Node* l1_n = l1;
        Node* l2 = mid->next;
        mid->next  = nullptr;
        Node* l2_n = l2;
        l2 = reverse(l2);
        while(l1 != nullptr && l2 != nullptr){
            l1_n = l1->next;
            l2_n = l2->next;
            l2->next = l1->next;
            l1->next = l2;
            l1 = l1_n;
            l2 = l2_n;
        }
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
    static Node* middle(Node* head){
        Node* slow = head;
        Node* fast = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    static Node* reverse(Node* head){
        Node* curr = head;
        Node* prev = nullptr;
        Node* n = nullptr;
        while(curr){
            n = curr->next;
            curr->next = prev;
            prev = curr;
            curr= n;
        }
        return prev;
    }
};

int main(){
    Node* head = new Node(2);
    head->next = new Node(4);
    head->next->next = new Node(6);
    head->next->next->next = new Node(8);
    head->next->next->next->next = new Node(10);
    LinkedList::printList(head);
    LinkedList::printList(LinkedList::reorder(head));
    return 0;
}