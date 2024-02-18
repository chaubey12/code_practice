#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct HighwaySection{
    int x, y;
    double distance;
};

void FloyadWarshall(vector<vector<double>>* G){
    for(int k=0; k < G->size(); ++k){
        for(int i=0; i < G->size(); ++i){
            for(int j=0; j < G->size(); ++j){
                if((*G)[i][k] != numeric_limits<double>::max() &&
                   (*G)[k][j] != numeric_limits<double>::max() &&
                   (*G)[i][j] > (*G)[i][k] + (*G)[k][j]){
                    (*G)[i][j] = (*G)[i][k] + (*G)[k][j];
                }
            }
        }
    }
}

HighwaySection FindBestProposals(const vector<HighwaySection>& H, const vector<HighwaySection>& P, int n){
    vector<vector<double>> G(n, vector<double>(n, numeric_limits<double>::max()));
    for(int i=0; i < n; ++i){
        G[i][i] = 0;
    }
    for(const HighwaySection& h : H){
        G[h.x][h.y] = G[h.y][h.x] = h.distance; 
    }
    FloyadWarshall(&G);
    double best_distance_saving = numeric_limits<double>::min();
    HighwaySection best_proposal = {-1, -1, 0.0};
    for(const HighwaySection& p : P){
        double proposal_saving = 0.0;
        for(int a=0; a < n; ++a){
            for(int b=0; b < n; ++b){
                double saving = G[a][b] - (G[a][p.x] + p.distance + G[p.y][b]);
                proposal_saving += (saving > 0.0) ? saving : 0.0;
            }
        }
        if(proposal_saving > best_distance_saving){
            best_distance_saving = proposal_saving;
            best_proposal = p;
        }
    }
    return best_proposal;
}

int main(){
    return 0;
}