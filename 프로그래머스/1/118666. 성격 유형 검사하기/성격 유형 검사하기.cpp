#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    unordered_map<char,int> check = {{'R',0},{'T',0},{'C',0},{'F',0},{'J',0},{'M',0},{'A',0},{'N',0}};
    vector<string> answer_check = {"RT","CF","JM","AN"};
    for(int i=0; i<survey.size(); i++){
        int num = choices[i];
        if(num<=3){
            check[survey[i][0]] +=4-num;
        }
        if(num>=5){
            check[survey[i][1]]+=num-4;
        }
    }
    for(string s : answer_check){
        char c1 = s[0];
        char c2  = s[1];
        if(check[c1]>check[c2]){
            answer += c1;
        }
        if(check[c1]<check[c2]){
            answer += c2;
        }
        if(check[c1]==check[c2]){
            if(c1<c2){
                answer+=c1;
            }
            else{
                answer+=c2;
            }
            
        }
    }
    return answer;
}