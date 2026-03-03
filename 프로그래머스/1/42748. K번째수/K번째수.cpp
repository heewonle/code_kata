#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
 
    for(auto& arr : commands){
        int i = arr[0]-1;
        int j = arr[1];
        int k = arr[2]-1;
        vector<int> ans;
        for(int t = i; t<j; t++){
            ans.push_back(array[t]);
        }
        sort(ans.begin(),ans.end());
        answer.push_back(ans[k]);
    }
  
    return answer;
}