#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map>

using namespace std;

template <typename T>
struct BinaryTreeNode{
    T data;
    unique_ptr<BinaryTreeNode<T>> left, right;
};

unique_ptr<BinaryTreeNode<int>> BinaryTreeNodeFromPreorderInorderHelper(
    const vector<int>& preorder, size_t preorder_start, size_t preorder_end,
    size_t inorder_start, size_t inorder_end, unordered_map<int, size_t>& node_to_inorder_idx 
){
    if(preorder_end <= preorder_start || inorder_end <= inorder_start){
        return nullptr;
    }
    size_t root_inorder_idx = node_to_inorder_idx.at(preorder[preorder_start]);
    size_t left_subtree_size = root_inorder_idx - inorder_start;
    return make_unique<BinaryTreeNode<int>>(
        BinaryTreeNode<int>{
            preorder[preorder_start],
            BinaryTreeNodeFromPreorderInorderHelper(
                preorder, preorder_start + 1,
                preorder_start + 1 + left_subtree_size, inorder_start,
                root_inorder_idx, node_to_inorder_idx
            ),
            BinaryTreeNodeFromPreorderInorderHelper(
                preorder, 
                preorder_start + 1 + left_subtree_size, preorder_end,
                root_inorder_idx + 1, inorder_end, node_to_inorder_idx
            )
        }
    );
}

unique_ptr<BinaryTreeNode<int>> BinaryTreeNodeFromPreorderInorder(const vector<int>& preorder,
                                const vector<int>& inorder){
    unordered_map<int, size_t> node_to_inorder_idx;
    for(size_t i=0; i < inorder.size(); ++i){
        node_to_inorder_idx.emplace(inorder[i], i);
    }
    return BinaryTreeNodeFromPreorderInorderHelper(preorder, 0, preorder.size(), 0, inorder.size(), node_to_inorder_idx); 
}

void Inorder(unique_ptr<BinaryTreeNode<int>>& tree){
    if(tree){
        Inorder(tree->left);
        cout << tree->data << " ";
        Inorder(tree->right);
    }
}

void Preorder(unique_ptr<BinaryTreeNode<int>>& tree){
    if(tree){
        cout << tree->data<<" ";
        Preorder(tree->left);
        Preorder(tree->right);
    }
}


int main(){
    vector<int> in {4,2,5,1,6,3,7};
    vector<int> pre {1,2,4,5,3,6,7};
    auto result = BinaryTreeNodeFromPreorderInorder(pre, in);
    Inorder(result);
    cout << endl;
    Preorder(result);
    cout << endl;
    return 0;
}