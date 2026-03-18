#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int x, int y, int n) {
    const int INF = 1e9;
    vector<int> dp(y + 1, INF);

    dp[x] = 0;

    for (int i = x + 1; i <= y; i++) {
        if (i - n >= x) {
            dp[i] = min(dp[i], dp[i - n] + 1);
        }
        if (i % 2 == 0 && i / 2 >= x) {
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }
        if (i % 3 == 0 && i / 3 >= x) {
            dp[i] = min(dp[i], dp[i / 3] + 1);
        }
    }

    return dp[y] == INF ? -1 : dp[y];
}