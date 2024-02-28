#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct Rectangle{
    int left, right, height;
};

typedef vector<Rectangle> Skyline;

Skyline ComputeSkyline(const vector<Rectangle>& buildings){
    int min_left = numeric_limits<int>::max();
    int max_right = numeric_limits<int>::min();
    for(const Rectangle& building : buildings){
        min_left = min(building.left, min_left);
        max_right = max(building.right, max_right);
    }
    vector<int> heights(max_right - min_left + 1, 0);
    for(const Rectangle& building : buildings){
        for(int i=building.left; i <= building.right; ++i){
            heights[i-min_left] = max(heights[i - min_left], building.height);
        }
    }
    Skyline result;
    int left=0;
    for(int i=1; i < heights.size(); ++i){
        if(heights[i] != heights[i-1]){
            result.emplace_back(Rectangle{left + min_left, i-1 + min_left, heights[i-1]});
            left = i;
        }
    }
    result.emplace_back(Rectangle{left + min_left, max_right, heights.back()});
    return result;
}

int main(){
    vector<Rectangle> rectangles{{0, 1, 1}, {1, 6, 3}, {4, 8, 4}, {5, 9, 2}, {7, 14, 3},{10, 12, 6}, {11, 17, 1}, {13, 16, 2}};
    auto result = ComputeSkyline(rectangles);
    for(auto res : result){
        cout << res.left << ", "<<res.right << ", "<<res.height<<endl;
    }
    return 0;
}