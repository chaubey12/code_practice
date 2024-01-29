#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int LongestContainedRange(const vector<int>& A){
    unordered_set<int> unprocessed_entries(A.begin(), A.end());
    int upper_bound=0, lower_bound=0;
    int max_interval_size = 0;
    while(!unprocessed_entries.empty()){
        int a = *unprocessed_entries.begin();
        unprocessed_entries.erase(a);    
        
        lower_bound = a-1;
        while(unprocessed_entries.count(lower_bound)){
            unprocessed_entries.erase(lower_bound);
            --lower_bound;
        }
        upper_bound = a+1;
        while(unprocessed_entries.count(upper_bound)){
            unprocessed_entries.erase(upper_bound);
            ++upper_bound;
        }
        max_interval_size = max(max_interval_size, upper_bound - lower_bound - 1);
    }
    return max_interval_size;
}

int main(){
    vector<int> A{3, -2, 7, 9, 8, 1, 2, 0, -1, 5, 8};
    cout << LongestContainedRange(A)<<endl;
    return 0;
}