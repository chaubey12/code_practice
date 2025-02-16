#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

string PrintArray(vector<int> nums){
    string inputarray = "[";
    for (int x: nums){
        inputarray += to_string(x) + ", ";
    }
    inputarray = inputarray.substr(0, inputarray.size() - 2) + "]";
    return inputarray;
}

vector<int> NextGreaterElement(vector<int> nums1, vector<int> nums2){
    stack<int> s;
    unordered_map<int, int> m;
    for(int current : nums2){
        while(!s.empty() && current > s.top()){
            m[s.top()] = current;
            s.pop();
        }
        s.push(current);
    }
    while(!s.empty()){
        m[s.top()] = -1;
        s.pop();
    }
    vector<int> ans(nums1.size());
    for(int i=0; i < nums1.size(); i++){
        ans[i] = m[nums1[i]];
    }
    return ans;
}

int main() {
  vector<vector<int>> A = {
    {2, 4},
    {3, 2, 5},
    {14, 45, 52},
    {1, 3, 2},
    {4, 2},
    {0}
  };

  vector<vector<int>> B = {
    {1, 2, 3, 4},
    {2, 3, 5, 1},
    {52, 14, 45, 65},
    {1, 3, 2, 4, 5},
    {1, 2, 4, 3},
    {0}
  };

  for(int i=0; i<A.size(); i++){
    cout << i + 1 << ".\tNums 1 = " << PrintArray(A[i]) << "\n\tNums 2 = " << PrintArray(B[i]) << "\n"; 
    vector<int> ansult = NextGreaterElement(A[i], B[i]);
    cout << "\tThe Next Greater Element Array = " << PrintArray(ansult) << "\n";
    cout << std::string(100, '-') << "\n";

  }
  return 0;
}