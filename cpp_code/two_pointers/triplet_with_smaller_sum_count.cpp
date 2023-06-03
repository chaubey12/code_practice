#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class TripletsWithSmallerSum{
public:
    static int searchTriplet(vector<int>& arr, int targetSum){
        sort(arr.begin(), arr.end());
        int count = 0;
        for(int i = 0; i < arr.size() - 2; i++){
            count += searchPairs(arr, targetSum - arr[i], i);
        }
        return count;
    }
private:
    static int searchPairs(vector<int>& arr, int targetSum, int first){
        int count = 0;
        int left = first + 1, right = arr.size() - 1;
        while(left < right){
            if(arr[left] + arr[right] < targetSum){
                count++;
                left++;
            }else{
                right--;
            }
        }
        return count;
    }
};

int main(){
    vector<int> arr = {-1, 1, 2, 4, -2, 3, -4, -3, 0, 5};
    cout << TripletsWithSmallerSum::searchTriplet(arr, 6) << " triplets have sum smaller than " << 6 <<endl;
    return 0;
}