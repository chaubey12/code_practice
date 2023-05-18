#include <iostream>
#include <vector>
#include <array>

using namespace std;

vector<int> MatricInSpiralOrder(vector<vector<int>>& square_matrix){
    const array<array<int, 2>, 4> kShift = {{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};
    int dir = 0, x = 0, y = 0;
    vector<int> spiral_ordering;
    for(int i = 0; i < square_matrix.size()*square_matrix.size(); ++i){
        spiral_ordering.emplace_back(square_matrix[x][y]);
        square_matrix[x][y] = 0;
        int next_x = x + kShift[dir][0], next_y = y + kShift[dir][1];
        if(next_x < 0 || next_x >= square_matrix.size() || next_y < 0 ||
        next_y > square_matrix.size() || square_matrix[next_x][next_y] == 0){
            dir = (dir+1)%4;
            next_x = x + kShift[dir][0], next_y = y + kShift[dir][1];
        }
        x = next_x, y = next_y;
    }
    return spiral_ordering;
}

int main(){
    vector<vector<int>> mat;
    mat.emplace_back(vector<int>{1,2,3});
    mat.emplace_back(vector<int>{4,5,6});
    mat.emplace_back(vector<int>{7,8,9});
    auto result = MatricInSpiralOrder(mat);
    for(auto i : result){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}