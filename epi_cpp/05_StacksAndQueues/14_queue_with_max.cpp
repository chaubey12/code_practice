#include <iostream>
#include <queue>
#include <deque>

using namespace std;
template <typename T>
class QueueWithMax{
private:
    queue<T> entries_;
    queue<T> candidates_for_max_;
public:
    void Enqueue(const T& x){
        entries_.emplace(x);
        while(!candidates_for_max_.empty()){
            if(candidates_for_max_.back() >= x){
                break;
            }
            candidates_for_max_.pop_back();
        }
        candidates_for_max_.emplace_back(x);
    }

    T Dequeue(){
        if(!entries_.empty()){
            T result = entries_.front();
            if(result == candidates_for_max_.front()){
                candidates_for_max_.pop_front();
            }
            entries_.pop();
            return result;
        }
        throw length_error("empty queue");
    }
    const T& Max() const{
        if(!candidates_for_max_.empty()){
            return candidates_for_max_.front();
        }
        throw length_error("empty queue");
    }
};

int main(){
    return 0;
}