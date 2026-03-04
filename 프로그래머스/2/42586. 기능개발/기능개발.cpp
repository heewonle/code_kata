#include <string>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> before;
    for(int i=0; i<progresses.size(); i++){
    double day = (100 - progresses[i]) / (double)speeds[i];
    int result = (int)ceil(day);
        before.push_back(result);
    }
    int bf_day = before[0];
    unordered_map<int,int> counts;
    vector<int> days;
    days.push_back(bf_day);
    counts[bf_day] = 0;
    for(int i=1; i<before.size(); i++){
        if(before[i]<=bf_day){
            before[i] = bf_day;
        }
        else{
            bf_day = before[i];
            days.push_back(bf_day);
            counts[bf_day] =0;
        }
    }
    for(int i=0; i<before.size(); i++){
        counts[before[i]] +=1;
    }
    for(int d : days){
        answer.push_back(counts[d]);
    }
    return answer;
}