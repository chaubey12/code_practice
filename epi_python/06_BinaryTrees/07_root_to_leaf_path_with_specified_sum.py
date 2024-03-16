class BinaryTreeNode:
    def __init__(self, data=None, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right

def has_path_sum(tree: BinaryTreeNode, remaining_weight: int)->bool:
    if not tree:
        return False
    if not tree.left and not tree.right:
        return tree.data == remaining_weight
    return (has_path_sum(tree.left, remaining_weight - tree.data) or
            has_path_sum(tree.right, remaining_weight - tree.data))