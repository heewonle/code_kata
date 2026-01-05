#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

map<string,int> number_map = {{"zero",0},{"one",1},{"two",2},{"three",3},
                              {"four",4},{"five",5},{"six",6},{"seven",7},
                              {"eight",8},{"nine",9}};
map<int,int> answer_map;
int solution(string s) {
    int answer = 0;
    for(int i=0; i<s.length(); i++){
        int num  = s[i] -'0';
        if(num<=9){
            answer_map[i] = num;
        }
    }
    for(int i=0; i<20; i++){
        for(auto& m : number_map){
            string key = m.first;
            auto it =s.find(key);
            if(it != string::npos){
                int num = m.second;
                answer_map[it] = num;
                s[it] = ' ';
            }
        }        
    }

    string answer_string ="";
    for(auto& m : answer_map){
        int num = m.second;
        answer_string += to_string(num);
    }
    answer = stoi(answer_string);
    return answer;
}