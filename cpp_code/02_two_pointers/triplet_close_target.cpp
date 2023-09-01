#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class TripletSumTarget{
public:
    static int find(vector<int>& arr, int targetSum){
        int smallestDifference = numeric_limits<int>::max();
        sort(arr.begin(), arr.end());
        for(int i = 0; i < arr.size() - 2; i++){
            int start = i+1;
            int end = arr.size() - 1;
            while(start < end){
                int targetDifference = targetSum - (arr[i] + arr[start] + arr[end]);
                if(targetDifference == 0){
                    return targetSum - targetDifference;
                }
                if(abs(targetDifference) < abs(smallestDifference)){
                    smallestDifference = targetDifference;
                }
                if(abs(targetDifference) < abs(smallestDifference) || abs(targetDifference) == abs(smallestDifference) && targetDifference > smallestDifference){
                    smallestDifference = targetDifference;
                }
                if(targetDifference > 0){
                    start++;
                }else{
                    end--;
                }
            }
            return targetSum - smallestDifference;
        }
        return 0;
    }
};

int main(){
    vector<int> arr = {-2, 0, 1, 2};
    int target = 2;
    auto result = TripletSumTarget::find(arr, 2);
    cout << result;
    return 0;
}