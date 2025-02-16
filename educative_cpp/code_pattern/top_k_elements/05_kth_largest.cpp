#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int KthLargestInArray(const vector<int>& A, int k){
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for(int a : A){
        minHeap.emplace(a);
        if(minHeap.size() > k){
            minHeap.pop();
        }
    }
    return minHeap.top();
}

int main(){
    vector<int> nums = {1, 5, 12, 2, 11, 9, 7, 30, 20};
    int k=3;
    cout << KthLargestInArray(nums, k)<<endl;
    return 0;
}