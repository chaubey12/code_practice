#include <iostream>
#include <vector>

using namespace std;

struct Event{
    int start, finish;
};

struct Endpoint{
    int time;
    bool isStart;
    bool operator<(const Endpoint& e) const{
        return time != e.time ? time < e.time : (isStart && !e.isStart);
    }
};

int FindMaxSimultaneousEvents(const vector<Event>& A){
    vector<Endpoint> E;
    for(const Event& event : A){
        E.emplace_back(Endpoint{event.start, true});
        E.emplace_back(Endpoint{event.finish, false});
    }
    sort(E.begin(), E.end());
    int max_num_simultaneous_events = 0, num_simultaneous_events = 0;
    for(const Endpoint& endpoint : E){
        if(endpoint.isStart){
            ++num_simultaneous_events;
            max_num_simultaneous_events = max(max_num_simultaneous_events, num_simultaneous_events);
        }else{
            --num_simultaneous_events;
        }
    }
    return max_num_simultaneous_events;
}

int main(){
    vector<Event> events{{1, 5}, {2, 7}, {4, 5}, {6, 10}, {8, 9}, {9, 17}, {11, 13}, {12, 15}, {14, 15}};
    cout << "Max concurrent events : "<< FindMaxSimultaneousEvents(events)<<endl;
    return 0;
}