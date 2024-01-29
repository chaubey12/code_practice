#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;
struct Name{
    string first_name, last_name;
    bool operator==(const Name& that) const{
        return first_name == that.first_name;
    }
    bool operator <(const Name& that) const{
        if(first_name != that.first_name){
            return first_name < that.first_name;
        }
        return last_name < that.last_name;
    }
};

void EliminateDuplicate(vector<Name>* A){
    sort(A->begin(), A->end());
    A->erase(unique(A->begin(), A->end()), A->end());
}


int main(){
    Name a = Name{"Ian", "Botham"};
    Name b = Name{"David", "Gower"};
    Name c = Name{"Ian", "Bell"};
    Name d = Name{"Ian", "Chappel"};
    vector<Name> names{a, b, c, d};
    EliminateDuplicate(&names);
    for(auto& name : names){
        cout << name.first_name << " "<< name.last_name<<endl;
    }
    return 0;
}