from typing import Optional

class BinaryTreeNode:
    def __init__(self, data=None, left=None, right=None, parent=None):
        self.data = data
        self.left = left
        self.right = right
        self.parent = parent

def lca(node0: BinaryTreeNode, node1: BinaryTreeNode)->Optional[BinaryTreeNode]:
    def get_depth(node):
        depth = 0
        while node:
            depth += 1
            node = node.parent
        return depth
    depth0, depth1 = map(get_depth, (node0, node1))
    if depth1 > depth0:
        node0, node1 = node1, node0
    depth_diff = abs(depth0 - depth1)
    while depth_diff:
        node0 = node0.parent
        depth_diff -= 1
    
    while node0 is not node1:
        node0, node1 = node0.parent, node1.parent
    return node0
