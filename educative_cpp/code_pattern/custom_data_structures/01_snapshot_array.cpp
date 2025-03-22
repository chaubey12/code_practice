#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class SnapshotArray{
public:
    int snapshotId;
    unordered_map<int, unordered_map<int, int>> nodeValue;
    int nCount;

    SnapshotArray(int length){
        snapshotId = 0;
        nCount = length;
    }

    void SetValue(int idx, int val){
        if(idx < nCount){
            nodeValue[snapshotId][idx] = val;
        }
    }

    int Snapshot(){
        nodeValue[snapshotId+1] = unordered_map<int, int>(nodeValue[snapshotId]);
        snapshotId++;
        return snapshotId - 1;
    }
    int GetValue(int idx, int snapshotId){
        if(snapshotId < this->snapshotId && snapshotId >= 0 && idx < nCount){
            if(nodeValue[snapshotId].find(idx) != nodeValue[snapshotId].end()){
                return nodeValue[snapshotId][idx];
            }else{
                return 0;
            }
        }
        return -1;
    }
};

int main(){
    vector<int> numNodes = {3, 5, 5, 3, 2};
    vector<vector<vector<int>>> nodeValues = {
        {{0, 5}, {0, 1}, {2, 3}, {1, 10}},
        {{4, 1}, {2, 21}},
        {{4, 12}, {2, 61}},
        {{0, 15}, {0, 5}, {2, 13}, {1, 100}},
        {{0, 32}, {0, 6}, {1, 2}}
    };
    vector<vector<vector<int>>> valuesToGet = {
        {{0, 0}, {0, 1}, {1, 0}},
        {{4, 1}, {2, 1}, {3, 1}},
        {{4, 1}, {2, 1}, {3, 1}},
        {{0, 1}, {1, 1}},
        {{0, 0}}
    };
    for(int i=0; i < numNodes.size(); i++){
        cout << i + 1 << ".\tInitializing a data structure with "<<numNodes[i]<<" nodes"<<endl;
        SnapshotArray snapshotArr(numNodes[i]);
        for(int j=0; j < nodeValues[i].size(); j++){
            snapshotArr.SetValue(nodeValues[i][j][0], nodeValues[i][j][1]);
            cout << "Snap id: "<<snapshotArr.Snapshot()<<endl;
        }
        for(int x=0; x < valuesToGet[i].size(); x++){
            cout << snapshotArr.GetValue(valuesToGet[i][x][0], valuesToGet[i][x][1]) << endl;
        }
        cout << "\n"<< string(100, '-') << endl;
    }
    return 0;
}