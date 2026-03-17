#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> topping) {
    int answer = 0;

    vector<int> rightCount(10001, 0);
    vector<bool> leftVisited(10001, false);

    int rightKinds = 0;
    int leftKinds = 0;

    for (int t : topping) {
        if (rightCount[t] == 0) rightKinds++;
        rightCount[t]++;
    }
    for (int i = 0; i < topping.size() - 1; i++) {
        int t = topping[i];
        if (!leftVisited[t]) {
            leftVisited[t] = true;
            leftKinds++;
        }
        rightCount[t]--;
        if (rightCount[t] == 0) {
            rightKinds--;
        }
        if (leftKinds == rightKinds) {
            answer++;
        }
    }

    return answer;
}