#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> GeneratePascalsTriangle(int num_rows){
    vector<vector<int>> pascals_triangle;
    for(int i=0; i < num_rows; i++){
        vector<int> curr_row;
        for(int j=0; j <= i; j++){
            curr_row.emplace_back((0 < j && j < i) ? pascals_triangle.back()[j-1] + 
            pascals_triangle.back()[j] : 1);
        }
        pascals_triangle.emplace_back(curr_row);
    }
    return pascals_triangle;
}

int main(){
    int num_rows = 5;
    auto result = GeneratePascalsTriangle(num_rows);
    for(auto row : result){
        for(auto item : row){
            cout << item << " ";
        }
        cout << endl;
    }
    return 0;
}