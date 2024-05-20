from typing import Optional

class ListNode:
    def __init__(self, data=0, next=None):
        self.data = data
        self.next = next

def merge_two_sorted_lists(L1: Optional[ListNode], L2: Optional[ListNode]) -> Optional[ListNode]:
    dummy_head = tail = ListNode()

    while L1 and L2:
        if L1.data < L2.data:
            tail.next, L1 = L1, L1.next
        else:
            tail.next, L2 = L2, L2.next
        tail = tail.next
    tail.next = L1 or L2
    return dummy_head.next

def print_list(L: ListNode) -> None:
    while L:
        print(L.data)
        L = L.next

if __name__ == '__main__':
    L1_head = L1 = ListNode(1)
    L1.next = ListNode(3)
    L1 = L1.next
    L1.next = ListNode(5)
    L1 = L1.next
    L1.next = ListNode(7)
    L2_head = L2 = ListNode(2)
    L2.next = ListNode(4)
    L2 = L2.next
    L2.next = ListNode(6)
    L2 = L2.next
    L2.next = ListNode(8)
    L = merge_two_sorted_lists(L1_head, L2_head)
    print_list(L)

