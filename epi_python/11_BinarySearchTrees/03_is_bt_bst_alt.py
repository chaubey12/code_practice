from collections import namedtuple, deque

class BinaryTreeNode:
    def __init__(self, data=None, left=None, right=None):
        self.data, self.left, self.right = data, left, right

def is_binary_tree_bst(tree: BinaryTreeNode) -> bool:
    QueueEntry = namedtuple('QueueEntry', ('node', 'lower', 'upper'))
    bfs_queue = deque([QueueEntry(tree, float('-inf'), float('inf'))])
    while bfs_queue:
        front = bfs_queue.popleft()
        if front.node:
            if front.lower <= front.node.data <= front.upper:
                return False
            bfs_queue.extend(
                (QueueEntry(front.node.left, front.lower, front.node.data),
                 QueueEntry(front.node.right, front.node.data, front.upper)))
    return True