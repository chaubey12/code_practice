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
    static bool isPalindrome(Node* head){
        Node* mid = middle(head);
        Node* l1 = head;
        Node* l2 = mid->next;
        mid->next = nullptr;
        l2 = reverse(l2);
        while(l1 != nullptr && l2 != nullptr){
            if(l1->value != l2->value){
                return false;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        return true;
    }
private:
    static Node* middle(Node* head){
        Node* slow = head;
        Node* fast = head->next;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    static Node* reverse(Node* head){
        Node* curr = head;
        Node* prev = nullptr;
        Node* n;
        while(curr != nullptr){
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
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(1);

    // head->next->next->next = new Node(3);
    // head->next->next->next->next = new Node(3);
    // head->next->next->next->next->next = new Node(2);
    // head->next->next->next->next->next->next = new Node(1);
    if(LinkedList::isPalindrome(head)){
        cout << "IS PALINDROME" << endl;
    }else{
        cout << "NOT A PALINDROME" << endl;
    }
    return 0;
}