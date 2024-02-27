#include <iostream>
#include <vector>
#include <memory>
#include "geometry.h"
#include <functional>
#include <map>

using namespace std;

vector<shared_ptr<VectorObject>> vectorObjects{
    make_shared<VectorRectangle>(10, 10, 100, 100),
    make_shared<VectorRectangle>(30, 30, 60, 60)
};

struct LineToPointCachingAdapter{
    typedef vector<Point> Points;
    LineToPointCachingAdapter(Line& line){

    }
private:
    map<size_t, Points> cache;
};

struct LineToPointAdapter{
    typedef vector<Point> Points;
    LineToPointAdapter(Line& line){
        static int count = 0;
        cout << count++<<" : Generating points for line(no caching)" << endl;
        int left = min(line.start.x, line.end.x);
        int right = max(line.start.x, line.end.x);
        int top = min(line.start.y, line.end.y);
        int bottom = max(line.start.y, line.end.y);
        int dx = right - left;
        int dy = line.end.y - line.start.y;
        if (dx == 0)
        {
            for (int y = top; y <= bottom; ++y)
            {
                points.emplace_back(Point{ left,y });
            }
        }   
        else if (dy == 0)
        {
            for (int x = left; x <= right; ++x)
            {
                points.emplace_back(Point{ x, top });
            }
        }
    }
    virtual Points::iterator begin() { return points.begin(); }
    virtual Points::iterator end() { return points.end(); }
private:
    Points points;
};

void DrawPoints(vector<Point>::iterator start, vector<Point>::iterator end){
    for(auto i = start; i != end; ++i){
        cout << i->x << ", "<<i->y<<endl;
    }
}

int main(){
    return 0;
}