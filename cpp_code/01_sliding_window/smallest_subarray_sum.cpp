#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class SmallestSubarraySum{
public:
    static int find(const vector<int>& arr, int s){
        int minLength = numeric_limits<int>::max();
        int windowSum = 0, windowStart = 0;
        for(int windowEnd = 0; windowEnd < arr.size(); windowEnd++){
            windowSum += arr[windowEnd];
            while(windowSum >= s){
                minLength = min(minLength, windowEnd - windowStart + 1);
                windowSum -= arr[windowStart++];
            }
        }
        return minLength;
    }
};

int main(){
    vector<int> arr = {2, 1, 5, 2, 3, 2};
    int s = 7;
    cout << SmallestSubarraySum::find(arr, s) << endl;
    return 0;
}