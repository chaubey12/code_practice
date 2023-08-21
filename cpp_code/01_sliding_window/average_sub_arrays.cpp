#include <iostream>
#include <vector>

using namespace std;

class SubarrayAverage{
public:
    static vector<double> findAverage(const vector<int>& arr, int k){
        vector<double> result;
        double windowSum = 0;
        int windowStart = 0;
        for(int windowEnd = 0; windowEnd < arr.size(); windowEnd++){
            windowSum += arr[windowEnd];
            if(windowEnd >= (k-1)){
                result.push_back(windowSum/k);
                windowSum -= arr[windowStart];
                windowStart++;
            }
        }
        return result;
    }
};

int main(){
    vector<int> arr = {1, 3, 2, 6, -1, 4, 1, 8, 2};
    int k = 5;
    auto result = SubarrayAverage::findAverage(arr, k);
    for(auto val : result){
        cout << val << " ";
    }
    cout << endl;
    return 0;
}