#include <string>
#include <vector>
#include<iostream>
using namespace std;

bool solution(string s) {
    bool answer = true;
    if(s.length()==4 || s.length()==6){
        for(int i=0; i<s.length(); i++){
            int num = s[i] -'0';
            if(num>9){
                return false;
            }
        } 
    }
    else{
        answer= false;
    }
    return answer;
}