#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct MatchResult{
    string winning_team, losing_team;
};

unordered_map<string, unordered_set<string>> BuildGraph(const vector<MatchResult>& matches){
    unordered_map<string, unordered_set<string>> graph;
    for(const MatchResult& match : matches){
        graph[match.winning_team].emplace(match.losing_team);
    }
    return graph;
}

bool IsReachableDFS(const unordered_map<string, unordered_set<string>>& graph, 
                    const string& curr, const string& dest, 
                    unordered_set<string>* visited_ptr){
    unordered_set<string>& visited = *visited_ptr;
    if(curr == dest){
        return true;
    }else if((visited.find(curr) != visited.end()) || (graph.find(curr) == graph.end())){
        return false;
    }
    visited.emplace(curr);
    for(const string& team : graph.at(curr)){
        if(IsReachableDFS(graph , team, dest, visited_ptr)){
            return true;
        }
    }
    return false;
}

bool CanTeamABeatTeamB(const vector<MatchResult>& matches, const string& team_a, const string& team_b){
    return IsReachableDFS(BuildGraph(matches), team_a, team_b, make_unique<unordered_set<string>>().get());
}


int main(){
    vector<MatchResult> matches {{"a", "b"}, {"b", "c"}, {"d", "c"}, 
    {"a", "d"}, {"x", "y"}, {"a", "x"}, {"b", "x"}, {"y", "c"}, {"a", "y"}};
    if(CanTeamABeatTeamB(matches, "b", "y")){
        cout << "YES" << endl;
    }else{
        cout << "NO"<<endl;
    }
    return 0;
}