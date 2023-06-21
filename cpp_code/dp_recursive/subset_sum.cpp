#include <iostream>
#include <vector>

using namespace std;

class SubsetSum{
public:
    static int countSubsets(const vector<int>& num, int sum){
        return countSubsetsRecursive(num, sum, 0);
    }
    static int countSubsetsRecursive(const vector<int>& num, int sum, int currentIndex){
        if(sum == 0){
            return 1;
        }
        if(num.empty() || currentIndex >= num.size()){
            return 0;
        }
        int count1 = 0;
        if(num[currentIndex] <= sum){
            count1 = countSubsetsRecursive(num, sum - num[currentIndex], currentIndex + 1); 
        }
        int count2 = countSubsetsRecursive(num, sum, currentIndex + 1);
        return count1 + count2;
    }
};

int main(){
    vector<int> num = {3, 2, 7, 5, 8, 1, 9, 10, 11, -1};
    int sum = 10;
    int count = SubsetSum::countSubsets(num, sum);
    cout << "Total subsets : "<< count << endl;
    return 0;
}