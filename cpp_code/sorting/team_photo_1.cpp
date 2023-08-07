#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Player{
    int height;
    bool operator<(const Player& that) const{
        return height < that.height;
    }
};

class Team{
    private:
        vector<Player> players_;
        vector<Player> SortPlayersByHeight() const{
            vector<Player> sorted_players(players_);
            sort(sorted_players.begin(), sorted_players.end());
            return sorted_players;
        }
    public:
        explicit Team(const vector<int>& heights){
            for(int i : heights){
                players_.emplace_back(Player{i});
            }
        }

        static bool valid_placement_exists(const Team& A, const Team& B){
            vector<Player> A_sorted(A.SortPlayersByHeight());
            vector<Player> B_sorted(B.SortPlayersByHeight());
            for(int i = 0; i < A_sorted.size() && i < B_sorted.size(); ++i){
                if(B_sorted[i] < A_sorted[i]){
                    return false;
                }
            }
            return true;

        }
};

int main(){
    vector<int> h_B = {2,4,6};
    vector<int> h_A = {1,3,5};
    auto team_a = Team(h_A);
    auto team_b = Team(h_B);
    if(Team::valid_placement_exists(team_a, team_b)){
        cout << "Valid placement exists" << endl;
    }else{
        cout << "Valid placement doesn't exist" << endl;
    }
    return 0;
}