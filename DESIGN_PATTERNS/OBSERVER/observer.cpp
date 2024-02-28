#include <iostream>
#include <vector>
#include <string>

using namespace std;

// observer & observable
template <typename T>
struct Observer{
    virtual void field_changed(
        T& source,
        const string filed_name
    ) = 0;
};

template <typename T>
struct Observable{
    vector<Observer<T>*> observers;
    void notify(T& source, const string& field_name){
        for(auto observer : observers){
            observer->field_changed(source, field_name);
        }
    }

    void subscribe(Observer<T>& observer){
        observers.push_back(&observer);
    }

    void unsubscribe(Observer<T>& observer){
        observers.erase(
            remove(observers.begin(), observers.end(), observer),
            observers.end()
        );
    }
};

class Person : public Observable<Person>{   // observable
    int age;
public:
    int get_age() const{
        return age;
    }
    void set_age(int age){
        if(this->age == age) return;
        this->age = age;
        notify(*this, "age");
    }
};

struct ConsolePersonObserver : public Observer<Person>{
    void field_changed(Person& source, const string& field_name) override{
        cout << "Person's "<<field_name<< " has changed to ";
        if(field_name == "age") cout << source.get_age();
        cout << "\n.";   
    }
};

int main(){
    Person person{10};
    ConsolePersonObserver cpo;
    return 0;
}