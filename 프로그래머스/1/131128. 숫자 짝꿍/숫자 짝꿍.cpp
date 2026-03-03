#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(string X, string Y) {
    string answer = "";
    map<char,vector<int>,greater<char>> nums = {{'9',{0,0}},{'8',{0,0}},{'7',{0,0}},
                                   {'6',{0,0}},{'5',{0,0}},{'4',{0,0}},
                                   {'3',{0,0}},{'2',{0,0}},{'1',{0,0}},{'0',{0,0}}};

    for(int i=0; i<X.length(); i++){
        char s = X[i];
        nums[s][0]+=1;
        
    }
    for(int j=0; j<Y.length(); j++){
        char s = Y[j];
        nums[s][1]+=1;
    }
    for(auto& a : nums){
        vector<int> count = a.second;
        int min_count = *min_element(count.begin(),count.end());
        while(min_count>0){
            answer+=a.first;
            min_count--;
        }
    }
    if(answer==""){
        answer="-1";
    }
    if(answer[0]=='0'){
        answer= "0";
    }
    return answer;
}