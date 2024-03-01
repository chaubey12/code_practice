#include <iostream>
#include <vector>
#include <memory>

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
    Side sides[4];
public:
    bool checkCorner(){}
    bool checkEdge(){}
    bool checkMiddle(){}
};

class Puzzle{
private:
    static Puzzle *puzzle;
    vector<vector<Piece>> board;
    vector<Piece> free;
public:
    void insertPiece(Piece piece, int row, int column) {}
    static Puzzle *getInstance(){
        if(puzzle == nullptr){
            puzzle = new Puzzle();
        }
        return puzzle;
    }
};

class PuzzleSolverf{
public:
    Puzzle matchPieces(Puzzle board){}
};

