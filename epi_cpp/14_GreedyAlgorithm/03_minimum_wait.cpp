#include <iostream>
#include <vector>
#include <memory>

using namespace std;

int MinimumTotalWaitingTime(vector<int> service_times){
    sort(service_times.begin(), service_times.end());
    int total_waiting_time=0;
    for(int i=0; i < service_times.size(); ++i){
        int num_remaining_queries = service_times.size() - (i+1);
        total_waiting_time += service_times[i]*num_remaining_queries;
    }
    return total_waiting_time;
}

int main(){
    vector<int> service_times = {2,5,1,3};
    cout << MinimumTotalWaitingTime(service_times)<<endl;
    return 0;
}