#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class RequestLogger{
private:
    unordered_map<string, int> requests;
    int timelimit;
public:
    RequestLogger(int newTimeLimit){
        timelimit = newTimeLimit;
    }

    bool MessageRequestDecision(int timestamp, string request){
        if(this->requests.find(request) == this->requests.end()){
            this->requests[request] = timestamp;
            return true;
        }
        int oldTimestamp = this->requests[request];
        if(timestamp - oldTimestamp >= timelimit){
            this->requests[request] = timestamp;
            return true;
        }else{
            return false;
        }
    }
};

int main(){
    RequestLogger newRequests = RequestLogger(7);
    vector<int> times = {1, 5, 6, 7, 11};
    vector<string> messages = {
        "good morning",
        "hello world",
        "good morning",
        "good morning",
        "hello world"
    };
    for(int i=0; i < messages.size(); ++i){
        cout << i + 1 << ".\t Time, Message: ("<< times[i] << ", '"<< messages[i] << "')"<<endl;
        cout << "\t Message request decision: " << boolalpha << newRequests.MessageRequestDecision(times[i], messages[i]) << endl;
        cout << string(100, '-') << endl;
    }
    return 0;
}