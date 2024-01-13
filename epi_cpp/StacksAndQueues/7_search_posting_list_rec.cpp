#include <iostream>
#include <memory>

using namespace std;

struct PostingListNode{
    int order;
    shared_ptr<PostingListNode> next, jump;
};

void SetJumpOrderHelper(const shared_ptr<PostingListNode>& L, int* order){
    if(L && L->order == -1){
        L->order = (*order)++;
        SetJumpOrderHelper(L->jump, order);
        SetJumpOrderHelper(L->next, order);
    }
}


void SetJumpOrder(const shared_ptr<PostingListNode>& L){
    int order = 0;
    SetJumpOrderHelper(L, &order);
}

int main(){
    return 0;
}