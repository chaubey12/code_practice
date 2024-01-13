#include <iostream>
#include <vector>
#include <list>


using namespace std;

class Queue{
private:
    list<int> data_;
public:
    void Enque(int x) {
        data_.emplace_back(x);
    }

    int Dequeue(){
        if(data_.empty()){
            throw length_error("Empty queue");
        }
        int val = data_.front();
        data_.pop_front();
        return val;
    }

    int Max() const{
        if(data_.empty()){
            throw length_error("Cannot perform max on empty queue");
        }
        return *max_element(data_.begin(), data_.end());
    }
};

int main(){
    return 0;
}