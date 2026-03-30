#include <vector>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> triangle(n);
    for (int i = 0; i < n; i++) {
        triangle[i] = vector<int>(i + 1, 0);
    }
    int total = n * (n + 1) / 2;
    int dr[3] = {1, 0, -1};
    int dc[3] = {0, 1, -1};

    int r = 0;
    int c = 0;
    int dir = 0;
    for (int num = 1; num <= total; num++) {
        triangle[r][c] = num;
        int nr = r + dr[dir];
        int nc = c + dc[dir];
        if (nr < 0 || nr >= n || nc < 0 || nc >= triangle[nr].size() || triangle[nr][nc] != 0) {
            dir = (dir + 1) % 3;
            nr = r + dr[dir];
            nc = c + dc[dir];
        }
        r = nr;
        c = nc;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            answer.push_back(triangle[i][j]);
        }
    }
    return answer;
}