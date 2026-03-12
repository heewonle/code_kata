#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <cmath>
using namespace std;

int solution(string word) {
    int answer = 0;
    unordered_map<char,int> alpha_cost = {{'A',0},{'E',1},{'I',2},{'O',3},{'U',4}};
    int weight[5] = {781, 156, 31, 6, 1};

    for (int i = 0; i < word.size(); i++) {
        answer += alpha_cost[word[i]] * weight[i] + 1;
    }


    return answer;
}