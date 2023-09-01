#include <iostream>
#include <thread>

using namespace std;

int main(){
    thread t1([]{ cout << this_thread::get_id() << endl;});
    t1.join();
    return 0;
}