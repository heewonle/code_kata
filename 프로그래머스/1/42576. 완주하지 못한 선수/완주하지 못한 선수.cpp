#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string,int> checks;
    for(string s : participant){
        checks[s] +=1;
    }
    for(string s : completion){
        checks[s] -=1;
    }
    for(auto k : checks){
        if(k.second!=0){
            answer = k.first;
        }
    }
    return answer;
}