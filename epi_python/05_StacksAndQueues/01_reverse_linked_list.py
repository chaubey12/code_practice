class ListNode:
    def __init__(self, data=0, next=None):
        self.data = data
        self.next = next
    
    def append(self, data):
        new_node = ListNode(data)
        if not self:
            self.data = data
            return
        current = self
        while current.next:
            current = current.next
        current.next = new_node
    
def print_linked_list_in_reverse(head: ListNode) -> None:
    nodes = []
    while head:
        nodes.append(head.data)
        head = head.next
    while nodes:
        print(nodes.pop())

if __name__=='__main__':
    head = ListNode(1)
    head.append(2)
    head.append(3)
    print_linked_list_in_reverse(head)