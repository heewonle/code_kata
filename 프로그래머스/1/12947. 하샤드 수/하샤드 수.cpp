#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = false;
    string num_string = to_string(x);
    int check_num=0;
    for(char c : num_string){
        check_num += c-'0';
    }
    if(x%check_num==0){
        answer = true;
    }
    return answer;
}