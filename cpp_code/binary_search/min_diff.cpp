#include <iostream>
#include <vector>

using namespace std;

class MinimumDifference{
public:
    static int searchMinDifference(const vector<int>& arr, int key){
        if(key < arr[0]){
            return arr[0];
        }
        if(key > arr[arr.size() - 1]){
            return arr[arr.size() - 1];
        }
        int start = 0, end = arr.size() - 1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(key < arr[mid]){
                end = mid - 1;
            }else if(key > arr[mid]){
                start = mid + 1;
            }else{
                return arr[mid];
            }
        }
        if((arr[start] - key) < (key - arr[end])){
            return arr[start];
        }
        return arr[end];
    }
};

int main(){
    vector<int> arr = {8, 12, 13, 17, 21, 34, 43, 51};
    int key = 18;
    cout << MinimumDifference::searchMinDifference(arr, key) << endl;
    return 0;
}