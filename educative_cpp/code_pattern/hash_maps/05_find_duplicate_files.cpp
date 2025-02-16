#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

vector<vector<string>> FindDuplicate(vector<string>& paths){
    unordered_map<string, vector<string>> fileMap;
    for(string& path : paths){
        stringstream ss(path);
        string directory, file;
        ss >> directory;
        while(ss >> file){
            size_t pos = file.find('(');
            string filename = file.substr(0, pos);
            string content = file.substr(pos + 1, file.size() - pos - 2);
            string filePath = directory + "/" + filename;
            fileMap[content].emplace_back(filePath);
        }
    }

    vector<vector<string>> result;
    for(auto entry : fileMap){
        if(entry.second.size() > 1){
            result.emplace_back(entry.second);
        }
    }
    return result;
}

int main(){
    vector<vector<string>> inputList = {
        {
            "home/user1 1.txt(hello) 2.txt(world)",
            "home/user2 3.txt(hello)",
            "home/user3/docs 4.txt(world)",
            "home/user3/docs 5.txt(greetings)"
        },
        {
            "data 1.csv(data1) 2.csv(data2)",
            "data/2021 3.csv(data1) 4.csv(data3)",
            "data/2022 5.csv(data2)",
            "data/2021/backup 6.csv(data3)"
        },
        {
            "reports/jan 1.doc(report1) 2.doc(report2)",
            "reports/feb 3.doc(report1)",
            "reports/mar 4.doc(report2)",
            "reports/apr 5.doc(report3)"
        },
        {
            "docs 1.doc(text1) 2.doc(text2)",
            "docs/2020 3.doc(text1)",
            "docs/2021 4.doc(text2)",
            "docs/2021/backup 5.doc(text3)"
        },
        {
            "csv 1.csv(123) 2.csv(456)",
            "csv/2022 3.csv(123)",
            "csv/2023 4.csv(456) 5.csv(789)",
            "csv/backup 6.csv(789)"
        }
    };

    for (size_t i = 0; i < inputList.size(); ++i) {
        cout << i + 1 << ".\tInput string:" << endl;
        for (const string& path : inputList[i]) {
            cout << "\t\t" << path << endl;
        }

        vector<vector<string>> duplicates = FindDuplicate(inputList[i]);

        cout << "\n\tDuplicate files: " << endl;
        for (const auto& group : duplicates) {
            for (const auto& filePath : group) {
                cout << "\t\t" << filePath << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
