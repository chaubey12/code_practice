#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

double FindSalaryCap(double target_payroll, vector<double> current_salaries){
    sort(current_salaries.begin(), current_salaries.end());
    double unadjusted_salary_sum = 0.0;
    for(int i=0; i < current_salaries.size(); ++i){
        const double adjusted_salary_sum = current_salaries[i] * (current_salaries.size() - i);
        if(unadjusted_salary_sum + adjusted_salary_sum >= target_payroll){
            return (target_payroll - unadjusted_salary_sum)/(current_salaries.size() - i);
        }
        unadjusted_salary_sum += current_salaries[i];
    }
    return -1.0;
}

int main(){
    vector<double> current_salaries{90, 30, 100, 40, 20};
    int target_payroll = 210;
    cout << FindSalaryCap(target_payroll, current_salaries)<<endl;
    return 0;
}