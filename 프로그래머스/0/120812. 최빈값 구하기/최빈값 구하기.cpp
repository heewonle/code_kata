#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int solution(vector<int> array) {

    unordered_map<int,int> check;
    
    for(int c : array){
        check[c] +=1;
    }
    auto max_k =  max_element(check.begin(),check.end(),[](const auto &p1, const auto &p2){
        return p1.second < p2.second;
    });
    int max_value = max_k->second;
    int max_count = 0;
    for(auto k : check){
        if(k.second == max_value){
            max_count+=1;
        }
    }
    int answer=max_k->first;
    if(max_count>1){
        answer=-1;
    }
    return answer;
}