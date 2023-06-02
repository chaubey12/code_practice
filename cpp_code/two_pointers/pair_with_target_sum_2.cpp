#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;

class PairWithTargetSum{
public:
    static pair<int, int> search(const vector<int>& arr, int targetSum){
        unordered_map<int, int> elementIndexMap;
        for(int i = 0; i < arr.size(); i++){
            if(elementIndexMap.find(targetSum - arr[i]) != elementIndexMap.end()){
                return make_pair(i, elementIndexMap[targetSum - arr[i]]);
            }else{
                elementIndexMap[arr[i]] = i;
            }
        }
        return make_pair(-1, -1);
    }
};

int main(){
    vector<int> arr{5, 7, 2, 9, 11, 6};
    int targetSum=13;
    pair<int, int> result =  PairWithTargetSum::search(arr, targetSum);
    cout <<"{"<< result.first << ", "<< result.second << "}" << endl;
    return 0;
}