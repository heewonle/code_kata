#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    unordered_map<string,set<string>> id_map;
        unordered_map<string,set<string>> mails;
    for(int i=0; i<id_list.size(); i++){
        id_map[id_list[i]]={};
    }
    for(int j=0; j<report.size(); j++){
        auto it = report[j].find(" ");
        string id = report[j].substr(0,it);
        string reporter = report[j].substr(it+1);
        id_map[reporter].insert(id);
    }
    for(int j=0; j<report.size(); j++){
        auto it = report[j].find(" ");
        string id = report[j].substr(0,it);
        string reporter = report[j].substr(it+1);
        int report_num = id_map[reporter].size();
        if(report_num>=k){
            mails[id].insert(reporter);
        }
    }
    for(int i=0; i<id_list.size(); i++){
        answer.push_back(mails[id_list[i]].size());
    }
    return answer;
}