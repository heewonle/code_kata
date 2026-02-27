#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string t, string p) {
    int answer = 0;
    for(int i=0; i<t.length(); i++){
        string sub = t.substr(i,p.length());
        if(sub.length()==p.length()){
            if(stoll(sub)<=stoll(p)){
                answer+=1;
            }
        }  
    }
    return answer;
}