#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <array>

using namespace std;

const char B = 'B';
const char W = 'W';

void MarkBoundaryRegion(int i, int j, const vector<vector<char>>& board, vector<deque<bool>> *visited_ptr){
    struct Coordinate{
        int x, y;
    };
    queue<Coordinate> q;
    vector<deque<bool>>& visited = *visited_ptr;
    q.emplace(Coordinate{i, j});
    visited[i][j] = true;
    while(!q.empty()){
        const Coordinate curr = q.front();
        const static array<array<int, 2>, 4> kDirs = {{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}};
        for(const array<int, 2>& d : kDirs){
            const Coordinate next = {curr.x + d[0], curr.y + d[1]};
            if(next.x >= 0 && next.x < board.size() && 
              next.y >= 0 && next.y < board[next.x].size() &&
              board[next.x][next.y] == W && !visited[next.x][next.y]){
                visited[next.x][next.y] = true;
                q.emplace(next);
            }
        }
        q.pop();
    }
}

void FillSurroundingRegions(vector<vector<char>>* board_ptr){
    vector<vector<char>>& board = *board_ptr;
    if(board.empty()){
        return;
    }
    vector<deque<bool>> visited(board.size(), deque<bool>(board.front().size(), false));
    for(int i=0; i < board.size(); ++i){
        if(board[i][0] == W && !visited[i][0]){
            MarkBoundaryRegion(i, 0, board, &visited);
        }
        if(board[i][board[i].size() - 1] == W && !visited[i][board[i].size() - 1]){
            MarkBoundaryRegion(i, board[i].size() - 1, board, &visited);
        }
    }
    for(int j=0; j < board.front().size(); ++j){
        if(board[0][j] == W && !visited[0][j]){
            MarkBoundaryRegion(0, j, board, &visited);
        }
        if(board[board.front().size() - 1][j] == W && !visited[board.front().size() - 1][j]){
            MarkBoundaryRegion(board.front().size() - 1, j, board, &visited);
        }
    }
    for(int i=1; i < board.size() - 1; ++i){
        for(int j=1; j < board[i].size() - 1; ++j){
            if(board[i][j] == W && !visited[i][j]){
                board[i][j] = B;
            }
        } 
    }
}

int main(){
    vector<vector<char>> board = {{B, B, B, B},
                                  {W, B, W, B},
                                  {B, W, W, B},
                                  {B, B, B, B}};
    cout << "BEFORE FILLING"<<endl;
    for(auto row : board){
        for(auto elem : row){
            cout << elem << " ";
        }
        cout << endl;
    }
    cout << "AFTER FILLING"<<endl;
    FillSurroundingRegions(&board);
    for(auto row : board){
        for(auto elem : row){
            cout << elem << " ";
        }
        cout << endl;
    }
    return 0;
}