#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Job{
public:
    int start=0;
    int end=0;
    int cpuLoad=0;
    Job(int start, int end, int cpuLoad){
        this->start = start;
        this->end = end;
        this->cpuLoad = cpuLoad;
    }
};

class MaxCPULoad{
public:
    struct endCompare{
        bool operator()(const Job& a, const Job& b){
            return a.end > b.end; 
        }
    };
    static int findMaxCPULoad(vector<Job>& jobs){
        if(jobs.size() < 2){
            return jobs[0].cpuLoad;
        }
        priority_queue<Job, vector<Job>, endCompare> minHeap;
        sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b){ return a.start < b.start; });
        int maxCPULoad = 0, currentCPULoad = 0;
        for(auto job : jobs){
            while(!minHeap.empty() && job.start > minHeap.top().end){
                currentCPULoad -= minHeap.top().cpuLoad;
                minHeap.pop();
            }
            minHeap.push(job);
            currentCPULoad += job.cpuLoad;
            maxCPULoad = max(currentCPULoad, maxCPULoad);
        }
        return maxCPULoad;
    }
};

int main(){
    vector<Job> jobs = {{1, 4, 7}, {3, 6, 7}, {8, 10, 12}, {11, 13, 13}};
    cout << "Peak load :" << MaxCPULoad::findMaxCPULoad(jobs) << endl;
    return 0;
}