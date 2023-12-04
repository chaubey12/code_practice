#include <iostream>
#include <memory>

using namespace std;

class BinaryTreeNode{
private:
    shared_ptr<BinaryTreeNode>  left_, right_, parent_;
    bool locked_=false;
    int numLockedDescendants_=0;
public:
    bool IsLocked() const{
        return locked_;
    }

    bool Lock(){
        if(locked_){
            return false;
        }
        for(auto iter = parent_; iter != nullptr; iter = iter->parent_){
            if(iter->locked_){
                return false;
            }
        }
        locked_=true;
        for(auto iter = parent_; iter != nullptr; iter = iter->parent_){
            ++iter->numLockedDescendants_;
        }
        return true;
    }

    void Unlock(){
        if(locked_){
            locked_ = false;
            for(auto iter = parent_; iter != nullptr; iter=iter->parent_){
                --iter->numLockedDescendants_;
            }
        }
    }
};