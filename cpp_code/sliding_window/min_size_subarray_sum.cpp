#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class MinSizeSubarraySum{
public:
    static int findMinSubarray(const vector<int>& arr, int S){
        int minSize = numeric_limits<int>::max();
        int currSum = 0;
        int windowStart = 0;
        for(int windowEnd = 0; windowEnd < arr.size(); windowEnd++){
            currSum += arr[windowEnd];
            while(currSum >= S){
                minSize = min(minSize, windowEnd - windowStart + 1);
                currSum -= arr[windowStart++];
            }
        }
        return minSize == numeric_limits<int>::max() ? 0 : minSize;
    }
};


int main(){
    vector<int> arr = {1, 3, 5, 3, 5, 7, 9, 2, 3, 4, 6};
    cout << MinSizeSubarraySum::findMinSubarray(arr, 11) << endl;
    return 0;
}