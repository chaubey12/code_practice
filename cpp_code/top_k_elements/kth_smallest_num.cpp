#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class KthSmallestNumber{
public:
    static int findKthSmallestNumber(const vector<int>& arr, int k){
        priority_queue<int> maxHeap;
        for(int i = 0; i < k; i++){
            maxHeap.push(arr[i]);
        }
        for(int i = k; i < arr.size(); i++){
            if(arr[i] < maxHeap.top()){
                maxHeap.pop();
                maxHeap.push(arr[i]);
            }
        }
        return maxHeap.top();
    }
};

int main(){
    vector<int> arr = {5, 7, 9, 3, 1, 2};
    int k = 3;
    cout << KthSmallestNumber::findKthSmallestNumber(arr, k) << " is kth smallest number." << endl;
    return 0;
}