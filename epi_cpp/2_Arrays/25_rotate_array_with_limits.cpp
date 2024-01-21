#include <iostream>
#include <vector>

using namespace std;

class RotatedMatrix{
private:
    vector<vector<int>>& square_matrix_;
public:
    explicit RotatedMatrix(vector<vector<int>>* square_matrix)
        : square_matrix_(*square_matrix){}
    
    int ReadEntry(int i, int j) const{
        return square_matrix_[square_matrix_.size() - 1 - j][i];
    }

    int WriteEntry(int i, int j, int v){
        square_matrix_[square_matrix_.size() - 1 - j][i] = v;
    }

};