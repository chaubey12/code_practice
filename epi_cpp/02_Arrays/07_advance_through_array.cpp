#include <iostream>
#include <vector>

using namespace std;

bool CanReachEnd(vector<int>& max_advance_steps){
    int farthest_reach_so_far = 0, last_step = max_advance_steps.size() - 1;
    for(int i=0; i <= farthest_reach_so_far && farthest_reach_so_far < last_step; ++i){
        farthest_reach_so_far = max(farthest_reach_so_far, max_advance_steps[i] + i);
    }
    return farthest_reach_so_far >= last_step;
}

int main(){
    vector<int> A = {1, 2, 0, 1, 1};
    if(CanReachEnd(A)){
        cout << "Reached End"<<endl;
    }else{
        cout << "Cannot reach end"<<endl;
    }
    return 0;
}