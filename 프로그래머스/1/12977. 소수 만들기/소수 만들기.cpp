#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    vector<vector<int>> comb;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                comb.push_back({i,j,k});
            }
        }
    }
    for(auto& n : comb){
        int sum  = nums[n[0]] + nums[n[1]] + nums[n[2]];
        cout<<sum<<endl;
        set<int> div;
        for(int i=1; i<=sum; i++){
            if(sum%i==0){
                div.insert(i);
            }
            if(div.size()>2){
                break;
            }
        }
        if(div.size()==2){
            answer+=1;
        }
    }

    return answer;
}