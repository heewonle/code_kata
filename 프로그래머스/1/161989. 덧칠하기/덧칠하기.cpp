#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int check = section[0];
    int count = 1;
    for(int i=0; i<section.size(); i++){
        if(section[i]-check<m){
            continue;
        }
        else{
            check = section[i];
            count+=1;
        }
    }
    answer = count;
    return answer;
}