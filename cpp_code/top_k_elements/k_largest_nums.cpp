#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

class KLargestNumbers{
public:
    struct greater{
        bool operator()(const int& a, const int& b){
            return a > b;
        }
    };
    static vector<int> find(const vector<int>& arr, int k){
        vector<int> minHeap(arr.begin(), arr.begin() + k);
        make_heap(minHeap.begin(), minHeap.end(), greater());
        for(int i = k; i < arr.size(); i++){
            if(arr[i] > minHeap.front()){
                pop_heap(minHeap.begin(), minHeap.end(), greater());
                minHeap.pop_back();
                minHeap.push_back(arr[i]);
                push_heap(minHeap.begin(), minHeap.end(), greater());
            }
        }
        return minHeap;
    }
};

int main(){
    vector<int> arr = { 1, 3, 9, 7, 2, 6};
    int k = 3;
    auto result = KLargestNumbers::find(arr, k);
    for(auto item : result){
        cout << item << " ";
    }
    cout << endl;
    return 0;
}