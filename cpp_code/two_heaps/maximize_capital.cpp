#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class MaximizeCapital{
public:
    struct capitalCompare{
        bool operator()(const pair<int, int>& x, const pair<int, int>& y){
            return x.first > y.first;
        }
    };
    struct profitCompare{
        bool operator()(const pair<int, int>& x, const pair<int, int>& y){
            return x.first < y.first;
        }
    };

    static int findMaximumCapital(const vector<int> &capital, const vector<int> &profit, int numberOfProjects, int initialCapital){
        int n = profit.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, capitalCompare> minCapitalHeap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, profitCompare> maxProfitHeap;
        int availableCapital = initialCapital;
        for(int i = 0; i < n; i++){
            minCapitalHeap.push(make_pair(capital[i], i));
        }
        for(int i = 0; i < numberOfProjects; i++){
            while(!minCapitalHeap.empty() && minCapitalHeap.top().first <= availableCapital){
                auto capitalIndex = minCapitalHeap.top().second;
                minCapitalHeap.pop();
                maxProfitHeap.push(make_pair(profit[capitalIndex], capitalIndex));
            }
            if(maxProfitHeap.empty()){
                break;
            }
            availableCapital += maxProfitHeap.top().first;
            maxProfitHeap.pop();
        }
        return availableCapital;
    }
};

int main(){
    vector<int> profits = {1,2,3,5};
    vector<int> capital = {0,1,2,3};
    int initialCapital = 0;
    int numOfProj = 3;
    cout << MaximizeCapital::findMaximumCapital(capital, profits, numOfProj, initialCapital) << endl;
    return 0;
}