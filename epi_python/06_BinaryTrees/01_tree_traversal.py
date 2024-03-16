class BinaryTreeNode:
    def __init__(self, data=None, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right

def tree_traversal(root: BinaryTreeNode)->None:
    if root:
        print('Preorder: %d' %root.data)
        tree_traversal(root.left)
        print('Inorder: %d' %root.data)
        tree_traversal(root.right)
        print('Postorder: %d' %root.data)