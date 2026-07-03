#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int n = park.size();
    int m = park[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    int maxEmptySquare = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (park[i][j] == "-1") {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = min({
                        dp[i - 1][j],
                        dp[i][j - 1],
                        dp[i - 1][j - 1]
                    }) + 1;
                }

                maxEmptySquare = max(maxEmptySquare, dp[i][j]);
            }
        }
    }

    sort(mats.begin(), mats.end(), greater<int>());

    for (int mat : mats) {
        if (mat <= maxEmptySquare) {
            return mat;
        }
    }

    return -1;
}