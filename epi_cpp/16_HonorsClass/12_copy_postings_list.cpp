#include <iostream>
#include <vector>
#include <memory>

using namespace std;

struct PostingListNode{
    int order;
    shared_ptr<PostingListNode> next, jump;
};

void PrintPostingList(shared_ptr<PostingListNode> head){
    while(head){
        cout << head->order<<" ";
        if(head->next){
            cout << head->next->order << " ";
        }else{
            cout << "NEXT NULL ";
        }
        if(head->jump){
            cout << head->jump->order << " ";
        }else{
            cout << "JUMP NULL ";
        }
        head = head->next;
        cout << endl;
    }
}

shared_ptr<PostingListNode> CopyPostingList(const shared_ptr<PostingListNode>& L){
    if(L == nullptr){
        return nullptr;
    }
    auto iter = L;
    while(iter){
        auto new_node = make_shared<PostingListNode>(PostingListNode{iter->order, iter->next, nullptr});
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
    auto a = make_shared<PostingListNode>(PostingListNode{1, nullptr, nullptr});
    auto b = make_shared<PostingListNode>(PostingListNode{2, nullptr, nullptr});
    auto c = make_shared<PostingListNode>(PostingListNode{3, nullptr, nullptr});
    auto d = make_shared<PostingListNode>(PostingListNode{4, nullptr, nullptr});
    auto e = make_shared<PostingListNode>(PostingListNode{5, nullptr, nullptr});
    auto f = make_shared<PostingListNode>(PostingListNode{6, nullptr, nullptr});
    auto head = a;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    a->jump = f;
    b->jump = a;
    c->jump = d;
    e->jump = c;
    PrintPostingList(head);
    auto result = CopyPostingList(head);
    cout <<"COPYING LIST"<<endl;
    PrintPostingList(head);
    return 0;
}