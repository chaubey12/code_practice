#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Person{
    string name;
    int age;
};

void GroupByAge(vector<Person>* person_array){
    unordered_map<int, int> age_to_count;
    for(const Person& p : *person_array){
        ++age_to_count[p.age];
    }
    unordered_map<int, int> age_to_offset;
    int offset = 0;
    for(const auto& p: age_to_count){
        age_to_offset[p.first] = offset;
        offset += p.second;
    }
    while(age_to_offset.size()){
        auto from = age_to_offset.begin();
        auto to = age_to_offset.find((*person_array)[from->second].age);
        swap((*person_array)[from->second], (*person_array)[to->second]);
        --age_to_count[to->first];
        if(age_to_count[to->first] > 0){
            ++to->second;
        }else{
            age_to_offset.erase(to);
        }
    }
}

int main(){
    vector<Person> persons{{"Greg", 14}, {"John", 12}, {"Andy", 11}, {"Jim", 13}, {"Phil", 12}, {"Bob", 13}, {"Chip", 13}, {"Tim", 14}};
    for(Person person : persons){
        cout << person.name << ", "<< person.age<<endl;
    }
    cout << "GROUP BY AGE"<<endl;
    GroupByAge(&persons);
    for(Person person : persons){
        cout << person.name << ", "<< person.age<<endl;
    }
    return 0;
}