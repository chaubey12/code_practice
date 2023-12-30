#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool IsNowPillarOrReachedEnd(const vector<int>& heights, int curr_idx, int last_pillar_idx){
    return curr_idx < heights.size() 
        ? heights[curr_idx] < heights[last_pillar_idx]
        : true;
}


int CalculateLargestRestangle(const vector<int>& heights){
    stack<int> pillar_indices;
    int max_rectangle_area = 0;
    for(int i=0; i <= heights.size(); ++i){
        if(!pillar_indices.empty() && (i < heights.size()) && (heights[i] == heights[pillar_indices.top()])){
            pillar_indices.pop();
            pillar_indices.emplace(i);
        }
        while(!pillar_indices.empty() && IsNowPillarOrReachedEnd(heights, i, pillar_indices.top())){
            int height = heights[pillar_indices.top()];
            pillar_indices.pop();
            int width = pillar_indices.empty() ? i : i - pillar_indices.top() - 1;
            max_rectangle_area = max(max_rectangle_area, height*width);
        }
        pillar_indices.emplace(i);
    }
    return max_rectangle_area;
} 

int main(){
    vector<int> heights = {1, 4, 2, 5, 6, 3, 2, 6, 6, 5, 2, 1, 3};
    cout << "Max rectangle area is: "<<CalculateLargestRestangle(heights)<<endl;
    return 0;
}