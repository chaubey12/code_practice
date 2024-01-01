#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class BinarySearchTree{
private:
    struct TreeNode{
        int data;
        unique_ptr<TreeNode> left, right;
    };
    unique_ptr<TreeNode> root_ = nullptr;
public:
    bool Insert(int key){
        if(root_ == nullptr){
            root_ = make_unique<TreeNode>(TreeNode{key, nullptr, nullptr});
        }else{
            TreeNode *curr = root_.get(), *parent = nullptr;
            while(curr){
                parent = curr;
                if(key == curr->data){
                    return false;
                } else if(key < curr->data){
                    curr = curr->left.get();
                } else{
                    curr = curr->right.get();
                }
            }
            if(key < parent->data){
                parent->left.reset(new TreeNode{key});
            }else{
                parent->right.reset(new TreeNode{key});
            }
        }
        return true;
    }
    bool Delete(int key){
        TreeNode *curr = root_.get(), *parent = nullptr;
        while(curr && curr->data != key){
            parent = curr;
            curr = key < curr->data ? curr->left.get() : curr->right.get(); 
        }
        if(!curr){
            return false;
        }
        TreeNode *key_node = curr;
        if(key_node->right){
            TreeNode *r_key_node = key_node->right.get(), *r_parent = key_node;
        }else{
            if(root_.get() == key_node){
                root_.reset(key_node->left.release());
            }else{
                if(parent->left.get() == key_node){
                    parent->left.reset(key_node->left.release());
                }else{
                    parent->right.reset(key_node->left.release());
                }
            }
        }
        return true;
    }
};


int main(){
    return 0;
}