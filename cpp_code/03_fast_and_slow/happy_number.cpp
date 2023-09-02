#include <iostream>

using namespace std;

class HappyNumber{
public:
    static bool isHappy(int num){
        int slow=num, fast=num;
        while(true){
            slow = findSquareSum(slow);
            fast = findSquareSum(findSquareSum(fast));
            if(slow == fast){
                break;
            }
        }
        return slow == 1;
    }
private:
    static int findSquareSum(int num){
        int sum = 0;
        while(num > 0){
            sum += (num%10)*(num%10);
            num = num/10;
        }
        return sum;
    }
};

int main(){
    int num = 23;
    if(HappyNumber::isHappy(num)){
        cout << "HAPPY" << endl;
    }else{
        cout << "NOT-HAPPY" << endl;
    }
    return 0;
}