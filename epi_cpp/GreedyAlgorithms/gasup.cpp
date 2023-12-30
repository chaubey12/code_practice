#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int kMPG = 20;

size_t FindAmpleCity(const vector<int>& gallons, const vector<int>& distances){
    int remaining_gallons = 0;
    struct CityAndRemainingGas{
        int city=0, remaining_gallons=0;
    };
    CityAndRemainingGas city_remaining_gallons_pair;
    const int num_cities = gallons.size();
    for(int i=1; i < num_cities; ++i){
        remaining_gallons += gallons[i-1] - distances[i-1]/kMPG;
        if(remaining_gallons < city_remaining_gallons_pair.remaining_gallons){
            city_remaining_gallons_pair = {i, remaining_gallons};
        }
    }
    return city_remaining_gallons_pair.city;
}


int main(){
    vector<int> gallons{20,5,30,25,10,10,50};
    vector<int> distances{600,200, 400, 600, 200, 100, 900};
    cout <<"Ample city is city# "<<FindAmpleCity(gallons, distances)<<endl;
    return 0;
}