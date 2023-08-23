#include <iostream>
#include <vector>

using namespace std;

class SubarrayOneReplacement{
public:
    static int find(vector<int>& arr, int k){
        int windowStart=0;
        int maxOneCount=0, maxLen=0;
        for(int windowEnd=0; windowEnd < arr.size(); windowEnd++){
            if(arr[windowEnd] == 1){
                maxOneCount++;
            }
            if(windowEnd - windowStart + 1 - maxOneCount > k){
                if(arr[windowStart] == 1){
                    maxOneCount--;
                }
                windowStart++;
            }
            maxLen = max(maxLen, windowEnd - windowStart + 1);
        }
        return maxLen;
    }
};

int main(){
    vector<int> arr = {0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1};
    int k = 3;
    cout << SubarrayOneReplacement::find(arr, k) << endl;
    return 0;
}