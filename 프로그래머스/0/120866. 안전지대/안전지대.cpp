#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board) {
    int n = board.size();
    int m = board[0].size();

    vector<vector<bool>> danger(n, vector<bool>(m, false));

    int dx[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
    int dy[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 1) {
                for (int k = 0; k < 9; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                        continue;
                    }

                    danger[nx][ny] = true;
                }
            }
        }
    }

    int answer = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!danger[i][j]) {
                answer++;
            }
        }
    }

    return answer;
}