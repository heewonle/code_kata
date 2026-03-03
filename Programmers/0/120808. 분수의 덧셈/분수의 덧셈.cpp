#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer;
    int num_answer = numer1 *denom2 + numer2*denom1;
    int denom_answer = denom1 *denom2;
    int r;
    int min_value;
    if(denom_answer > num_answer){
        r= denom_answer;
        min_value = num_answer;
    }
    else{
        r = num_answer;
        min_value = denom_answer;
    }
    int result  = r% min_value;
    while(result!=0){
        if(result > min_value){
            min_value = r;
            r = result;
        }else{
            r = min_value;
            min_value = result;        
        }
        result  = r% min_value;
    }
    answer.push_back(num_answer/min_value);
    answer.push_back(denom_answer/min_value);
    return answer;
}