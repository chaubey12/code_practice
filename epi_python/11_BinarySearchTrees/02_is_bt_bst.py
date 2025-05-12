class BinaryTreeNode:
    def __init__(self, data=None, left=None, right=None):
        self.data, self.left, self.right = data, left, right

def is_binary_tree_bst(tree: BinaryTreeNode) -> bool:
    def are_keys_in_range(tree,
                          low_range=float('-inf'),
                          high_range=float('inf')):
        if not tree:
            return True
        elif not low_range <= tree.data <= high_range:
            return False
        return (are_keys_in_range(tree.left, low_range, tree.data)
                and are_keys_in_range(tree.right, tree.data, high_range))
    return are_keys_in_range(tree)