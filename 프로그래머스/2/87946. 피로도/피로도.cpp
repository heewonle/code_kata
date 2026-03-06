#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    int n = dungeons.size();
    int FULL = 1<< n;
    vector<int> dp(FULL,-1);
    
    dp[0] = k;
    for(int i=0; i<FULL; i++){
        if(dp[i]<0){
            continue;
        }
        answer = max(answer,__builtin_popcount(i));
        for(int j =0; j<n; j++){
            if(i & (1<<j)) continue;
            int req = dungeons[j][0];
            int cost = dungeons[j][1];
            if(dp[i]>=req){
                int next = i | (1<<j);
                int nextReq = dp[i] - cost;
                dp[next] = max(dp[next],nextReq);
            }
            
        }
    }
    return answer;
}