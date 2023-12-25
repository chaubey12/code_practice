#include <iostream>
#include <vector>
#include <array>

using namespace std;
typedef enum {WHITE, BLACK} Color;

struct Coordinate{
    bool operator==(const Coordinate& that) const{
        return that.x == x && that.y == x;
    }
    int x, y;
};

bool IsFeasible(const Coordinate& cur, const vector<vector<Color>>& maze){
    return cur.x >= 0 && cur.x < maze.size() && cur.y >= 0 && cur.y < maze[cur.x].size() && maze[cur.x][cur.y] == WHITE;
}


bool SearchMazeHelper(const Coordinate& cur, const Coordinate& dest, vector<vector<Color>>* maze, vector<Coordinate>* path){
    if(cur == dest){
        return true;
    }
    const array<array<int, 2>, 4> kShift = {{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}};
    for(const array<int, 2>& s : kShift){
        Coordinate next{cur.x + s[0], cur.y + s[1]};
        if(IsFeasible(next, *maze)){
            (*maze)[next.x][next.x] = BLACK;
        }
    }
    return false;
}

vector<Coordinate> SearchMaze(vector<vector<Color>> maze, const Coordinate& s, const Coordinate& e){
    vector<Coordinate> path;
    maze[s.x][s.y] = BLACK;
    path.emplace_back(s);
    if(!SearchMazeHelper(s, e, &maze, &path)){
        path.pop_back();
    }
    return path;
}


int main(){
    vector<vector<Color>> maze{
                {BLACK, WHITE, WHITE, WHITE, WHITE, WHITE, BLACK, BLACK, WHITE, WHITE},
                {WHITE, WHITE, BLACK, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE},
                {BLACK, WHITE, BLACK, WHITE, WHITE, BLACK, BLACK, WHITE, BLACK, BLACK},
                {WHITE, WHITE, WHITE, BLACK, BLACK, BLACK, WHITE, WHITE, WHITE, WHITE},
                {WHITE, BLACK, BLACK, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE},
                {WHITE, BLACK, BLACK, WHITE, WHITE, BLACK, WHITE, BLACK, BLACK, WHITE},
                {WHITE, WHITE, WHITE, WHITE, BLACK, WHITE, WHITE, WHITE, WHITE, WHITE},
                {BLACK, WHITE, BLACK, WHITE, BLACK, WHITE, BLACK, WHITE, WHITE, WHITE},
                {BLACK, WHITE, BLACK, BLACK, WHITE, WHITE, WHITE, BLACK, BLACK, BLACK},
                {WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, BLACK, BLACK, WHITE}};
    Coordinate start = {maze.size() - 1, 0};
    Coordinate end = {0, maze.size() - 1};
    auto path = SearchMaze(maze, start, end);
    for(auto elem : path){
        cout << "{"<< elem.x<<", "<< elem.y << "}"<<endl;
    }
    return 0;
}