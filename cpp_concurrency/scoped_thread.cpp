#include <iostream>
#include <thread>
#include <utility>

using namespace std;

class scoped_thread{
    thread t;
public:
    explicit scoped_thread(thread t_) : t(move(t_)){
        if(!t.joinable()){
            throw logic_error("No thread");
        }
    }
};