#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Stack{
private:
    int timestamp_ = 0;
    struct ValueWithRank{
        int value, rank;
        bool operator<(const ValueWithRank& that) const{
            return rank < that.rank;
        }
    };
    priority_queue<ValueWithRank, vector<ValueWithRank>> max_heap_;
public:
    void Push(int x){
        max_heap_.emplace(ValueWithRank{timestamp_++, x});
    }

    int Pop(){
        if(max_heap_.empty()){
            throw length_error("empty stack");
        }
        int val = max_heap_.top().rank;
        max_heap_.pop();
        return val;
    }

    int Peek(){
        if(max_heap_.empty()){
            throw length_error("empty stack");
        }
        return max_heap_.top().rank;
    }
};

int main(){
    Stack* st = new Stack();
    st->Push(1);
    st->Push(2);
    st->Push(3);
    cout << st->Pop()<< endl;
    cout << st->Pop()<< endl;
    cout << st->Pop()<< endl;


    return 0;
}