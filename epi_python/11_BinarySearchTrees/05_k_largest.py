from typing import List

class BstNode:
    def __init__(self, data=None, left=None, right=None):
        self.data, self.left, self.right = data, left, right

def find_k_largest_in_bst(tree: BstNode, k: int) -> List[int]:
    def find_k_largest_in_bst_helper(tree):
        # Perform reverse inorder traversal
        if tree and len(k_largest_elements) < k:
            find_k_largest_in_bst_helper(tree.right)
            if len(k_largest_elements) < k:
                k_largest_elements.append(tree.data)
                find_k_largest_in_bst_helper(tree.left)

    k_largest_elements: List[int] = []
    find_k_largest_in_bst_helper(tree)
    return k_largest_elements
