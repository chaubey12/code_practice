#include <iostream>
#include <vector>
#include <memory>
#include <limits>

using namespace std;
typedef enum {SMALLER, EQUAL, LARGER} Ordering;

Ordering Compare(double a, double b){
    double diff = (a - b)/b;
    return diff < -numeric_limits<double>::epsilon()
                ? SMALLER
                : diff > numeric_limits<double>::epsilon() ? LARGER : EQUAL;
}

double SquareRoot(double x){
    double left, right;
    if(x < 1.0){
        left = x, right = 1.0;
    }else{
        left = 1.0, right = x;
    }
    while(Compare(left, right) == SMALLER){
        double mid = left + 0.5*(right - left);
        double mid_squared = mid*mid;
        if(Compare(mid_squared, x) == EQUAL){
            return mid;
        }else if(Compare(mid_squared, x) == LARGER){
            right = mid;
        }else{
            left = mid;
        }
    }
    return left;
}

int main(){
    double x = 1.69;
    cout << SquareRoot(x) << endl;
    return 0;
}