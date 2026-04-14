#include <vector>
#include <string>
using namespace std;

bool IsValid(const vector<string>& room) {
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            if (room[r][c] != 'P') continue;
            int dr1[4] = {-1, 1, 0, 0};
            int dc1[4] = {0, 0, -1, 1};

            for (int d = 0; d < 4; d++) {
                int nr = r + dr1[d];
                int nc = c + dc1[d];

                if (nr < 0 || nr >= 5 || nc < 0 || nc >= 5) continue;

                if (room[nr][nc] == 'P') {
                    return false;
                }
            }

            int dr2[4] = {-2, 2, 0, 0};
            int dc2[4] = {0, 0, -2, 2};

            for (int d = 0; d < 4; d++) {
                int nr = r + dr2[d];
                int nc = c + dc2[d];

                if (nr < 0 || nr >= 5 || nc < 0 || nc >= 5) continue;

                if (room[nr][nc] == 'P') {
                    int mr = r + dr2[d] / 2;
                    int mc = c + dc2[d] / 2;

                    if (room[mr][mc] != 'X') {
                        return false;
                    }
                }
            }

            int dr3[4] = {-1, -1, 1, 1};
            int dc3[4] = {-1, 1, -1, 1};

            for (int d = 0; d < 4; d++) {
                int nr = r + dr3[d];
                int nc = c + dc3[d];

                if (nr < 0 || nr >= 5 || nc < 0 || nc >= 5) continue;

                if (room[nr][nc] == 'P') {
                    if (room[r][nc] != 'X' || room[nr][c] != 'X') {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for (const auto& room : places) {
        if (IsValid(room)) answer.push_back(1);
        else answer.push_back(0);
    }

    return answer;
}