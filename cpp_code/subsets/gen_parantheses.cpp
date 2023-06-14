#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class ParanthesesString{
public:
    string str;
    int openCount = 0;
    int closeCount = 0;
    ParanthesesString(string str, int open, int close){
        this->str = str;
        this->openCount = open;
        this->closeCount = close;
    }
};

class GenerateParantheses{
public:
    static vector<string> generate(int num){
        vector<string> result;
        if(num < 1){
            return result;
        }
        queue<ParanthesesString> q;
        q.push({"", 0, 0});
        while(!q.empty()){
            ParanthesesString ps = q.front();
            q.pop();
            if(ps.openCount == num && ps.closeCount == num){
                result.push_back(ps.str);
            }else{
                if(ps.openCount < num){
                    q.push({ps.str + "(", ps.openCount+1, ps.closeCount});
                }
                if(ps.openCount > ps.closeCount){
                    q.push({ps.str + ")", ps.openCount, ps.closeCount+1});
                }
            }
        }
        return result;
    }
};


int main(){
    int num = 5;
    auto result = GenerateParantheses::generate(num);
    for(auto elem : result){
        cout << elem << endl;
    }
    return 0;
}