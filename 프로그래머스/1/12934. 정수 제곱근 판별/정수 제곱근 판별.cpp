#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

long long solution(long long n) {
    long long answer = -1;
    cout<<pow(11,2)<<endl;
    for(int i=1; i<100000000; i++){
        if(n==pow(i,2)){
           return answer = pow(i+1,2);
        }
    }
    return answer;
}