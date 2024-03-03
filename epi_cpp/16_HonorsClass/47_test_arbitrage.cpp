#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

bool BellmanFord(const vector<vector<double>> G, int source){
    vector<double> dis_to_source(G.size(), numeric_limits<double>::max());
    dis_to_source[source] = 0;
    for(size_t times=1; times < G.size(); ++times){
        bool have_update = false;
        for(size_t i=0; i < G.size(); ++i){
            for(size_t j=0; j < G.size(); ++j){
                if(dis_to_source[i] != numeric_limits<double>::max() &&
                   dis_to_source[j] > dis_to_source[i] + G[i][j]){
                    have_update = true;
                    dis_to_source[j] = dis_to_source[i] + G[i][j];
                }
            }
        }
        if(have_update == false){
            return false;
        }
    }
    for(size_t i=0; i < G.size(); ++i){
        for(size_t j=0; j < G.size(); ++j){
            if(dis_to_source[i] != numeric_limits<double>::max() &&
               dis_to_source[j] > dis_to_source[i] + G[i][j]){
                return true;
            }
        }
    }
    return false;
}

bool IsArbitrageExist(vector<vector<double>> G){
    for(vector<double>& edge_list : G){
        for(double& edge : edge_list){
            edge = -log10(edge);
        }
    }
    return BellmanFord(G, 0);
}

int main(){
    vector<vector<double>> G{
        {1, 0.8123, 0.6404, 78.125, 0.9784, 0.9924, 0.9465},
        {1,2275, 1, 0.7860, 96.55, 1.2010, 1.2182, 1.1616},
        {1.5617, 1.2724, 1, 122.83, 1.5280, 1.5498, 1.4778},
        {0.0128, 0.0104, 0.0081, 1, 1.2442, 0.0126, 0.0120},
        {1.0219, 0.8327, 0.6546, 80.39, 1, 1.0142, 0.9672},
        {1.0076, 0.8206, 0.6453, 79.26, 0.9859, 1, 0.9535},
        {1.0567, 0.8609, 0.6767, 83.12, 1.0339, 1.0487, 1}
    };
    if(IsArbitrageExist(G)){
        cout << "Arbitrage exists"<<endl;
    }else{
        cout << "Arbitrage doesn't exist"<<endl;
    }
    return 0;
}