#include <iostream>
#include <vector>

using namespace std;

double MaxKPairsProfits(const vector<double>& A, int k){
    if(k > A.size()/2 - 1){
        k = A.size()/2 - 1;
    }
    vector<double> k_sum(2*k, numeric_limits<double>::lowest());
    for(int i=0; i < A.size(); ++i){
        vector<double> pre_k_sum(k_sum);
        for(int j=0, sign = -1; j < k_sum.size() && j <= i; ++j, sign *= -1){
            double diff = sign * A[i] + (j == 0 ? 0 : pre_k_sum[j-1]);
            k_sum[j] = max(diff, pre_k_sum[j]);
        }
    }
    return k_sum.back();
}

int main(){
    vector<double> prices{310, 315, 275, 295, 260, 270, 290, 230, 255, 250};
    for(int k = 1; k <= 15; ++k){
        cout << MaxKPairsProfits(prices, k)<<endl;
    }
    return 0;
}