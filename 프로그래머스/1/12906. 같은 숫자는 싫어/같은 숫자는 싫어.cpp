#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    queue<int> checks;
    for(int i : arr){
        checks.push(i);
    }
    int num = 10;
    while(!checks.empty()){
        int n = checks.front();
        if(n==num){
            checks.pop();
        }
        else{
            num = n;
            answer.push_back(n);
            checks.pop();
        }
    }

    return answer;
}