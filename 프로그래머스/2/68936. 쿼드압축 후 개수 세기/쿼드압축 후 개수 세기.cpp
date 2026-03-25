#include <string>
#include <vector>

using namespace std;
vector<int> answer(2,0);

bool isSame(const vector<vector<int>>& arr, int x, int y, int size){
    int val = arr[x][y];
    
    for(int i=x; i<x+size; i++){
        for(int j=y; j<y+size; j++){
            if(arr[i][j]!=val){
                return false;
            }
        }
    }
    return true;
}

void dfs(const vector<vector<int>>& arr, int x, int y, int size){
    if(isSame(arr,x,y,size)){
        answer[arr[x][y]]++;
        return;
    }
    int half = size/2;
    dfs(arr,x,y,half);
    dfs(arr,x,y+half,half);
    dfs(arr,x+half,y,half);
    dfs(arr,x+half,y+half,half);
}
vector<int> solution(vector<vector<int>> arr) {
    dfs(arr,0,0,arr.size());
    return answer;
}