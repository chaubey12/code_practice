#include <iostream>
#include <vector>
#include <functional>
#include <tuple>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct HashTuple{
    size_t operator()(const tuple<int, int, int>& t) const{
        return hash<int>()(get<0>(t)^get<1>(t)*1021^get<2>(t)*1048573);
    }
};

bool IsPatternSuffixContainedStartingAtXY(const vector<vector<int>>& grid, int x, int y, const vector<int>& pattern, 
                                          int offset, unordered_set<tuple<int, int, int>, HashTuple>* previous_attempts){
    if(pattern.size() == offset){
        return true;
    }
    if((x < 0) || (x > grid.size()) || (y < 0) || (y >= grid[x].size()) ||
       (previous_attempts->find({x, y, offset}) != previous_attempts->cend())){
       return false;
    }
    if((grid[x][y] == pattern[offset]) &&(
        IsPatternSuffixContainedStartingAtXY(grid, x-1, y, pattern, offset+1, previous_attempts) ||
        IsPatternSuffixContainedStartingAtXY(grid, x+1, y, pattern, offset+1, previous_attempts) ||
        IsPatternSuffixContainedStartingAtXY(grid, x, y-1, pattern, offset+1, previous_attempts) ||
        IsPatternSuffixContainedStartingAtXY(grid, x, y+1, pattern, offset+1, previous_attempts))){
            return true;
    }
    previous_attempts->emplace(x, y, offset);
    return false;
}

bool IsPatternContainedInGrid(const vector<vector<int>>& grid, const vector<int>& pattern){
    unordered_set<tuple<int,int,int>, HashTuple> previous_attempts;
    for(int i=0; i < grid.size(); ++i){
        for(int j=0; j < grid[i].size(); ++j){
            if(IsPatternSuffixContainedStartingAtXY(grid, i, j, pattern, 0, &previous_attempts)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    vector<vector<int>> grid {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20}};
    vector<int> pattern{1,2,7,12,13,14,19,20};
    if(IsPatternContainedInGrid(grid, pattern)){
        cout << "PATTERN CONTAINED IN GRID"<<endl;
    }else{
        cout << "PATTERN NOT CONTAINED IN GRID"<<endl;
    }
    vector<int> pattern1{1,2,7,12,13,14,19,21};
    if(IsPatternContainedInGrid(grid, pattern1)){
        cout << "PATTERN CONTAINED IN GRID"<<endl;
    }else{
        cout << "PATTERN NOT CONTAINED IN GRID"<<endl;
    }
    return 0;
}