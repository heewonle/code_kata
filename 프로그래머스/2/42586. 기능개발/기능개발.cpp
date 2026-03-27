#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> pq;

    for (int i = 0; i < progresses.size(); i++) {
        int days = ceil((float)(100 - progresses[i]) / speeds[i]);
        pq.push(days);
    }

    if (pq.empty()) return answer;

    int before = pq.front();
    int count = 0;

    while (!pq.empty()) {
        int t = pq.front();

        if (t <= before) {
            count++;
        } else {
            answer.push_back(count);
            before = t;
            count = 1;
        }

        pq.pop();
    }

    answer.push_back(count);

    return answer;
}