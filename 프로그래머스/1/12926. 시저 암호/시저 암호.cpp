#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s, int n) {
    string answer = "";
    char c;
    for(int i=0; i<s.length(); i++){
        if(s[i]==' '){
            c=' ';
        }
        else if(s[i]<='z' && s[i]>='a'){
            if(s[i]=='z' || s[i]+n>'z'){
               c=s[i]-26+n;
            }
            else{
                c=s[i]+n;
            }
        }
        else{
            if(s[i]=='Z'||s[i]+n>'Z'){
                 c = s[i] -26 + n;
            }
            else{
                c=s[i]+n;
            }
        }
        answer +=c;
    }
    return answer;
}