#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    int start_num = min(a,b);
    int end_num = max(a,b);

    for(int i = start_num; i<=end_num; i++){
        answer += i;
    }
    return answer;
}