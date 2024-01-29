#include <iostream>
#include <stack>

using namespace std;

class Stack{
private:
    stack<int> elements_;
    struct MaxWithCount{
        int max, count;
    };
    stack<MaxWithCount> cached_max_with_count_;
public:
    bool Empty() const{
        return elements_.empty();
    }
    int Max() const{
        if(Empty()){
            throw length_error("Max(): empty stack");
        }
        return cached_max_with_count_.top().max;
    }
    int Pop(){
        if(Empty()){
            throw length_error("Pop(): empty stack");
        }
        int pop_element = elements_.top();
        elements_.pop();
        const int current_max = cached_max_with_count_.top().max;
        if(pop_element == current_max){
            int& max_frequency = cached_max_with_count_.top().count;
            --max_frequency;
            if(max_frequency == 0){
                cached_max_with_count_.pop();
            }
        }
        return pop_element;
    }
    void Push(int x){
        elements_.emplace(x);
        if(cached_max_with_count_.empty()){
            cached_max_with_count_.emplace(
                MaxWithCount{x, 1}
            );
        }else{
            const int current_max = cached_max_with_count_.top().max;
            if(x == current_max){
                int& max_frequency = cached_max_with_count_.top().max;
                ++max_frequency;
            }else if(x > current_max){
                cached_max_with_count_.emplace(
                    MaxWithCount{x, 1}
                );
            }
        }
    }
};

int main(){
    Stack* st = new Stack();
    st->Push(5);
    st->Push(10);
    st->Push(7);
    st->Push(6);
    cout << st->Max() << " ";
    st->Pop();
    cout << st->Max() << " ";
    return 0;
}