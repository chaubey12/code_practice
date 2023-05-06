#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int grid_size = 9;

bool HasDuplicates(const vector<vector<int>>& partial_assignments,
    int start_row, int end_row, int start_col, int end_col){
    vector<bool> is_present(partial_assignments.size() + 1, false);
    for(int i = start_row; i < end_row; i++){
        for(int j  = start_col; j < end_col; j++){
            if(partial_assignments[i][j] != 0 &&
            is_present[partial_assignments[i][j]]){
                return true;
            }
            is_present[partial_assignments[i][j]] = true;
        }
    }
    return false;
}

bool IsValidSudoku(const vector<vector<int>>& partial_assignments){
    for(int i = 0; i < partial_assignments.size(); i++){
        if(HasDuplicates(partial_assignments, i, i+1, 0, partial_assignments.size())){
            return false;
        }
    }

    for(int j = 0; j < partial_assignments.size(); j++){
        if(HasDuplicates(partial_assignments, 0, partial_assignments.size(), j, j+1)){
            return false;
        }
    }

    int region_size = sqrt(partial_assignments.size());
    for(int i = 0; i < region_size; i++){
        for(int j = 0; j < region_size; j++){
            if(HasDuplicates(partial_assignments, region_size*i, region_size*(i+1),
                region_size*j, region_size*(j+1))){
                    return false;
                }
        }
    }
    return true;
}

int main(){
    vector<vector<int>> solution;
    solution.emplace_back(vector<int>{5,3,4,6,7,8,9,1,2});
    solution.emplace_back(vector<int>{6,7,2,1,9,5,3,4,8});
    solution.emplace_back(vector<int>{1,9,8,3,4,2,5,6,7});
    solution.emplace_back(vector<int>{8,5,9,7,6,1,4,2,3});
    solution.emplace_back(vector<int>{4,2,6,8,5,3,7,9,1});
    solution.emplace_back(vector<int>{7,1,3,9,2,4,8,5,6});
    solution.emplace_back(vector<int>{9,6,1,5,3,7,2,8,4});
    solution.emplace_back(vector<int>{2,8,7,4,1,9,6,3,5});
    solution.emplace_back(vector<int>{3,4,5,2,8,6,1,7,9});
    if(IsValidSudoku(solution)){
        cout << "Valid Solution"<<endl;
    }else{
        cout << "Invalid Solution"<<endl;
    }
    return 0;
}