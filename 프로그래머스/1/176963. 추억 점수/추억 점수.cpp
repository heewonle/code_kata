#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    unordered_map<string,int> check;
    for(int i=0; i<name.size(); i++){
        check[name[i]] = yearning[i];
    }
    for(auto v : photo){
        int grade =0;
        for(string s : v){
            grade+= check[s];
        }
        answer.push_back(grade);
    }
    return answer;
}