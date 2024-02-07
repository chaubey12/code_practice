#include <iostream>
#include <vector>

using namespace std;

vector<int> CalculateBonus(const vector<int>& productivity){
    vector<int> tickets(productivity.size(), 1);
    for(int i=1; i < productivity.size(); ++i){
        if(productivity[i] > productivity[i-1]){
            tickets[i] = tickets[i-1] + 1;
        }
    }
    for(int i=productivity.size() -2; i >= 0; --i){
        if(productivity[i] > productivity[i+1]){
            tickets[i] = max(tickets[i], tickets[i+1]+1);
        }
    }
    return tickets;
}

int main(){
    vector<int> productivity{300, 400, 500, 200};
    auto result = CalculateBonus(productivity);
    for(auto item : result){
        cout << item << " ";
    }
    cout << endl;
    return 0;
}