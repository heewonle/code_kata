#include <string>
#include <vector>

using namespace std;
int DFS(int current, const vector<vector<int>>& graph, vector<bool>& visited, int A, int B){
    visited[current] = true;
    int count = 1;
    for(int next : graph[current]){
        if((current==A && next==B) || (current == B && next==A)){
            continue;
        }
        if(!visited[next]){
            count+=DFS(next,graph,visited,A,B);
        }
    }
    return count;
}
int solution(int n, vector<vector<int>> wires) {
    vector<vector<int>> graph(n+1);
    int answer = n;
    for(const auto& wire : wires){
        int a= wire[0];
        int b = wire[1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
      for(const auto& wire : wires){
        int a = wire[0];
        int b = wire[1];
        vector<bool> visted(n+1, false);
        int countA = DFS(a,graph, visted, a,b);
        int countB = n - countA;
        int diff = abs(countA - countB);
        answer= min(answer,diff);
    }
    return answer;
}