#include <iostream>
#include <vector>

using namespace std;

int ComputeXChooseY(int x, int y, vector<vector<int>>* x_choose_y_ptr){
    if(y == 0 || x==y){
        return 1;
    }
    vector<vector<int>>& x_choose_y = *x_choose_y_ptr;
    if(x_choose_y[x][y] == 0){
        int without_y = ComputeXChooseY(x-1, y, x_choose_y_ptr);
        int with_y = ComputeXChooseY(x-1, y-1, x_choose_y_ptr);
        x_choose_y[x][y] = without_y + with_y;
    }
    return x_choose_y[x][y];
}

int ComputeBinomialCoefficient(int n, int k){
    vector<vector<int>> x_choose_y(n+1, vector<int>(k+1, 0));
    return ComputeXChooseY(n, k, &x_choose_y);
}

int main(){
    int n=5, k=2;
    cout << ComputeBinomialCoefficient(n, k) << endl;
    return 0;
}