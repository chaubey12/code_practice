#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class SparseVector{
private:
    unordered_map<int, int> hashmap;
public:
    SparseVector(vector<int>& nums){
        for(int i=0; i < nums.size(); ++i){
            if(nums[i] != 0){
                hashmap[i] = nums[i];
            }
        }
    }

    int DotProduct(SparseVector& vec){
        int sum=0;
        for(auto& [i, n] : hashmap){
            if(vec.hashmap.count(i)){
                sum += n * vec.hashmap[i];
            }
        }
        return sum;
    }
};