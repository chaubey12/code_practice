#include <iostream>
#include <stack>

using namespace std;

class Queue{
private:
    stack<int> enq_, deq_;
public:
    void Enqueue(int x){ enq_.emplace(x); }
    int Dequeue(){
        if(deq_.empty()){
            while(!enq_.empty()){
                deq_.emplace(enq_.top());
                enq_.pop();
            }
        }
        if(deq_.empty()){
            throw length_error("empty queue");
        }
        int ret = deq_.top();
        deq_.pop();
        return ret;
    }
};

int main(){
    return 0;
}