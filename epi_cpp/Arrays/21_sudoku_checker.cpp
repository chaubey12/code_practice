#include <iostream>
#include <vector>
#include <deque>
#include <cmath>

using namespace std;

bool HasDuplicate(const vector<vector<int>>& partial_assignment, int row_start, int row_end, int col_start, int col_end){
    deque<bool> is_present(partial_assignment.size()+1, false);
    for(int i = row_start; i < row_end; ++i){
        for(int j = col_start; j < col_end; ++j){
            if(partial_assignment[i][j] != 0 &&
                is_present[partial_assignment[i][j]]){
                    return true;
            }
            is_present[partial_assignment[i][j]] = true;
        }
    }
    return false;
}


bool IsValidSudoku(const vector<vector<int>>& partial_assignment){
    for(int i=0; i < partial_assignment.size(); ++i){
        if(HasDuplicate(partial_assignment, i, i+1, 0, partial_assignment.size())){
            return false;
        }
    }
    for(int j=0; j < partial_assignment.size(); ++j){
        if(HasDuplicate(partial_assignment, 0, partial_assignment.size(), j, j+1)){
            return false;
        }
    }
    int region_size=sqrt(partial_assignment.size());
    for(int I = 0; I < region_size; ++I){
        for(int J = 0; J < region_size; ++J){
            if(HasDuplicate(partial_assignment, region_size*I, region_size*(I+1), region_size*J, region_size*(J+1))){
                return false;
            }
        }
    }
    return true;
}

int main(){
    vector<vector<int>>partial_assignment;
    partial_assignment.push_back({5,3,4,6,7,8,9,1,2});
    partial_assignment.push_back({6,7,2,1,9,5,3,4,8});
    partial_assignment.push_back({1,9,8,3,4,2,5,6,7});
    partial_assignment.push_back({8,5,9,7,6,1,4,2,3});
    partial_assignment.push_back({4,2,6,8,5,3,7,9,1});
    partial_assignment.push_back({7,1,3,9,2,4,8,5,6});
    partial_assignment.push_back({9,6,1,5,3,7,2,8,4});
    partial_assignment.push_back({2,8,7,4,1,9,6,3,5});
    partial_assignment.push_back({3,4,5,2,8,6,1,7,9});
    if(IsValidSudoku(partial_assignment)){
        cout << "VALID SUDOKU"<<endl;
    }else{
        cout << "INVALID SUDOKU"<<endl;
    }
    return 0;
}