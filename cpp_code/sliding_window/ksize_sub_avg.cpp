#include <iostream>
#include <vector>

using namespace std;

class AverageOfSubarrayOfSizeK{
public: 
    static vector<double> findAverage(const vector<int>& arr, int k){
        vector<double> result(arr.size() - k + 1);
        int windowStart = 0;
        double sum = 0;
        for(int windowEnd = 0; windowEnd < arr.size(); windowEnd++){
            sum += arr[windowEnd];
            if(windowEnd >= k-1){
                result[windowStart] = sum/k;
                sum -= arr[windowStart];
                windowStart++;
            }
        }
        return result;
    }
};

int main(){
    vector<int> arr = {3, 2, 4, 7, 8, 1, 11, 7, 9};
    int k = 3;
    auto result = AverageOfSubarrayOfSizeK::findAverage(arr, k);
    for(auto item : result){
        cout << item << " ";
    }
    cout << endl;
    return 0;
}