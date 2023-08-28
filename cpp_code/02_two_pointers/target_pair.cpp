#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <unordered_map>

using namespace std;

class PairWithTargetSum{
public:
    static pair<int, int> find(vector<int>& arr, int target){
        int start = 0, end = arr.size() - 1;
        sort(arr.begin(), arr.end());
        while(start < end){
            int currentSum = arr[start] + arr[end];
            if(currentSum == target){
                return make_pair(start, end);
            }
            if(currentSum < target){
                start++;
            }else{
                end--;
            }
        }
        return make_pair(-1, -1);
    }
};

class PairWithTargetSumHash{
public:
    static pair<int, int> find(vector<int>& arr, int target){
        unordered_map<int, int> numSumPair;
        for(int i = 0; i < arr.size(); i++){
            if(numSumPair.find(target - arr[i]) != numSumPair.end()){
                return make_pair(i, numSumPair[target - arr[i]]);
            }
            numSumPair[arr[i]] = i;
        }
        return make_pair(-1, -1);
    }
};

int main(){
    vector<int> arr = {1, 2, 3, 4, 6};
    int target = 6;
    auto result = PairWithTargetSum::find(arr, target);
    cout << result.first << ", "<<result.second << endl;
    result = PairWithTargetSumHash::find(arr, target);
    cout << result.first << ", "<<result.second << endl;
    return 0;
}