#include <iostream>
#include <stack>
#include <vector>
#include <sstream>

using namespace std;

vector<int> ExamineBuildingsWithSunset(istringstream* sin){
    int building_idx=0, building_height;
    struct BuildingWithHeight{
        int id, height;
    };
    stack<BuildingWithHeight> candidates;
    while(*sin >> building_height){
        while(!candidates.empty() && 
              building_height >= candidates.top().height){
            candidates.pop();
        }
        candidates.emplace(BuildingWithHeight{building_idx++, building_height});
    }
    vector<int> buildings_with_sunset;
    while(!candidates.empty()){
        buildings_with_sunset.emplace_back(candidates.top().id);
        candidates.pop();
    }
    return buildings_with_sunset;
}

int main(){
    return 0;
}