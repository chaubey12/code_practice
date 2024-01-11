#include <iostream>
#include <vector>
#include <limits>

using namespace std;

double BuyAndSellStockOnce(const vector<double>& prices){
    double min_price_so_far = numeric_limits<int>::max();
    double max_profit = 0;
    for(auto price : prices){
        double max_profit_sell_today = price - min_price_so_far;
        max_profit = max(max_profit, max_profit_sell_today);
        min_price_so_far = min(min_price_so_far, price);
    }
    return max_profit;
}

int main(){
    vector<double> prices = {10, 20.5, 1.5, 19.4, 40.2, 34.6};
    cout << "Max Profit : " << BuyAndSellStockOnce(prices) << endl;
    return 0;
}