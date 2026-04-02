#include <vector>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int n = (int)queue1.size();

    long long sum1 = 0;
    long long sum2 = 0;

    for (int x : queue1) sum1 += x;
    for (int x : queue2) sum2 += x;

    long long total = sum1 + sum2;
    if (total % 2 != 0) return -1;

    long long target = total / 2;
    if (sum1 == target) return 0;

    vector<int> arr;
    arr.reserve(n * 2);
    for (int x : queue1) arr.push_back(x);
    for (int x : queue2) arr.push_back(x);

    int left = 0;
    int right = n;
    int answer = 0;

    int limit = n * 4;

    while (answer <= limit) {
        if (sum1 == target) return answer;

        if (sum1 > target) {
            if (left >= 2 * n) break;
            sum1 -= arr[left];
            left++;
        } else {
            if (right >= 2 * n) break;
            sum1 += arr[right];
            right++;
        }

        answer++;
    }

    return -1;
}