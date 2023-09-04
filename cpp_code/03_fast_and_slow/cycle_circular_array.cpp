#include <iostream>
#include <vector>

using namespace std;

class CircularArray{
public:
    static bool hasCycle(const vector<int>& arr){
        for(int i=0; i < arr.size(); i++){
            bool isForward = (arr[i] >= 0);
            int slow = i;
            int fast = i;
            while(true){
                slow = findNextIndex(arr, isForward, slow);
                fast = findNextIndex(arr, isForward, fast);
                if(fast != -1){
                    fast = findNextIndex(arr, isForward, fast);
                }
                if(slow == -1 || fast == -1 || slow == fast){
                    break;
                }
            }
            if(slow != -1 && slow == fast){
                return true;
            }
        }
        return false;
    }
private:
    static int findNextIndex(const vector<int>& arr, bool isForward, int currentIdx){
        bool direction = (arr[currentIdx] >= 0);
        if(isForward != direction){
            return -1;
        }
        int nextIdx = (currentIdx + arr[currentIdx]) % arr.size();
        if(nextIdx < 0){
            nextIdx += arr.size();
        }
        if(nextIdx == currentIdx){
            nextIdx = -1;
        }
        return nextIdx;
    }
};

int main(){
    vector<int> arr = {1, 2, -1, 2, 2};
    if(CircularArray::hasCycle(arr)){
        cout << "HAS CYCLE" << endl;
    }else{
        cout << "NO CYCLE" << endl;
    }
    return 0;
}