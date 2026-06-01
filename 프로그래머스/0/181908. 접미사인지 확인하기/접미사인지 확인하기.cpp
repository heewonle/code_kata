#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int solution(string my_string, string is_suffix) {
    int answer = 0;
    stack<char> q_string;
    for(char c : my_string){
        q_string.push(c);
    }
    string check = "";
    while(!q_string.empty()){
        char c = q_string.top();
        check = c + check;
        cout<<check<<endl;
        if(check==is_suffix){
            answer=1;
        }
        q_string.pop();
    }
    
    return answer;
}