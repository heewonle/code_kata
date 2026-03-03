#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string,unordered_set<string>> comb;
    for(int i=0; i<clothes.size(); i++){
        string key =  clothes[i][1];
        comb[key] = {"X"};
    }
    for(int i=0; i<clothes.size(); i++){
        string key =  clothes[i][1];
        comb[key].insert(clothes[i][0]);
    }          
    for(auto k : comb){
        answer*=k.second.size();
    }    
    answer-=1;
    return answer;
}