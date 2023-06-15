#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class SumOfElements{
public:
    static int findSumOfElements(const vector<int>& nums, int k1, int k2){
        priority_queue<int> maxHeap;
        for(int i = 0; i < nums.size(); i++){
            if(i < k2 - 1){
                maxHeap.push(nums[i]);
            }else if(nums[i] < maxHeap.top()){
                maxHeap.pop();
                maxHeap.push(nums[i]);
            }
        }
        int elementSum = 0;
        for(int i = 0; i < k2 - k1 - 1; i++){
            elementSum += maxHeap.top();
            maxHeap.pop();
        }
        return elementSum;
    }
};


int main(){
    vector<int> arr = {7, 3, 6, 8, 9, 1, 2, 4, 5};
    int k1 = 3, k2 = 7;
    auto result = SumOfElements::findSumOfElements(arr, k1, k2);
    cout << "Sum of elements : " << result << endl;
    return 0;
}