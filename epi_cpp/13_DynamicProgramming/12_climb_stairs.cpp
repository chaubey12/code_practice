#include <iostream>
#include <vector>

using namespace std;

int ComputeNumberOfWaysToH(int h, int maximum_step, vector<int>* number_of_ways_to_h_ptr){
    if(h <= 1){
        return h;
    }
    vector<int>& number_of_ways_to_h = *number_of_ways_to_h_ptr;
    if(number_of_ways_to_h[h] == 0){
        for(int i=1; i <= maximum_step && h-i >= 0; ++i){
            number_of_ways_to_h[h] += ComputeNumberOfWaysToH(h-i, maximum_step, number_of_ways_to_h_ptr);
        }
    }
    return number_of_ways_to_h[h];
}


int NumberOfWaysToTop(int top, int maximum_step){
    vector<int> number_of_ways_to_h(top + 1, 0);
    return ComputeNumberOfWaysToH(top, maximum_step, &number_of_ways_to_h);
}

int main(){
    int h = 4, maximum_step = 2;
    cout << NumberOfWaysToTop(h, maximum_step)<<endl;
    return 0;
}