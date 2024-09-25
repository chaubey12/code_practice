#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Point{
public:
    int x,y;
    Point(int X, int Y){
        this->x = X;
        this->y = Y;
    }
    int distFromOrigin(){
        return (x*x) + (y*y);
    } 
};

struct Comp{
    bool operator()(Point& a, Point& b){
        return a.distFromOrigin() < b.distFromOrigin();
    }
};

vector<Point> KClosest(vector<Point> locations, int k){
    priority_queue<Point, vector<Point>, Comp> minHeap;
    for(auto& location : locations){
        if(minHeap.size() < k){
            minHeap.emplace(location);
        }else{
            minHeap.emplace(location);
            minHeap.pop();
        }
    }
    vector<Point> result;
    while(!minHeap.empty()){
        result.emplace_back(minHeap.top());
        minHeap.pop();
    }
    return result;
}

int main(){
    vector<Point> pointsOne = {Point(1,3), Point(3,4), Point(2,-1)};
    auto result = KClosest(pointsOne, 2);
    for(auto item : result){
        cout << "(" << item.x << ", "<< item.y <<")" << endl;
    }

    return 0;
}

