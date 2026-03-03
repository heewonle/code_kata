#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    unordered_map<string,int> term_map;
    today.erase(std::remove(today.begin(), today.end(), '.'), today.end());
    for(int d=0; d<terms.size(); d++){
        term_map[terms[d].substr(0,1)] = stoi(terms[d].substr(2,3));
        
    }
    for(int i=0; i<privacies.size(); i++){
        string date = privacies[i].substr(0,privacies[i].length()-2);
        int year = stoi(date.substr(0,4));
        int month = stoi(date.substr(5,7));
        string term = privacies[i].substr(privacies[i].length()-1);
        month+=term_map[term];
        while(month>12){
            month-=12;
            year+=1;
        }
        string str_month = to_string(month);
        if(month<10){
            str_month = "0"+str_month;
        }
        date = to_string(year) + str_month + date.substr(8,10);
        int sub = stoi(today) - stoi(date);
        if(sub>=0){
            answer.push_back(i+1);
        }
       
    }
    return answer;
}