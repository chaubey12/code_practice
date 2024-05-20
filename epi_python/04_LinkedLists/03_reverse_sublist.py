from typing import Optional

class ListNode:
    def __init__(self, data=0, next=None) -> None:
        self.data = data
        self.next = next

def print_list(L: ListNode) -> None:
    while L:
        print(L.data)
        L = L.next

def reverse_sublist(L: ListNode, start: int, finish: int) -> Optional[ListNode]:
    dummy_head = sublist_head = ListNode(0, L)
    for _ in range(1, start):
        sublist_head = sublist_head.next

    sublist_iter = sublist_head.next
    for _ in range(finish - start):
        temp = sublist_iter.next
        sublist_iter.next, temp.next, sublist_head.next = (temp.next,
                                                           sublist_head.next,
                                                           temp)
    return dummy_head.next

if __name__ == '__main__':
    L = L_tail = ListNode(1)
    L_tail.next = ListNode(2)
    L_tail = L_tail.next
    L_tail.next = ListNode(3)
    L_tail = L_tail.next
    L_tail.next = ListNode(4)
    L_tail = L_tail.next
    L_tail.next = ListNode(5)
    L_tail = L_tail.next
    L_tail.next = ListNode(6)
    L_tail = L_tail.next
    L_tail.next = ListNode(7)
    L_tail = L_tail.next
    reverse_sublist(L, 3, 6)
    print_list(L)

