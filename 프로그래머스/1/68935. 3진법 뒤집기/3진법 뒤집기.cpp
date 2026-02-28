#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int>result;
    for(int i=17; i>=0; i--){
        int p= pow(3,i);
        int temp =n/p;
        if(n<pow(3,i) && result.empty()){
            continue;
        }
        else if(temp==1 || temp==2){
            result.push_back(temp);
            n-=temp*p;
        }
        else{
            result.push_back(0);
        }

    };
    
    for(int i=result.size()-1; i>=0; i--){
        cout<<result[i]<<endl;
        if(result[i]!=0){
            answer+=pow(3,i)*result[i];
        }
    }
        
    return answer;
}