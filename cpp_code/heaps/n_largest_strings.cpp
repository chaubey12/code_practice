#include <iostream>
#include <queue>
#include <vector>
#include <sstream>

using namespace std;

vector<string> TopK(int k, istringstream* stream){
    priority_queue<string, vector<string>, function<bool(string, string)>>
        min_heap([](const string& a, const string& b)-> bool{
            return a.length() >= b.length();
        });
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
    string str = "This is one of the most crucial aspect of development";
    istringstream stream(str);
    int k = 3;
    auto result = TopK(k, &stream);
    for(auto s : result){
        cout << s << " " << endl;
    }
    return 0;
}