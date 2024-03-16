from typing import Optional
import collections

class BinaryTreeNode:
    def __init__(self, data=None, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right

def lca(tree: BinaryTreeNode, node0: BinaryTreeNode, node1: BinaryTreeNode)->Optional[BinaryTreeNode]:
    Status = collections.namedtuple('Status', ('num_target_nodes', 'ancestor'))

    def lca_helper(tree, node0, node1):
        if tree is None:
            return Status(0, None)
        left_result = lca_helper(tree.left, node0, node1)
        if left_result.num_target_nodes == 2:
            return left_result
        right_result = lca_helper(tree.right, node0, node1)
        if right_result.num_target_nodes == 2:
            return right_result
        num_target_nodes = (left_result.num_target_nodes + right_result.num_target_nodes + 
                            (node0, node1).count(tree))
        return Status(num_target_nodes, tree if num_target_nodes == 2 else None)
    return lca_helper(tree, node0, node1).ancestor