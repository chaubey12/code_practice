#include <iostream>
#include <thread>

using namespace std;

void helloFunction(){
    cout << "Hello from a function." << endl;
}

class HelloFunctionObject{
public:
    void operator()() const{
        cout << "Hello from a function object." << endl;
    }
};

int main(){
    thread t1(helloFunction);
    HelloFunctionObject helloFunctionObject;
    thread t2(helloFunctionObject);
    thread t3([]{cout << "Hello from a lambda." << endl;});

    t1.join();
    t2.join();
    t3.join();
    return 0;
}