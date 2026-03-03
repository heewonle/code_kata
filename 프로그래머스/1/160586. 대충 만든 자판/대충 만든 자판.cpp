#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    for(string s : targets){
        int count = 0;
        int checks = 0;
        for(int i=0; i<s.length(); i++){
            char c = s[i];
            vector<int> counts;
            for(string k : keymap){
                auto it =  k.find(c);
                if(it != string::npos){
                    counts.push_back(it+1);
                }
            }
            if(counts.size()==0){
                checks+=1;
                break;
            }
            else{
                int min_count = *min_element(counts.begin(),counts.end());
                count += min_count;
            }
        }
        if(checks>0){
            answer.push_back(-1);
        }
        else{
            answer.push_back(count);
        }

    }
    return answer;
}