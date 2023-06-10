#include <iostream>

using namespace std;

struct PostListNode{
    int order;
    shared_ptr<PostListNode> next;
    shared_ptr<PostListNode> jump;
};

shared_ptr<PostListNode> CopyPostingList(const shared_ptr<PostListNode> L){
    if(L == nullptr){
        return nullptr;
    }
    auto iter = L;
    while(iter){
        auto new_node = make_shared<PostListNode>(
            PostListNode{iter->order, iter->next, nullptr}
        );
        iter->next = new_node;
        iter = new_node->next;
    }
    iter = L;
    while(iter){
        if(iter->jump){
            iter->next->jump = iter->jump->next;
        }
        iter = iter->next->next;
    }
    iter = L;
    auto new_list_head = iter->next;
    while(iter->next){
        auto temp = iter->next;
        iter->next = temp->next;
        iter = temp;
    }
    return new_list_head;
}

int main(){
    return 0;
}