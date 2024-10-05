#include <iostream>
#include <vector>

using namespace std;

vector<int> SortColors(vector<int>& colors){
    int start=0;
    int current=0;
    int end = colors.size() - 1;
    while(current <= end){
        if(colors[current] == 0){
            swap(colors[start], colors[current]);
            ++current;
            ++start;
        }else if(colors[current] == 1){
            ++current;
        }else{
            swap(colors[end], colors[current]);
            --end;
        }
    }
    return colors;
}

int main(){
    vector<int> colors{2, 1, 1, 0, 1, 0, 2};
    auto result = SortColors(colors);
    for(auto x : result){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}