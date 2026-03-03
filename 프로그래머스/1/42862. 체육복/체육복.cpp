#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    for (auto it = lost.begin(); it != lost.end(); ) {
        auto r = find(reserve.begin(), reserve.end(), *it);
        if (r != reserve.end()) {
            reserve.erase(r);
            it = lost.erase(it);
        } else it++;
    }
    for(int i=0; i<lost.size(); i++){
        int num = lost[i];
        auto it1 = find(reserve.begin(),reserve.end(),num-1);
        auto it2 = find(reserve.begin(),reserve.end(),num+1);
    
        if(it1!=reserve.end()){
            reserve.erase(it1);
        }
        else if(it2!=reserve.end()){
            reserve.erase(it2); 
        }
        else{
            answer--;
        }
    }
    return answer;
}