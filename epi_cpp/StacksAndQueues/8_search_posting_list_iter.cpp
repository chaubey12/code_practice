#include <iostream>
#include <memory>
#include <stack>

using namespace std;

struct PostingListNode{
    int order;
    shared_ptr<PostingListNode> next, jump;
};


void SetJumpOrder(shared_ptr<PostingListNode>& L){
    stack<shared_ptr<PostingListNode>> s;
    int order = 0;
    s.emplace(L);
    while(!s.empty()){
        auto curr = s.top();
        s.pop();
        s.emplace(curr->next);
        s.emplace(curr->jump);
    }
}

int main(){
    return 0;
}