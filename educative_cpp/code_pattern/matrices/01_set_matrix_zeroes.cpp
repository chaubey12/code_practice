#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> SetMatrixZeros(vector<vector<int>>& mat){
    int rows = mat.size();
    int cols = mat[0].size();
    bool fcol = false;
    bool frow = false;
    for(int i=0; i < rows; ++i){
        if(mat[i][0] == 0){
            fcol = true;
            break;
        }
    }
    for(int i=0; i < cols; ++i){
        if(mat[0][i] == 0){
            frow = true;
            break;
        }
    }
    for(int i=1; i < rows; i++){
        for(int j=1; j < cols; j++){
            if(mat[i][j] == 0){
                mat[0][j] = 0;
                mat[i][0] = 0;
            }
        }
    }
    for(int i=1; i < rows; i++){
        if(mat[i][0] == 0){
            for(int j = 1; j < cols; j++){
                mat[i][j] = 0;
            }
        }
    }
    for(int j = 1; j < cols; j++){
        if(mat[0][j] == 0){
            for(int i=1; i < rows; i++){
                mat[i][j] = 0;
            }
        }
    }
    if(fcol){
        for(int i=0; i < rows; i++){
            mat[i][0] = 0;
        }
    }
    if(frow){
        for(int j=0; j < cols; j++){
            mat[0][j] = 0;
        }
    }
    return mat;
}

