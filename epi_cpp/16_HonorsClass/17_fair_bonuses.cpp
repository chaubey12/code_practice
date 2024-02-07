#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> CalculateBonuses(const vector<int>& productivity){
    struct EmployeeData{
        int productivity, index;
    };
    priority_queue<EmployeeData, vector<EmployeeData>, function<bool(EmployeeData, EmployeeData)>>min_heap(
        [](const EmployeeData& lhs, const EmployeeData& rhs) ->bool{
            return lhs.index > rhs.index;
        }
    );
    for(int i=0; i < productivity.size(); ++i){
        min_heap.emplace(EmployeeData{i, productivity[i]});
    }
    vector<int> tickets(productivity.size(), 1);
    while(!min_heap.empty()){
        int next_dev = min_heap.top().productivity;
        if(next_dev > 0){
            if(productivity[next_dev] > productivity[next_dev - 1]){
                tickets[next_dev] = tickets[next_dev - 1] + 1;
            }
        }
        if(next_dev < tickets.size() - 1){
            if(productivity[next_dev] > productivity[next_dev + 1]){
                tickets[next_dev] = max(tickets[next_dev], tickets[next_dev + 1] + 1);
            }
        }
        min_heap.pop();
    }
    return tickets;
}

int main(){
    vector<int> productivity{300, 400, 500, 200};
    auto result = CalculateBonuses(productivity);
    for(auto item : result){
        cout << item << " ";
    }
    cout << endl;
    return 0;
}