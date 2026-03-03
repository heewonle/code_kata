#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool compare(char a, char b){
    return a>b;
}
long long solution(long long n) {
    long long answer = 0;
    vector<char> string_vector;
    string num_string = to_string(n);
    for(int i=0; i<num_string.length(); i++){
            string_vector.push_back(num_string[i]);
    }
    sort(string_vector.begin(),string_vector.end(),compare);
    string answer_string = "";
    for(auto& str : string_vector){
        answer_string += str;
    }
    answer = stod(answer_string);
    return answer;
}