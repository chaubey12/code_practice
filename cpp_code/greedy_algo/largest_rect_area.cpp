#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool IsNewPillarOrReachEnd(const vector<int>& heights, int curr_idx, int last_pillar_idx){
    return curr_idx < heights.size() ? heights[curr_idx] < heights[last_pillar_idx] : true; 
}


int CalculateMaxRectArea(const vector<int>& heights){
    stack<int> pillar_indices;
    int max_rect_area = 0;
    for(int i=0; i <= heights.size(); ++i){
        if(!pillar_indices.empty() && i < heights.size() &&
        heights[i] == heights[pillar_indices.top()]){
            pillar_indices.pop();
            pillar_indices.push(i);
        }
        while(!pillar_indices.empty() && IsNewPillarOrReachEnd(heights, i, pillar_indices.top())){
            int height = heights[pillar_indices.top()];
            pillar_indices.pop();
            int width = pillar_indices.empty() ? i : i - pillar_indices.top() - 1;
            max_rect_area = max(max_rect_area, height*width);
        }
        pillar_indices.push(i);
    }
    return max_rect_area;
}

int main(){
    vector<int> arr = {1, 4, 2, 5, 6, 1, 2, 6, 0, 5, 2, 1, 3};
    cout << "Max Rect Area: " << CalculateMaxRectArea(arr) << endl;
    return 0;
}