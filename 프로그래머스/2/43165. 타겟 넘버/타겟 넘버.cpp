#include <string>
#include <vector>
#include <numeric>
using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int sum = accumulate(numbers.begin(), numbers.end(), 0);

    if (sum + target < 0 || (sum + target) % 2 != 0) return 0;

    int goal = (sum + target) / 2;
    vector<int> dp(goal + 1, 0);
    dp[0] = 1;

    for (int num : numbers) {
        for (int s = goal; s >= num; s--) {
            dp[s] += dp[s - num];
        }
    }

    answer = dp[goal];

    return answer;
}