#include <iostream>
#include <vector>
#include <functional>
#include <unordered_set>

using namespace std;

struct Jug{
    int low, high;
};

struct VolumeRange{
    int low, high;
    bool operator==(const VolumeRange& that) const{
        return low == that.low && high == that.high;
    }
};

struct HashVolumeRange{
    size_t operator()(const VolumeRange &p) const{
        return hash<int>()(p.low) ^ hash<int>()(p.high);
    }
};

bool CheckFeasibleHelper(const vector<Jug>& jugs, int L, int H, unordered_set<VolumeRange, HashVolumeRange>* c){
    if(L > H || c->find({L, H}) != c->cend() || (L < 0 && H < 0)){
        return false;
    }
    for(const Jug& j : jugs){
        if((L <= j.low && j.high <= H) || CheckFeasibleHelper(jugs, L - j.low, H - j.high, c)){
            return true;
        }
    }
    c->emplace(VolumeRange{L, H});
    return false;
}

bool CheckFeasible(const vector<Jug>& jugs, int L, int H){
    unordered_set<VolumeRange, HashVolumeRange> cache;
    return CheckFeasibleHelper(jugs, L, H, &cache);
}

int main(){
    vector<Jug> jugs{{230, 240}, {290, 310}, {500, 515}};
    int L = 2100, H = 2300;
    if(CheckFeasible(jugs, L, H)){
        cout << "FEASIBLE" <<endl;
    }else{
        cout << "NOT FEASIBLE" <<endl;
    }
    return 0;
}