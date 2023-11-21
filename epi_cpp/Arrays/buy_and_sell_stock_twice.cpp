#include <iostream>
#include <vector>

using namespace std;

double BuyAndSellStockTwice(const vector<double>& prices){
    double max_total_profit = 0;
    vector<double> first_buy_and_sell_profit(prices.size(), 0);
    double min_prices_so_far = numeric_limits<double>::max();
    for(int i=0; i < prices.size(); ++i){
        min_prices_so_far = min(min_prices_so_far, prices[i]);
        max_total_profit = max(max_total_profit, prices[i] - min_prices_so_far);
        first_buy_and_sell_profit[i] = max_total_profit;
    }
    double max_price_so_far = numeric_limits<double>::min();
    for(int i=prices.size()-1; i > 0; --i){
        max_price_so_far = max(max_price_so_far, prices[i]);
        max_total_profit = max(max_total_profit, max_price_so_far - prices[i] + first_buy_and_sell_profit[i-1]);
    }
    return max_total_profit;
}

int main(){
    vector<double> prices = {10, 20.5, 1.5, 19.4, 40.2, 34.6};
    cout << "Max Profit : " << BuyAndSellStockTwice(prices) << endl;
    return 0;
}