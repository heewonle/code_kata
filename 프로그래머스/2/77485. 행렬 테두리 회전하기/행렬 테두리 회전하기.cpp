#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    vector<vector<int>> mat(rows, vector<int>(columns));
    int num = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            mat[i][j] = num++;
        }
    }
    
    for (const auto& q : queries) {
        int x1 = q[0] - 1;
        int y1 = q[1] - 1;
        int x2 = q[2] - 1;
        int y2 = q[3] - 1;
        
        int prev = mat[x1][y1];
        int minValue = prev;
        
        for (int y = y1 + 1; y <= y2; y++) {
            int temp = mat[x1][y];
            mat[x1][y] = prev;
            prev = temp;
            minValue = min(minValue, prev);
        }
        for (int x = x1 + 1; x <= x2; x++) {
            int temp = mat[x][y2];
            mat[x][y2] = prev;
            prev = temp;
            minValue = min(minValue, prev);
        }
        for (int y = y2 - 1; y >= y1; y--) {
            int temp = mat[x2][y];
            mat[x2][y] = prev;
            prev = temp;
            minValue = min(minValue, prev);
        }
        for (int x = x2 - 1; x >= x1; x--) {
            int temp = mat[x][y1];
            mat[x][y1] = prev;
            prev = temp;
            minValue = min(minValue, prev);
        }
        
        answer.push_back(minValue);
    }
    
    return answer;
}