#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(vector<int> food) {
    string answer = "";
    string ans = "";
    for(int i=0; i<food.size(); i++){
        int count = food[i];
        if(count>=2){
            if(count%2!=0){
                count-=1;
            }
            for(int j=0; j<(count/2); j++){
                ans+=to_string(i);
            }
        }
    }
    answer = ans;
    answer +="0";
    for(int i=ans.size()-1; i>=0; i--){
        answer += ans[i];
    }
    return answer;
}