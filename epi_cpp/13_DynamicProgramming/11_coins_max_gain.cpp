#include <iostream>
#include <vector>

using namespace std;

int ComputeMaximumRevanueForRange(const vector<int>& coins, int a, int b, 
                                  vector<vector<int>>* maximum_revanue_for_range_ptr){
    if(a > b){
        return 0;
    }
    vector<vector<int>>& maximum_revanue_for_range = *maximum_revanue_for_range_ptr;
    if(maximum_revanue_for_range[a][b] == 0){
        int max_revanue_a = coins[a] + 
            min(ComputeMaximumRevanueForRange(coins, a + 2, b, maximum_revanue_for_range_ptr),
                ComputeMaximumRevanueForRange(coins, a + 1, b - 1, maximum_revanue_for_range_ptr));

        int max_revanue_b = coins[b] + 
            min(ComputeMaximumRevanueForRange(coins, a + 1, b - 1, maximum_revanue_for_range_ptr),
                ComputeMaximumRevanueForRange(coins, a, b - 2, maximum_revanue_for_range_ptr));

        maximum_revanue_for_range[a][b] = max(max_revanue_a, max_revanue_b);
    }
    return maximum_revanue_for_range[a][b];
}

int MaximumRevanue(const vector<int>& coins){
    vector<vector<int>> maximum_revanue_for_range(coins.size(), vector<int>(coins.size(), 0));
    return ComputeMaximumRevanueForRange(coins, 0, coins.size() - 1, &maximum_revanue_for_range);
}

int main(){
    // vector<int> coins{5, 25, 10, 1};
    vector<int> coins{10, 25, 5, 1, 10, 5};
    cout << MaximumRevanue(coins)<<endl;
    return 0;
}