#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> sub;
    int n = order.size();

    for (int box = 1; box <= n; box++) {
        if (box == order[answer]) {
            answer++;
        } else {
            sub.push(box);
        }
        while (!sub.empty() && answer < n && sub.top() == order[answer]) {
            sub.pop();
            answer++;
        }
    }

    return answer;
}