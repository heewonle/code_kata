#include <string>
#include <vector>
#include <bitset>
#include <iostream>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i=0; i<n; i++){
        string s;
        for(int j = n - 1; j >= 0; --j){
            char a1 = ((arr1[i] >> j) & 1) ? '1' : '0';
            char a2 = ((arr2[i] >> j) & 1) ? '1' : '0';
            if(a1=='1' || a2== '1'){
                s+='#';
            }
            else{
                s+=' ';
            }
        }
        answer.push_back(s);
    }
    return answer;
}