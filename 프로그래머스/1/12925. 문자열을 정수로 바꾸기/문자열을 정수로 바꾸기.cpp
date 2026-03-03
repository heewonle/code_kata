#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 1;
    if(s[0]=='-'){
        answer= -1;
        s=s.substr(1, s.length());
    }else if(s[0]=='+'){
        answer = 1;
        s=s.substr(1, s.length());
    }
    answer *= stoi(s);
    return answer;
}