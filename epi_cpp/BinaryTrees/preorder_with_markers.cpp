#include <iostream>
#include <vector>
#include <memory>

using namespace std;

template<typename T>
struct BinaryTreeNode{
    T data;
    unique_ptr<BinaryTreeNode<int>> left, right;
};

unique_ptr<BinaryTreeNode<int>> ReconstructPreorderHelper(const vector<int*>& preorder, int* subtree_idx_pointer){
    int& subtree_idx = *subtree_idx_pointer;
    int* subtree_key = preorder[subtree_idx];
    ++subtree_idx;
    if(subtree_key == nullptr){
        return nullptr;
    }
    auto left_subtree = ReconstructPreorderHelper(preorder, subtree_idx_pointer);
    auto right_subtree = ReconstructPreorderHelper(preorder, subtree_idx_pointer);
    return make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{*subtree_key, move(left_subtree), move(right_subtree)});
}

unique_ptr<BinaryTreeNode<int>> ReconstructPreorder(const vector<int*>& preorder){
    int subtree_idx_pointer = 0;
    return ReconstructPreorderHelper(preorder, &subtree_idx_pointer);
}

int main(){
    return 0;
}