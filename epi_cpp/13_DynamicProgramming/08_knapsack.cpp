#include <iostream>
#include <vector>

using namespace std;

struct Item{
    int weight, value;
};

int OptimumSubjectToItemAndCapacity(const vector<Item>& items, int k, int available_capacity, vector<vector<int>>* V_ptr){
    if(k < 0){
        return 0;
    }
    vector<vector<int>>& V = *V_ptr;
    if(V[k][available_capacity] == -1){
        int without_curr_item = OptimumSubjectToItemAndCapacity(items, k-1, available_capacity, V_ptr);
        int with_curr_item =   
            available_capacity < items[k].weight
            ? 0
            : items[k].value + OptimumSubjectToItemAndCapacity(items, k-1, available_capacity - items[k].weight, V_ptr);
        V[k][available_capacity] = max(with_curr_item, without_curr_item);
    }
    return V[k][available_capacity];
}

int OptimumSubjectToCapacity(const vector<Item>& items, int capacity){
    vector<vector<int>> V(items.size(), vector<int>(capacity+1, -1));
    return OptimumSubjectToItemAndCapacity(items, items.size()-1, capacity, &V);
}

int main(){
    vector<Item> items{{5,60}, {3,50}, {4,70}, {2,30}};
    int capacity = 5;
    cout << OptimumSubjectToCapacity(items, capacity) << endl;
    return 0;
}