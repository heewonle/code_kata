#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

vector<int> updateDp(const vector<int>& dp, int a, int b, int n, int m)
{
    vector<int> ret(m, INF);

    for (int j = 0; j < m; j++)
    {
        if (dp[j] == INF) continue;

        if (dp[j] + a < n)
            ret[j] = min(ret[j], dp[j] + a);

        if (j + b < m)
            ret[j + b] = min(ret[j + b], dp[j]);
    }

    return ret;
}


int solution(vector<vector<int>> info, int n, int m) {
    vector<int> dp(m, INF);
    dp[0] = 0;

    for (auto& v : info)
    {
        dp = updateDp(dp, v[0], v[1], n, m);
    }

    int ans = *min_element(dp.begin(), dp.end());

    return ans == INF ? -1 : ans;
}