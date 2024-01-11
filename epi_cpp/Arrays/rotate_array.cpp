#include <iostream>
#include <vector>

using namespace std;

void RotateMatrix(vector<vector<int>>* square_matrix_ptr){
    vector<vector<int>>& square_matrix = *square_matrix_ptr;
    const int matrix_size = square_matrix.size() - 1;
    for(int i=0; i < (square_matrix.size()/2); ++i){
        for(int j=i; j < matrix_size - i; ++j){
            int temp1 = square_matrix[matrix_size - j][i];
            int temp2 = square_matrix[matrix_size - i][matrix_size - j];
            int temp3 = square_matrix[j][matrix_size - i];
            int temp4 = square_matrix[i][j];
            square_matrix[i][j] = temp1;
            square_matrix[matrix_size - j][i] = temp2;
            square_matrix[matrix_size - i][matrix_size - j] = temp3;
            square_matrix[j][matrix_size - i] = temp4;

        }
    }
}

void PrintMatrix(vector<vector<int>>& square_matrix){
    for(auto row : square_matrix){
        for(auto elem : row){
            cout << elem <<" ";
        }
        cout << endl;
    }
}

int main(){
    vector<vector<int>> square_matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    PrintMatrix(square_matrix);
    RotateMatrix(&square_matrix);
    cout << "Matrix After Rotation"<<endl;
    PrintMatrix(square_matrix);
    return 0;
}