#include <iostream>
#include <vector>
#include <limits>
#include <utility>

using namespace std;

class ShortestWindowSort{
public:
    static pair<int, int> sort(const vector<int>& arr){
        int low = 0, high = arr.size() - 1;
        while((low < high) && (arr[low] < arr[low+1])){
            low++;
        }
        if(low == high){
            return make_pair(low, high);
        }
        while((low < high) && (arr[high] > arr[high-1])){
            high--;
        }
        int subarrayMax = numeric_limits<int>::min(), subarrayMin = numeric_limits<int>::max();
        for(int i = low; i <= high; i++){
            subarrayMax = max(subarrayMax, arr[i]);
            subarrayMin = min(subarrayMin, arr[i]);
        }
        cout << low << ", "<< high << endl;
        cout << subarrayMin << ", "<< subarrayMax << endl;
        while((low > 0) && (arr[low-1] > subarrayMin)){
            low--;
        }
        while((high < arr.size() - 1) && (arr[high+1] < subarrayMax)){
            high++;
        }
        return make_pair(low, high);
    }
};

int main(){
    vector<int> arr = {1, 2, 3, 7, 11, 6, 8, 9, 10, 12};
    auto result = ShortestWindowSort::sort(arr);
    cout << "start="<<result.first<< ", "<<"end="<<result.second<<endl;
    return 0;
}