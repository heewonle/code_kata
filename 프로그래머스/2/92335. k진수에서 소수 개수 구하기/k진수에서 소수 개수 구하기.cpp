#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <iostream>
using namespace std;
bool is_prime(long long n){
    if (n <= 1) return false;
    for (int i = 2; i <= std::sqrt(n); ++i) {
        if (n % i == 0) return false; 
    }
    return true; 
}
int solution(int n, int k) {
    int answer = 0;
    string res = "";
    while (n > 0) {
        res += to_string(n % k);
        n /= k;
    }
    reverse(res.begin(), res.end());
    stringstream ss(res);
    char spliter  = '0';
    string token;
    while(getline(ss,token, spliter)){
        if(token!="" && is_prime(stoll(token))){
            answer+=1;
        }
    }
    return answer;
}