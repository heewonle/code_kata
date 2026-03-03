#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool compare(int a, int b){
    return a>b;
}
vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> king;
    for(int i=0; i<score.size(); i++){
        king.push_back(score[i]);
        sort(king.begin(),king.end(),compare);
        if(king.size()<=k){
            answer.push_back(king[king.size()-1]);
        }
        else{
            answer.push_back(king[k-1]);
        }
    }
    return answer;
}