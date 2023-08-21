#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class MaxSubarraySum{
public:
    static int findMax(const vector<int>& arr, int k){
        int maxSum = numeric_limits<int>::min();
        int windowStart = 0;
        int windowSum = 0;
        for(int windowEnd = 0; windowEnd < arr.size(); windowEnd++){
            windowSum += arr[windowEnd];
            if(windowEnd >= k-1){
                maxSum = max(windowSum, maxSum);
                windowSum -= arr[windowStart++];
            }
        }
        return maxSum;
    }
};

int main(){
    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 3;
    cout << MaxSubarraySum::findMax(arr, k) << endl;
    return 0;
}