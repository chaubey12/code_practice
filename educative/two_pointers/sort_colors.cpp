#include <iostream>
#include <vector>

using namespace std;

vector<int> SortColors(vector<int>& colors){
    int red=0, white=0, blue=colors.size()-1;
    while(white <= blue){
        if(colors[white] == 0){
            if(colors[red] != 0){
                swap(colors[red], colors[white]);
            }
            ++white;
            ++red;
        }else if(colors[white] == 1){
            ++white;
        }else{
            if(colors[blue] != 2){
                swap(colors[white], colors[blue]);
            }
            --blue;
        }
    }
    return colors;
}

int main(){
    vector<int> colors = {2,1,1,2,0,1,0,2,0};
    auto result = SortColors(colors);
    for(auto el : result){
        cout << el << " ";
    }
    cout << endl;
    return 0;
}