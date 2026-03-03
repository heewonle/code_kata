#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int count =0;
    int zero_count =0;
    while(s.length()!=1){
        int temp=s.length();
        for(int i=0; i<s.length(); i++){
            if(s[i]=='0'){
                temp-=1;
                zero_count+=1;
            }
        }
        string binary = "";
        while (temp > 0) {
            binary += to_string(temp % 2);
            temp /= 2;
        }
        reverse(binary.begin(), binary.end());
        s = binary;
        count+=1;
    }
    answer={count, zero_count};
    return answer;
}