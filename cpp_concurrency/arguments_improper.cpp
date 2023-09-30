#include <chrono>
#include <iostream>
#include <thread>

using namespace std;

class Sleeper{
public:
    Sleeper(int& i_) : i{i_}{};
    void operator()(int k){
        for(unsigned int j=0; j <= 5; ++j){
            this_thread::sleep_for(chrono::milliseconds(100));
            i += k;
        }
        cout << this_thread::get_id() << endl;
    }
private:
    int&i;
};

int main(){
    int valSleeper = 1000;
    thread t(Sleeper(valSleeper), 5);
    //t.detach();
    t.join();
    cout << "valSleeper = " << valSleeper << endl;
    return 0;
}

