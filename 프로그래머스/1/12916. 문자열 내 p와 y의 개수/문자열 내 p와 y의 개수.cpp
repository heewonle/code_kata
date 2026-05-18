#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int pCount =0;
    int yCount =0;
    for(char c : s){
        if(c=='p' || c=='P'){
            pCount+=1;
        }
        if(c=='y' || c=='Y'){
            yCount+=1;
        }
    }
    if(pCount!=yCount){
        answer =false;
    }

    return answer;
}