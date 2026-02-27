#include <string>
#include <vector>
#include <cmath>
#include <set>
using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int max_value = max(n,m);
    int min_value = min(n,m);
    while(min_value!=0){
        int least =  max_value%min_value;
        if(least<max_value && least>min_value){
            max_value = least;
        }
        else if(least<min_value){
            max_value = min_value;
            min_value = least;
        }
    }
    answer.push_back(max_value);
    answer.push_back(n*m/max_value);
    
    return answer;
}