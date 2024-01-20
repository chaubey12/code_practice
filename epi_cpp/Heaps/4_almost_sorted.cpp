#include <iostream>
#include <sstream>
#include <queue>
#include <vector>

using namespace std;

void SortApproximatelySortedData(istringstream* sequence, int k){
    priority_queue<int, vector<int>, greater<>> min_heap;
    int x;
    for(int i=0; i < k && *sequence>>x; ++i){
        min_heap.emplace(x);
    }

    while(*sequence >> x){
        min_heap.emplace(x);
        cout << min_heap.top()<<" ";
        min_heap.pop();
    }

    while(!min_heap.empty()){
        cout << min_heap.top()<<" ";
        min_heap.pop();
    }
    cout << endl;
}

int main(){
    string str = "3 -1 2 6 4 5 8";
    int k = 2;
    istringstream ss(str);
    SortApproximatelySortedData(&ss, k);
    return 0;
}