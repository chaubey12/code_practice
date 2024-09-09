#include <iostream>
#include <array>
#include <vector>

using namespace std;

enum Edge{
    INDENTATION,
    EXTRUSION,
    FLAT
};

class Side{
private:
    Edge edge;
};

class Piece{
private:
    array<Side, 4> sides;
public:
    bool checkCorder(){}
    bool checkEdge(){}
    bool checkMiddle(){}
};

class Puzzle{
private:
    static Puzzle* puzzle;
    vector<vector<Piece>> board;
    vector<Piece> free;
public:
    static Puzzle* getInstance(){
        if(puzzle == nullptr){
            puzzle = new Puzzle();
        }
        return puzzle;
    }
};

class PuzzleSolver{
public:
    Puzzle matchPieces(Puzzle board){}
};