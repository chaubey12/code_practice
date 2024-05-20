class ListNode:
    def __init__(self, data=0, next=None):
        self.data = data
        self.next = next

def search_list(L: ListNode, key: int) -> ListNode:
    while L and L.data != key:
        L = L.next
    return L

def insert_after(node: ListNode, new_node: ListNode) -> None:
    new_node.next = node.next
    node.next = new_node

def delete_after(node: ListNode) -> None:
    node.next = node.next.next

def print_list(L: ListNode) -> None:
    while L:
        print(L.data)
        L = L.next


if __name__ == '__main__':
    n1 = ListNode(1)
    n2 = ListNode(2)
    n3 = ListNode(3)
    n4 = ListNode(4)
    n1.next = n2 
    n2.next = n3
    n3.next = n4
    n4.next = None
    print_list(n1)
    insert_after(n2, ListNode(8))
    print('')
    print_list(n1)