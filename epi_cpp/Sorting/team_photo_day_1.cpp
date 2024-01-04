#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Player{
    bool operator < (const Player& that) const{
        return height < that.height;
    }
    int  height;
};

class Team{
private:
    vector<Player> players_;
    vector<Player> SortPlayersByHeight()const{
        vector<Player> sorted_players(players_);
        sort(sorted_players.begin(), sorted_players.end());
        return sorted_players;
    }
public:
    explicit Team(const vector<int>& height){
        for(int h : height){
            players_.emplace_back(Player{h});
        }
    }

    static bool valid_placement_exists(const Team& A, const Team& B){
        vector<Player> A_sorted(A.SortPlayersByHeight());
        vector<Player> B_sorted(B.SortPlayersByHeight());
        for(int i=0; i < A_sorted.size() && i < B_sorted.size(); ++i){
            if(B_sorted[i] < A_sorted[i]){
                return false;
            }
        }
        return true;
    }
};

int main(){
    vector<int> a {1, 2, 3, 4, 5};
    vector<int> b {2, 1, 1, 8, 10};
    Team* team_a = new Team(a);
    Team* team_b = new Team(b);
    if(Team::valid_placement_exists(*team_a, *team_b)){
        cout << "Placement Exists"<<endl;
    }else{
        cout << "Placement doesn't Exist"<<endl;
    }
    return 0;
}