#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class KthLargest{
    priority_queue<int, vector<int>, greater<int>> topKHeap;
    int k;
public:
    KthLargest(int k, vector<int>& nums){
        this->k = k;
        for(int num : nums){
            Add(num);
        }
    }

    int Add(int val){
        if(topKHeap.size() < k){
            topKHeap.emplace(val);
        }else if(val > topKHeap.top()){
            topKHeap.pop();
            topKHeap.emplace(val);
        }
        return topKHeap.top();
    }
};

int main(){
    vector<int> nums{3, 6, 10, 9, 8, 4, 7, 15};
    vector<int> adds = {20, 6, 18, 13, 2};
    int k = 3;
    auto obj = KthLargest(k, nums);
    for(int add : adds){
        cout << obj.Add(add) << endl;
    }
    return 0;
}