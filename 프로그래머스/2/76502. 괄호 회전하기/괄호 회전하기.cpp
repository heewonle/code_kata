#include <string>
#include <vector>
#include <iostream>
using namespace std;
bool Check(string s){
    string open = "";

    for(int i=0; i<s.length(); i++){
        char ch = s[i];

        if(ch=='(' || ch=='[' || ch=='{'){
            open += ch;
        }
        else{
            if(open.length()==0) return false;

            char last = open[open.length()-1];
            open = open.substr(0, open.length()-1);

            if((ch==')' && last!='(') ||
               (ch==']' && last!='[') ||
               (ch=='}' && last!='{')){
                return false;
            }
        }
    }

    if(open.length()!=0) return false;
    return true;
}
int solution(string s) {
    int answer= 0;
    if(Check(s)){
        answer++;
    }
    for(int i=1; i<s.length(); i++){

        char ss = s[0];
        string temp = s.substr(1,s.length()-1);
        s = temp + ss;

        if(Check(s)){
            answer++;
        }
    }
    return answer;
}