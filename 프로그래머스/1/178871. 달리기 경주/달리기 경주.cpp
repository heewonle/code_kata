#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    unordered_map<string,int> indexes;
    for(int j=0; j<players.size(); j++){
        indexes[players[j]] = j;
    }
    for(int i=0; i<callings.size(); i++){
        string name = callings[i];
        int it = indexes[name];
        if(it!=players.size()){
            string temp = players[it-1];
            players[it] = temp;
            players[it-1] = name;
            indexes[temp] = it;
            indexes[name] = it-1;
         }
    }
    answer= players;
    return answer;
}