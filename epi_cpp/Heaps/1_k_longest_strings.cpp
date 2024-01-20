#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

vector<string> TopK(int k, istringstream* stream){
    priority_queue<string, vector<string>, function<bool(string, string)>> min_heap(
        [](const string& a, const string& b)->bool{
            return a.size() >= b.size();
        }
    );
    string next_string;
    while(*stream >> next_string){
        min_heap.emplace(next_string);
        if(min_heap.size() > k){
            min_heap.pop();
        }
    }
    vector<string> result;
    while(!min_heap.empty()){
        result.emplace_back(min_heap.top());
        min_heap.pop();
    }
    return result;
}

int main(){
    string str = "this these am is a though although";
    istringstream ss(str);
    int k = 3;
    auto result = TopK(k, &ss);
    for(auto item : result){
        cout << item << " ";
    }
    cout << endl;
    return 0;
}