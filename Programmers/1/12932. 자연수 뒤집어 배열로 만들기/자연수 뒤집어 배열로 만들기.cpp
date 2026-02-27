#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    string num_string = to_string(n);
    for(int i=num_string.length()-1; i>=0; i--){
       int num = num_string[i] - '0';
       answer.push_back(num);
    }
    return answer;
}