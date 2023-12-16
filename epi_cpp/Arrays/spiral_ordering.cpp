#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void MatrixLayerInClockwise(const vector<vector<int>>& square_matrix, int offset, vector<int>& spiral_ordering){
    if(offset == square_matrix.size() - offset - 1){
        spiral_ordering.emplace_back(square_matrix[offset][offset]);
        return;
    }
    for(int j = offset; j < square_matrix.size() - offset - 1; ++j){
        spiral_ordering.emplace_back(square_matrix[offset][j]);
    }
    for(int i = offset; i < square_matrix.size() - offset - 1; ++i){
        spiral_ordering.emplace_back(square_matrix[i][square_matrix.size() - offset - 1]);
    }
    for(int j = square_matrix.size() - offset - 1; j > offset; --j){
        spiral_ordering.emplace_back(square_matrix[square_matrix.size() - offset - 1][j]);
    }
    for(int i = square_matrix.size() - offset - 1; i > offset; --i){
        spiral_ordering.emplace_back(square_matrix[i][offset]);
    }
}

vector<int> MatrixInSpiralOrder(const vector<vector<int>>& square_matrix){
    vector<int> spiral_ordering;
    for(int offset = 0; offset < ceil(0.5 * square_matrix.size()); ++offset){
        MatrixLayerInClockwise(square_matrix, offset, spiral_ordering);
    }
    return spiral_ordering;
}

int main(){
    vector<vector<int>> square_matrix{{1,2,3},{4,5,6},{7,8,9}};
    auto result = MatrixInSpiralOrder(square_matrix);
    for(auto item : result){
        cout << item << " ";
    }
    cout << endl;
    return 0;
}