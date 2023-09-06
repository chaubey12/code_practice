#include <iostream>
#include <thread>

using namespace std;

int main(){
    //cout << boolalpha << endl;
    cout << "hardware_concurrency()= " << thread::hardware_concurrency() << endl;
    return 0;
}