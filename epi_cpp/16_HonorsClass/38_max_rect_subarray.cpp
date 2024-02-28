#include <iostream>
#include <vector>
#include <deque>
#include <limits>

using namespace std;

struct MaxHW{
    int h, w;
};

int MaxRectangleSubmatrix(const  vector<deque<bool>>& A){
    vector<vector<MaxHW>> table(A.size(), vector<MaxHW>(A.front().size()));
    for(int i=A.size() - 1; i >= 0; --i){
        for(int j=A[i].size() - 1; j >= 0; --j){
            table[i][j] = A[i][j] ? MaxHW{(i < (A.size() - 1) ? table[i+1][j].h + 1 : 1),
                                          (j < (A[i].size() - 1) ? table[i][j+1].w + 1 : 1)}
                                  : MaxHW{0, 0};
        }
    }
    int max_rect_area=0;
    for(int i=0; i < A.size(); ++i){
        for(int j=0; j < A[i].size(); ++j){
            if(A[i][j] && (table[i][j].w * table[i][j].h) > max_rect_area){
                int min_width = numeric_limits<int>::max();
                for(int a=0; a < table[i][j].h; ++a){
                    min_width = min(min_width, table[i+a][j].w);
                    max_rect_area = max(max_rect_area, min_width*(a+1));
                }
            }
        }
    }
    return max_rect_area;
}


int main(){
    vector<deque<bool>> A { {false, true, true, true, false},
                            {false, true, true, true, false},
                            {false, true, true, true, false},
                            {false, false, true, true, false}};
    cout << "Max Rectangle Area : "<<MaxRectangleSubmatrix(A) << endl;
    return 0;
}