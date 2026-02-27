#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> ans1 = {1,2,3,4,5};
    vector<int> ans2 = {2,1,2,3,2,4,2,5};
    vector<int> ans3 = {3,3,1,1,2,2,4,4,5,5};
    
    vector<int> correct={0,0,0};
    for(int i=0; i<answers.size(); i++){
        int ans1_n = i-ans1.size()*(i/ans1.size());
        int ans2_n = i-ans2.size()*(i/ans2.size());
        int ans3_n = i-ans3.size()*(i/ans3.size());
        if(ans1[ans1_n]==answers[i]){
            correct[0]+=1;
        }
        if(ans2[ans2_n]==answers[i]){
            correct[1]+=1;
        }
        if(ans3[ans3_n]==answers[i]){
            correct[2]+=1;
        }
        else{
            continue;
        }

    }
    int maxScore = *max_element(correct.begin(), correct.end());
    for (int i=0; i<correct.size(); i++) {
        if (correct[i] == maxScore)
            answer.push_back(i+1);
    }
    return answer;
}