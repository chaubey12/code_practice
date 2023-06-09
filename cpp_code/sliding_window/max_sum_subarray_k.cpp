#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class MaxSumSubarrayOfSizeK{
public: 
    static int findMaxSum(vector<int>& arr, int k){
        int maxSum = numeric_limits<int>::min();
        int windowStart = 0, windowSum = 0;
        for(int windowEnd = 0; windowEnd < arr.size(); windowEnd++){
            windowSum += arr[windowEnd];
            if(windowEnd >= k - 1){
                maxSum = max(maxSum, windowSum);
                windowSum -= arr[windowStart];
                windowStart++;
            }
        }
        return maxSum;
    }
};

int main(){
    vector<int> arr = {3, 2, 4, 7, 8, 1, -11, 7, 9};
    int k = 3;
    int result = MaxSumSubarrayOfSizeK::findMaxSum(arr, k);
    cout << "Max sum is " <<result << endl;
    return 0;
}