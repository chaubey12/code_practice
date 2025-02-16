#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

struct Comp{
    bool operator()(pair<int, int>& p1, pair<int, int>& p2){
        return p1.second > p2.second;
    }
};

vector<int> TopKFrequent(const vector<int>& nums, int k){
    unordered_map<int, int> numFrequencyMap;
    for(int num : nums){
        ++numFrequencyMap[num];
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> topKElements;
    for(auto& entry : numFrequencyMap){
        topKElements.emplace(entry);
        if(topKElements.size() > k){
            topKElements.pop();
        }
    }
    vector<int> result;
    while(!topKElements.empty()){
        result.emplace_back(topKElements.top().first);
        topKElements.pop();
    }
    return result;
}


int main(){
    vector<int> nums{1, 3, 5, 12, 11, 12, 11, 12, 5, 1, 3, 5, 14, 18, 14, 5};
    int k = 3;
    auto result = TopKFrequent(nums, k);
    for(int a : result){
        cout << a << " ";
    }
    cout << endl;
    return 0;
}