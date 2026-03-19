#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for (long long x : numbers) {
        if (x % 2 == 0) {
            answer.push_back(x + 1);
        } else {
            answer.push_back(x + 1 + ((x ^ (x + 1)) >> 2));
        }
    }
    return answer;
}