#include <iostream>
#include <queue>


using namespace std;

class Stack{
private:
    int timestamp_=0;
    struct ValueWithRank{
        int value, rank;
        bool operator<(const ValueWithRank& that) const{
            return value < that.value;
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
    int Peek() const{ return max_heap_.top().rank;}

    bool Empty() const{
        return max_heap_.empty();
    }
};

int main(){
    Stack st;
    st.Push(5);
    st.Push(6);
    st.Push(7);
    st.Push(8);
    while(!st.Empty()){
        cout << st.Peek() << " ";
        st.Pop();
    } 
    cout << endl;
    return 0;
}