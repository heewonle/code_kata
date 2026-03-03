#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> nums ={};
    istringstream iss(s);
    int num;
    while(iss>>num){
        nums.push_back(num);
    }
    answer+= to_string(*min_element(nums.begin(),nums.end()));
    answer+= " ";
    answer+= to_string(*max_element(nums.begin(),nums.end()));
    return answer;
}