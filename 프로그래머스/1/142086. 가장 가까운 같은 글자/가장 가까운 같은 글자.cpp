#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map<char,int> ch_num;
    for(int i=0; i<s.length(); i++){
            if(ch_num.find(s[i])==ch_num.end()){
                ch_num[s[i]]=i;
                answer.push_back(-1);
            }
            else{
                answer.push_back(i-ch_num[s[i]]);
                ch_num[s[i]]=i;
            }
       
    }
    for(auto v : ch_num){
        
    }
    return answer;
}