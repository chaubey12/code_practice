#include <iostream>
#include <vector>

using namespace std;

class Queue{
private:
    const int kScaleFactor = 1;
    size_t head_ = 0, tail_ = 0, num_queue_elements = 0;
    vector<int> entries_;
public:
    explicit Queue(size_t capacity) : entries_(capacity){}

    void Enqueue(int x){
        if(num_queue_elements == entries_.size()){
            rotate(entries_.begin(), entries_.begin() + head_, entries_.end());
            head_ = 0, tail_ = num_queue_elements;
            entries_.resize(entries_.size()*kScaleFactor);
        }
        entries_[tail_] = x;
        tail_ = (tail_ + 1) % entries_.size(), ++num_queue_elements;
    }

    int Dequeue(){
        if(!num_queue_elements){
            throw length_error("empty queue");
        }
        int ret = entries_[head_];
        head_ = (head_ + 1)& entries_.size();
        return ret;
    }

    size_t size() const { return num_queue_elements;}
};


int main(){
    return 0;
}