#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
bool comp(int a, int b){
    return a>b;
}
int solution(vector<int> citations) {
    int answer = 0;
    map<int,int,greater<int>> count_map;
    sort(citations.begin(),citations.end(),comp);
    for(int i=0; i<citations.size(); i++){
        count_map[citations[i]] =0;
    }
    for(int i=0; i<citations.size(); i++){
        count_map[citations[i]] +=1;
    }
    vector<pair<int,int>> v(count_map.begin(),count_map.end());
    vector<int> counts(count_map.size(),v[0].second);
    for(int i=1; i<count_map.size(); i++){
        counts[i]  =v[i].second + counts[i-1];
    }
    for (int i=0; i<(int)counts.size(); i++){
        answer = max(answer, min(counts[i], v[i].first));
    }

    return answer;
}