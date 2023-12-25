#include <iostream>
#include <vector>
#include <deque>
#include <memory>
#include <array>
#include <queue>

using namespace std;

void FlipColor(int x, int y, vector<deque<bool>>* A_ptr){
    vector<deque<bool>>& A = *A_ptr;
    const array<array<int, 2>, 4> kDirs = {{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}};
    const bool color = A[x][y];
    struct Coordinate{
        int x, y;
    };
    A[x][y] = !color;
    for(const array<int, 2>& s : kDirs){
        const int next_x = x + s[0], next_y = y + s[1];
        if(next_x >= 0 && next_x < A.size() && next_y >= 0 && next_y < A[next_x].size() && A[next_x][next_y] == color){
            FlipColor(next_x, next_y, A_ptr);
        }
    }
}

int main(){
    vector<deque<bool>> A = {{true, false, true, false, false, false, true, true, true, true},
                             {false, false, true, false, false, true, false, false, true, true},
                             {true, true, true, false, false, true, true, false, true, true},
                             {false, true, false, true, true, true, true, false, true, false},
                             {true, false, true, false, false, false, false, true, false, false},
                             {true, false, true, false, false, true, false, true, true, true},
                             {false, false, false, false, true, false, true, false, false, true},
                             {true, false, true, false, true, false, true, false, false, false},
                             {true, false, true, true, false, false, false, true, true, true},
                             {false, false, false, false, false, false, false, true, true, false}};
    cout << "BEFORE FLIPPING" <<endl;
    for(auto row : A){
        for(auto elem : row){
            cout << elem << " ";
        }
        cout << endl;
    }
    FlipColor(5, 4, &A);
    cout << "AFTER FLIPPING" <<endl;
    for(auto row : A){
        for(auto elem : row){
            cout << elem << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}