#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class MedianOfAStream{
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    virtual void insertNum(int num){
        if(maxHeap.empty() || maxHeap.top() >= num){
            maxHeap.push(num);
        }else{
            minHeap.push(num);
        }

        if(maxHeap.size() > minHeap.size() + 1){
            minHeap.push(maxHeap.top());
        }else if(maxHeap.size() < minHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    virtual double findMedian(){
        if(maxHeap.size() == minHeap.size()){
            return maxHeap.top()/2.0 + minHeap.top()/2.0;
        }
        return maxHeap.top();
    }
};


int main(){
    vector<int> nums = {1, 1, 4, 2, 2, 3, 4, 5, 9, 8, 9, 7};
    auto obj = new MedianOfAStream();
    for(auto num : nums){
        obj->insertNum(num);
        cout << obj->findMedian() << " is median now" << endl;
    }
    return 0;
}