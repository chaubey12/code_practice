#include <iostream>
#include <vector>
#include <memory>

using namespace std;

void DirectedPowerSet(const vector<int>& input_set, int to_be_selected, 
                      vector<int>* selected_so_far, vector<vector<int>>* power_set){
    if(to_be_selected == input_set.size()){
        power_set->emplace_back(*selected_so_far);
        return;
    }
    selected_so_far->emplace_back(input_set[to_be_selected]);
    DirectedPowerSet(input_set, to_be_selected + 1, selected_so_far, power_set);
    selected_so_far->pop_back();
    DirectedPowerSet(input_set, to_be_selected + 1, selected_so_far, power_set);
}

vector<vector<int>> GeneratePowerSet(const vector<int>& input_set){
    vector<vector<int>> power_set;
    DirectedPowerSet(input_set, 0, new vector<int>, &power_set);
    return power_set;
}

int main(){
    vector<int> A{1, 2, 3};
    auto result = GeneratePowerSet(A);
    for(auto res : result){
        for(auto elem : res){
            cout << elem << " "; 
        }
        cout << endl;
    }
    return 0;
}