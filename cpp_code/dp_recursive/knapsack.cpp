#include <iostream>
#include <vector>

using namespace std;

class Knapsack{
public:
    static int solveKnapsack(const vector<int>& profits, const vector<int>& weights, int capacity){
        return solveKnapsackRecursive(profits, weights, capacity, 0);
    }
private:
    static int solveKnapsackRecursive(const vector<int>& profits, const vector<int>& weights, int capacity, int currentIndex){
        if(capacity <= 0 || currentIndex >= profits.size()){
            return 0;
        }
        int profit1 = 0;
        if(weights[currentIndex <= capacity]){
            profit1 = profits[currentIndex] + solveKnapsackRecursive(profits, weights, capacity - weights[currentIndex], currentIndex + 1);
        }
        int profit2 = solveKnapsackRecursive(profits, weights, capacity, currentIndex + 1);
        return max(profit1, profit2);
    }
};

int main(){
    int capacity = 10;
    vector<int> profits = {7, 2, 9, 6, 7};
    vector<int> weights = {2, 4, 1, 5, 3};
    int maxProfit = Knapsack::solveKnapsack(profits, weights, capacity);
    cout << "The max Profit to be made is : " << maxProfit << endl;
    return 0;
}