#include <iostream>
#include <stack>
#include <vector>
#include <memory>

using namespace std;

class Stack{
private:
    struct ElementWithCachedMax{
        int element, max;
    };
    stack<ElementWithCachedMax> elements_with_cached_max_;
public:
    bool Empty() const{
        return elements_with_cached_max_.empty();
    }

    int Max() const{
        if(Empty()){
            throw length_error("Max() : Empty stack");
        }
        return elements_with_cached_max_.top().max;
    }

    int Pop(){
        if(Empty()){
            throw length_error("Pop() : empty stack");
        }
        int pop_element = elements_with_cached_max_.top().element;
        elements_with_cached_max_.pop();
        return pop_element;
    }

    void Push(int x){
        elements_with_cached_max_.emplace(
            ElementWithCachedMax{x, max(x, Empty() ? x: Max())}
        );
    }
};


int main(){
    Stack* st = new Stack();
    st->Push(5);
    st->Push(10);
    st->Push(7);
    cout << st->Max() << " ";
    st->Pop();
    cout << st->Max() << " ";
    return 0;
}