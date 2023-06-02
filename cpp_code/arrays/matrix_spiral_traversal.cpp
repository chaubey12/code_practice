#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void MatrixLayerInClockwise(const vector<vector<int>>& square_matrix, int offset, vector<int>& spiral_order){
    if(offset == square_matrix.size() - offset - 1){
        spiral_order.emplace_back(square_matrix[offset][offset]);
        return;
    }
    for(int j = 0; j < square_matrix.size() - offset - 1; ++j){
        spiral_order.emplace_back(square_matrix[offset][j]);
    }

    for(int i = 0; i < square_matrix.size() - offset - 1; ++i){
        spiral_order.emplace_back(square_matrix[i][square_matrix.size() - offset - 1]);
    }

    for(int j = square_matrix.size() - offset - 1; j > offset; --j){
        spiral_order.emplace_back(square_matrix[square_matrix.size() - offset - 1][j]);
    }

    for(int i = square_matrix.size() - offset - 1; i > offset; --i){
        spiral_order.emplace_back(square_matrix[i][offset]);
    }
}

vector<int> MatricInSpiralOrder(const vector<vector<int>>& square_matrix){
    vector<int> spiral_order;
    for(int offset = 0; offset < ceil(0.5*square_matrix.size()); ++offset){
        MatrixLayerInClockwise(square_matrix, offset, spiral_order);
    }
    return spiral_order;
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