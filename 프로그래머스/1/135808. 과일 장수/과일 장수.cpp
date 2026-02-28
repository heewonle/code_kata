#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(int a, int b){
    return a<b;
}
int solution(int k, int m, vector<int> score) {
    int answer = 0;
    vector<int> count;
    sort(score.begin(),score.end(),compare);
    while( count.size()+score.size()>=m){
        count.push_back(score[score.size()-1]);
        score.pop_back();
        if(count.size()==m){
            answer+=*min_element(count.begin(),count.end())*m;
            count.clear();
        }
    }


    return answer;
}