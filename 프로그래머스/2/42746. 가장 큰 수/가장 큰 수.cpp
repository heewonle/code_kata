#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(int a, int b){
    string str_a = to_string(a) + to_string(b);
    string str_b = to_string(b) + to_string(a);
    return str_a>str_b;  
}
string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(),numbers.end(),comp);
    for(int i=0; i<numbers.size(); i++){
        answer+=to_string(numbers[i]);
    }
    if(numbers[0]==0){
        return "0";
    }
    return answer;
}