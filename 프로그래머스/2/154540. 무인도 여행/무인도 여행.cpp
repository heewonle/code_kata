#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    int n = maps.size();
    int m = maps[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (maps[r][c] == 'X' || visited[r][c]) continue;
            queue<pair<int, int>> q;
            q.push({r, c});
            visited[r][c] = true;
            int sum = 0;
            while (!q.empty()) {
                int cr = q.front().first;
                int cc = q.front().second;
                q.pop();
                sum += maps[cr][cc] - '0';
                for (int d = 0; d < 4; d++) {
                    int nr = cr + dr[d];
                    int nc = cc + dc[d];
                    if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                    if (visited[nr][nc]) continue;
                    if (maps[nr][nc] == 'X') continue;
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
            answer.push_back(sum);
        }
    }
    if (answer.empty()) return {-1};
    sort(answer.begin(), answer.end());
    return answer;
}