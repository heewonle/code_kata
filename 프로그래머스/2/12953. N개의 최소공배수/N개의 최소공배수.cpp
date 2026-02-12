#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;
int gcd(int a, int b){
    int max_value = max(a,b);
    int min_value = min(a,b);
    while(max_value%min_value!=0){
        int least = max_value % min_value;
        max_value = min_value;
        min_value = least;
    }
    return min_value;
}
int solution(vector<int> arr) {
    int answer = arr[0];
    for(int j=1; j<arr.size(); j++){
        int l = gcd(answer, arr[j]);
        int lcm = answer * arr[j] / l;
        answer = lcm;
    }
    return answer;
}