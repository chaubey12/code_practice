#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

bool BellmanFord(vector<vector<double>>& G, int source){
    vector<double> dis_to_source(G.size(), numeric_limits<double>::max());
    dis_to_source[source] = 0;
    for(int times = 1; times < G.size(); times++){
        bool have_update = false;
        for(int i = 0; i < G.size(); i++){
            for(int j = 0; j < G[i].size(); j++){
                if(dis_to_source[i] != numeric_limits<double>::max() &&
                   dis_to_source[j] > dis_to_source[i] + G[i][j]){
                    dis_to_source[j] = dis_to_source[i] + G[i][j];
                }
            }
        }
        if(have_update == false){
            return false;
        }
    }
    for(int i = 0; i < G.size(); ++i){
        for(int j = 0; j < G[i].size(); ++j){
            if(dis_to_source[i] != numeric_limits<double>::max() && dis_to_source[j] > dis_to_source[i] + G[i][j]){
                return true;
            }
        }
    }
    return false;
}

bool ArbitrageExists(vector<vector<double>>& G){
    for(vector<double>& edge_list : G){
        for(double& edge : edge_list){
            edge = -log10(edge); 
        }
    }
    return BellmanFord(G, 0);
}


int main(){
    vector<vector<double>> exchangeTable;
    exchangeTable.push_back({1, 0.8123, 0.6404, 78.125, 0.9784, 0.9924, 0.9465});
    exchangeTable.push_back({1.2275, 1, 0.7860, 96.55, 1.2010, 1.2182, 1.1616});
    exchangeTable.push_back({1.5617, 0.8123, 1, 122.83, 1.5280, 1.5948, 1.4778});
    exchangeTable.push_back({0.0128, 0.0104, 0.0081, 1, 1.2442, 0.0126, 0.0120});
    exchangeTable.push_back({1.0219, 0.8327, 0.6546, 80.39, 1, 1.0142, 0.9672});
    exchangeTable.push_back({1.0076, 0.8206, 0.6453, 79.26, 0.9859, 1, 0.9535});
    exchangeTable.push_back({1.0567, 0.8609, 0.6767, 83.12, 1.0339, 1.0487, 1});
    if(ArbitrageExists(exchangeTable)){
        cout << "Arbitrage opportunity exists." << endl;
    }else{
        cout << "No arbitrage opportunity exists." << endl;
    }
    return 0;
}