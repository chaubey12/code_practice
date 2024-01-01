#include <iostream>
#include <vector>
#include <memory>

using namespace std;
template<typename T>
struct BSTNode{
    T data;
    unique_ptr<BSTNode<T>> left_, right_;
};

unique_ptr<BSTNode<int>> BuildMinimumHeightBSTFromSortedArrayHelper(const vector<int>& A, int start, int end){
    if(start >= end){
        return nullptr;
    }
    int mid = start + (end - start)/2;
    return make_unique<BSTNode<int>>(BSTNode<int>{
        A[mid], 
        BuildMinimumHeightBSTFromSortedArrayHelper(A, start, mid),
        BuildMinimumHeightBSTFromSortedArrayHelper(A, mid+1, end)
    });
}


unique_ptr<BSTNode<int>> BuildMinimumHeightBSTFromSortedArray(const vector<int>& A){
    return BuildMinimumHeightBSTFromSortedArrayHelper(A, 0, A.size());
}

void Inorder(const unique_ptr<BSTNode<int>>& tree){
    if(tree){
        Inorder(tree->left_);
        cout << tree->data << " ";
        Inorder(tree->right_);
    }
}

int main(){
    vector<int> sorted_array{2, 4, 6, 8, 10, 12, 14};
    auto tree = BuildMinimumHeightBSTFromSortedArray(sorted_array);
    Inorder(tree);
    cout << endl;
    return 0;
}