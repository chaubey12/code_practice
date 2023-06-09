#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Meeting{
public:
    int start=0;
    int end=0;
    Meeting(int start, int end){
        this->start = start;
        this->end = end;
    }
};

class MinimumMeetingRooms{
public:
    struct endCompare{
        bool operator()(const Meeting& a, const Meeting& b){
            return a.end > b.end;
        }
    };
    static int findMinimumMeetingRooms(vector<Meeting>& meetings){
        int minRooms = 0;
        sort(meetings.begin(), meetings.end(), [](const Meeting& a, const Meeting& b){ return a.start < b.start; });
        priority_queue<Meeting, vector<Meeting>, endCompare> minHeap;
        for(auto meeting : meetings){
            while(!minHeap.empty() && meeting.start > minHeap.top().end){
                minHeap.pop();
            }
            minHeap.push(meeting);
            minRooms = max(minRooms, (int)minHeap.size());
        }
        return minRooms;
    }
};

int main(){
    vector<Meeting> meetings = {{2, 3}, {5, 7}, {8,10}, {6, 9}};
    auto result = MinimumMeetingRooms::findMinimumMeetingRooms(meetings);
    cout << "Minimum of " << result << " meeting rooms are required."<<endl;
    return 0;
}