#include <iostream>
#include <sstream>
#include <queue>

using namespace std;

void OnlineMedian(istringstream *sequence){
    priority_queue<int, vector<int>, greater<>> min_heap;
    priority_queue<int, vector<int>, less<>> max_heap;
    int x;
    while(*sequence >> x){
        if(min_heap.empty()){
            min_heap.emplace(x);
        }else{
            if(x >= min_heap.top()){
                min_heap.emplace(x);
            }else{
                max_heap.emplace(x);
            }
        }

        if(min_heap.size() > max_heap.size() + 1){
            max_heap.emplace(min_heap.top());
            min_heap.pop();
        }else if(max_heap.size() > min_heap.size()){
            min_heap.emplace(max_heap.top());
            max_heap.pop();
        }
        cout << (min_heap.size() == max_heap.size()
                    ? 0.5*(min_heap.top() + max_heap.top())
                    : min_heap.top());
    }
}

int main(){
    return 0;
}