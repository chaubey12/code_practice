#include <iostream>
#include <vector>

using namespace std;
int MinimumPathWeight(const vector<vector<int>> &triangle){
    if(triangle.empty()){
        return 0;
    }
    vector<int> prev_row(triangle.front());
    for(int i=1; i < triangle.size(); ++i){
        vector<int> curr_row(triangle[i]);
        curr_row.front() += prev_row.front();
        for(int j=1; j < curr_row.size() - 1; ++j){
            curr_row[j] += min(prev_row[j-1], prev_row[j]);
        }
        curr_row.back() += prev_row.back();
        prev_row.swap(curr_row);
    }
    return *min_element(prev_row.cbegin(), prev_row.cend());
}

int main(){
    vector<vector<int>> triangle;
    triangle.emplace_back(vector<int>{2});
    triangle.emplace_back(vector<int>{4,4});
    triangle.emplace_back(vector<int>{8,5,6});
    triangle.emplace_back(vector<int>{4,2,6,2});
    triangle.emplace_back(vector<int>{1,5,2,3,4});
    cout << MinimumPathWeight(triangle)<<endl;
    return 0;
}