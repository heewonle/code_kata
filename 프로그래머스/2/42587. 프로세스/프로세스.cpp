#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> priorities, int location) {
    queue<pair<int,int>> q;
    priority_queue<int> pq;

    for(int i = 0; i < priorities.size(); i++) {
        q.push({priorities[i], i});
        pq.push(priorities[i]);
    }

    int answer = 0;

    while(!q.empty()) {
        int current_priority = q.front().first;
        int current_index = q.front().second;
        q.pop();

        if(current_priority == pq.top()) {
            answer++;
            pq.pop();

            if(current_index == location)
                return answer;
        }
        else {
            q.push({current_priority, current_index});
        }
    }
    return answer;
}