#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <fstream>

using namespace std;

struct Journal{
    string title;
    vector<string> entries;

    Journal(const string &title) : title(title) {}

    void add_entry(const string& entry){
        static int count = 1;
        entries.push_back(to_string(count++) + ": " + entry);
    }

};

struct PersistenceManager{
    static void save(const Journal& j, const string& filename){
        ofstream ofs(filename);
        for(auto& e : j.entries){
            ofs << e << endl;
        }
    }
};

int main(){
    Journal journal{"Dear Diary"};
    journal.add_entry("I ate a bug");
    journal.add_entry("I cried today");
    PersistenceManager::save(journal, "C:\\diary.txt");
    return 0;
}