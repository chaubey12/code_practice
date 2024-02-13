#include <iostream>
#include <vector>
#include <functional>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int GCD(int x, int y){
    return y == 0 ? x : GCD(y, x%y);
}

struct Point{
    bool operator==(const Point& that) const{
        return x == that.x && y == that.y;
    }
    int x, y;
};

struct HashPoint{
    size_t operator()(const Point& p) const{
        return hash<int>()(p.x) ^ hash<int>()(p.y);
    }
};

struct Rational{
    int numerator, denominator;
    bool operator==(const Rational& that) const{
        return (numerator == that.numerator) && (denominator == that.denominator);
    }
};

Rational GetCanonicalForm(int a, int b){
    int gcd = GCD(abs(a), abs(b));
    a /= gcd, b /= gcd;
    return (b < 0) ? Rational{-a, -b} : Rational{a, b};
}

struct Line{
    Rational slope;
    Rational intercept;
    Line(const Point& a, const Point& b){
        slope = (a.x != b.x) ? GetCanonicalForm(b.y - a.y, b.x - a.x) : Rational{1, 0};
        intercept = (a.x != b.x) ? GetCanonicalForm(b.x*a.y - a.x*b.y, b.x - a.x) : Rational{a.x, 1};
    }
    bool operator==(const Line& that) const{
        return slope == that.slope && intercept == that.intercept;
    }
};

struct HashLine{
    size_t operator()(const Line& l) const{
        return hash<int>()(l.slope.numerator)^
               hash<int>()(l.slope.denominator)^
               hash<int>()(l.intercept.numerator)^
               hash<int>()(l.intercept.denominator);
    }
};

Line FindLineWithMostPoints(const vector<Point>& P){
    unordered_map<Line, unordered_set<Point, HashPoint>, HashLine> table;
    for(int i=0; i < P.size(); ++i){
        for(int j=i+1; j < P.size(); ++j){
            Line l(P[i], P[j]);
            table[l].emplace(P[i]);
            table[l].emplace(P[j]);
        }
    }
    return max_element(table.cbegin(), table.cend(), [](const pair<Line, unordered_set<Point, HashPoint>>& a, const pair<Line, unordered_set<Point, HashPoint>>& b){
        return a.second.size() < b.second.size();
    })->first;
}

int main(){
    vector<Point> points {{-1,-3}, {4,6}, {2,7}, {10,-2}, {7,3}, {0,0}, {13,13}, {-4,6}};
    auto result = FindLineWithMostPoints(points);
    cout << "Line with most points has slope=" << (double)(result.slope.numerator/result.slope.denominator) 
         <<" and intercept="<<(double)(result.intercept.numerator/result.intercept.denominator)<<endl;
    return 0;
}