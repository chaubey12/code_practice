#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

class SingletonDatabase{
    SingletonDatabase(){
        cout << "Initializatin database"<<endl;
        ifstream ifs("capitals.txt");
        string s, s2;
        while(getline(ifs, s)){
            getline(ifs, s2);
            int pop = stoi(s2);
            capitals[s] = pop;
        }
    }
    map<string, int> capitals;
public:
    SingletonDatabase(SingletonDatabase const&) = delete;
    void operator=(SingletonDatabase const&) = delete;

    static SingletonDatabase& get(){
        static SingletonDatabase db;
        return db;
    }

    int get_population(const string& name){
        return capitals[name];
    }
};

int main(){
    string city = "Tokyo";
    cout << city << " has population " <<
    SingletonDatabase::get().get_population(city) << endl;
    return 0;
}