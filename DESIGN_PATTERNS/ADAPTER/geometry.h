#pragma once
#include <vector>
#include <functional>

using namespace std;

struct Point{
    int x, y;
    size_t hash_point(const Point& obj){
        return hash<int>()(obj.x)^hash<int>()(obj.y);
    }
};

struct Line{
    Point start, end;
    size_t hash_line(const Line& line){
        return Point::hash_point(line.start)^Point::hash_point(line.end);
    }
};

struct VectorObject{
    virtual vector<Line>::iterator begin();
    virtual vector<Line>::iterator end();
};

struct VectorRectangle : VectorObject{
    VectorRectangle(int x, int y, int width, int height){
        lines.emplace_back(Line{Point{x, y}, Point{x + width, y}});
        lines.emplace_back(Line{Point{x + width, y}, Point{x + width, y + height}});
        lines.emplace_back(Line{Point{x, y}, Point{x, y + height}});
        lines.emplace_back(Line{Point{x, y+height}, Point{x + width, y + height}});
    }
private:
    vector<Line> lines;
};