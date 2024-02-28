#include <iostream>
#include <vector>
#include <deque>
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

int MaxRectangleSubmatrix(vector<deque<bool>>& A){
    vector<int> table(A.front().size(), 0);
    int max_rect_area = 0;
    for(int i=0; i < A.size(); ++i){
        for(int j=0; j < A[i].size(); ++j){
            table[j] = A[i][j] ? table[j] + 1: 0;
        }
        max_rect_area = max(max_rect_area, CalculateLargestRestangle(table));
    }
    return max_rect_area;
}


int main(){
    vector<deque<bool>> A { {false, false, true, true, false},
                            {false, true, true, true, false},
                            {false, true, true, true, false},
                            {false, false, true, true, false}};
    cout << "Max Rectangle Area : "<<MaxRectangleSubmatrix(A) << endl;
    return 0;
}