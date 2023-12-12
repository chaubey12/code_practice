#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <functional>

using namespace std;

struct ContactList{
    bool operator==(const ContactList& that) const{
        return unordered_set<string>(names.begin(), names.end()) == unordered_set<string>(that.names.begin(), that.names.end());
    }
    vector<string> names;
};

struct HashContactList{
    size_t operator()(const ContactList& contacts) const{
        size_t hash_code = 0;
        for(const string& name : unordered_set<string>(contacts.names.begin(), contacts.names.end())){
            hash_code ^= hash<string>()(name);
        }
        return hash_code;
    }
};

vector<ContactList> MergeContactLists(const vector<ContactList>& contacts){
    unordered_set<ContactList, HashContactList> unique_contacts(contacts.begin(), contacts.end());
    return {unique_contacts.begin(), unique_contacts.end()};
}

int main(){
    vector<string> cl1 = {"madhup", "choubey", "anwesha", "choubey", "rita", "choubey", "arpita", "upadhyaya", "chandra", "shekhar", "choubey"};
    vector<string> cl2 = {"madhup", "anwesha", "rita", "arpita", "chandra", "shekhar", "choubey", "upadhyaya"};

    ContactList contact1 = ContactList{cl1};
    ContactList contact2 = ContactList{cl2};
    vector<string> cl3 = {"madhup", "choubey"};
    vector<string> cl4 = {"anwesha", "choubey"};

    ContactList contact3 = ContactList{cl3};
    ContactList contact4 = ContactList{cl4};
    if(contact1 == contact2){
        cout << "EQUAL LISTS"<<endl;
    }else{
        cout << "UNEQUAL LISTS"<<endl;
    }
    return 0;
}