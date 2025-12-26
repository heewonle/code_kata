#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int mid_index = s.length()/2;
    if(s.length()%2==0){
        answer = s.substr(mid_index-1,2);
    }
    else{
        answer = s.substr(mid_index,1);
    }
    return answer;
}