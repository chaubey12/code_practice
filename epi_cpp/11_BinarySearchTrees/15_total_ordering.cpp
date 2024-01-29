#include <iostream>
#include <vector>
#include <memory>

using namespace std;
template<typename T>
struct BSTNode{
    T data;
    unique_ptr<BSTNode<T>> left_, right_;
};

bool SearchTarget(
    const unique_ptr<BSTNode<int>>& from,
    const unique_ptr<BSTNode<int>>& target
){
    auto* iter = from.get();
    while(iter && iter != target.get()){
        iter = iter->data > target->data ? iter->left_.get() : iter->right_.get();
    }
    return iter == target.get();
}


bool PairIncludeAncestorAndDescendantOfM(
    const unique_ptr<BSTNode<int>>& possible_anc_or_desc_0,
    const unique_ptr<BSTNode<int>>& possible_anc_or_desc_1,
    const unique_ptr<BSTNode<int>>& middle
){
    auto* search_0 = possible_anc_or_desc_0.get();
    auto* search_1 = possible_anc_or_desc_1.get();
    while(search_0 != possible_anc_or_desc_1.get() &&
          search_0 != middle.get() &&
          search_1 != possible_anc_or_desc_0.get() &&
          search_1 != middle.get() && (search_0 || search_1)){
        if(search_0){
            search_0 = search_0->data > middle->data ? search_0->left_.get() : search_0->right_.get();
        }
        if(search_1){
            search_1 = search_1->data > middle->data ? search_1->left_.get() : search_1->right_.get();
        }
    }
    if((search_0 != middle.get() && search_1 != middle.get()) ||
        search_0 == possible_anc_or_desc_1.get() ||
        search_1 == possible_anc_or_desc_0.get()){
        return false;
    }
    return search_0 == middle.get() 
            ? SearchTarget(middle, possible_anc_or_desc_1)
            : SearchTarget(middle, possible_anc_or_desc_0);
}

int main(){
    auto tree = make_unique<BSTNode<int>>(BSTNode<int>{19});
    tree->left_ = make_unique<BSTNode<int>>(BSTNode<int>{7});
    tree->left_->left_ = make_unique<BSTNode<int>>(BSTNode<int>{3});
    tree->left_->left_->left_ = make_unique<BSTNode<int>>(BSTNode<int>{2});
    tree->left_->left_->right_ = make_unique<BSTNode<int>>(BSTNode<int>{5});
    tree->left_->right_ = make_unique<BSTNode<int>>(BSTNode<int>{11});
    tree->left_->right_->right_ = make_unique<BSTNode<int>>(BSTNode<int>{17});
    tree->left_->right_->right_->left_ = make_unique<BSTNode<int>>(BSTNode<int>{13});
    tree->right_ = make_unique<BSTNode<int>>(BSTNode<int>{43});
    tree->right_->right_ = make_unique<BSTNode<int>>(BSTNode<int>{47});
    tree->right_->left_ = make_unique<BSTNode<int>>(BSTNode<int>{23});
    tree->right_->left_->right_ = make_unique<BSTNode<int>>(BSTNode<int>{37});
    tree->right_->left_->right_->right_ = make_unique<BSTNode<int>>(BSTNode<int>{41});
    tree->right_->left_->right_->left_ = make_unique<BSTNode<int>>(BSTNode<int>{29});
    tree->right_->left_->right_->left_->right_ = make_unique<BSTNode<int>>(BSTNode<int>{31});
    if(PairIncludeAncestorAndDescendantOfM(tree, tree->right_->right_,tree->left_)){
        cout << "INCLUDED"<<endl;
    }else{
        cout << "NOT INCLUDED" << endl;
    }
    return 0;
}
