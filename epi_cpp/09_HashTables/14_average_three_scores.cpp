#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <fstream>
#include <queue>

using namespace std;

int GetTopThreeScoresSum(priority_queue<int, vector<int>, greater<>> scores){
    int sum=0;
    while(!scores.empty()){
        sum += scores.top();
        scores.pop();
    }
    return sum;
}

string FindStudentWithHighestBestOfThreeScores(ifstream *ifs){
    unordered_map<string, priority_queue<int, vector<int>, greater<>>> student_scores;
    string name;
    int score;
    while(*ifs >> name >> score){
        student_scores[name].emplace(score);
        if(student_scores[name].size() > 3){
            student_scores[name].pop();
        }
    }
    string top_student = "no such student";
    int current_top_three_scores_sum=0;
    for(const auto& scores : student_scores){
        if(scores.second.size() == 3){
            int current_top_three_scores_sum = GetTopThreeScoresSum(scores.second);
            top_student = scores.first;
        }
    }
    return top_student;
}

int main(){
    return 0;
}