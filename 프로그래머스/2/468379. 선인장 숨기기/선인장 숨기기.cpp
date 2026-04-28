#include <vector>
#include <deque>
using namespace std;

vector<int> solution(int m, int n, int h, int w, vector<vector<int>> drops)
{
    const int INF = m * n + 1;

    vector<vector<int>> rain(m, vector<int>(n, INF));

    for (int i = 0; i < (int)drops.size(); i++)
    {
        int r = drops[i][0];
        int c = drops[i][1];
        rain[r][c] = i + 1;
    }

    int colCount = n - w + 1;
    vector<vector<int>> rowMin(m, vector<int>(colCount));

    for (int r = 0; r < m; r++)
    {
        deque<int> dq;

        for (int c = 0; c < n; c++)
        {
            while (!dq.empty() && rain[r][dq.back()] >= rain[r][c])
                dq.pop_back();

            dq.push_back(c);

            if (!dq.empty() && dq.front() <= c - w)
                dq.pop_front();

            if (c >= w - 1)
            {
                int startCol = c - w + 1;
                rowMin[r][startCol] = rain[r][dq.front()];
            }
        }
    }

    int bestTime = -1;
    int bestR = 0;
    int bestC = 0;

    for (int c = 0; c < colCount; c++)
    {
        deque<int> dq;

        for (int r = 0; r < m; r++)
        {
            while (!dq.empty() && rowMin[dq.back()][c] >= rowMin[r][c])
                dq.pop_back();

            dq.push_back(r);

            if (!dq.empty() && dq.front() <= r - h)
                dq.pop_front();

            if (r >= h - 1)
            {
                int startRow = r - h + 1;
                int startCol = c;

                int cactusTime = rowMin[dq.front()][c];

                if (cactusTime > bestTime ||
                    (cactusTime == bestTime &&
                     (startRow < bestR ||
                      (startRow == bestR && startCol < bestC))))
                {
                    bestTime = cactusTime;
                    bestR = startRow;
                    bestC = startCol;
                }
            }
        }
    }

    return {bestR, bestC};
}