#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct MaxHW{
    int h, w;
};

int MaxSquareSubmatrix(const vector<deque<bool>>& A){
    vector<vector<MaxHW>> table(A.size(), vector<MaxHW>(A.front().size()));
    for(int i=A.size()-1; i >= 0; --i){
        for(int j=A[i].size()-1; j >= 0; --j){
            table[i][j] = 
                A[i][j] ? MaxHW{(i < (A.size()-1)) ? table[i+1][j].h + 1: 1,
                                (j < (A[i].size() - 1)) ? table[i][j+1].w + 1 : 1}
                                : MaxHW{0, 0};
        }
    }
    vector<vector<int>> s(A.size(), vector<int>(A.front().size(), 0));
    int max_square_area = 0;
    for(int i=A.size()-1; i >= 0; --i){
        for(int j=A[i].size()-1; j >= 0; --j){
            int side = min(table[i][j].h, table[i][j].w);
            if(A[i][j]){
                if((i < A.size() - 1) && (j < A[i+1].size() - 1)){
                    side = min(s[i+1][j+1] + 1, side);
                }
                s[i][j] = side;
                max_square_area = max(max_square_area, side*side);
            }
        }
    }
    return max_square_area;
}

int main(){
    vector<deque<bool>> A { {false, true, true, true, false},
                            {false, true, true, true, false},
                            {false, false, true, true, false},
                            {false, false, true, true, false}};
    cout << "Max Square Area : "<<MaxSquareSubmatrix(A) << endl;
    return 0;
}