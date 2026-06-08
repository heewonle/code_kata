#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    vector<vector<int>> boxes;
    int h = ceil((float)n / (float)w);
    int index = -1;
    int numRow = -1;

    for (int i = 0; i < h; i++) {
        vector<int> temp;

        for (int j = 1; j <= w; j++) {
            if ((i + 1) % 2 == 0) {
                if (j + i * w <= n) {
                    temp.insert(temp.begin(), j + i * w);

                    if (j + i * w == num) {
                        index = w - j;
                        numRow = i;
                    }
                }
                else {
                    temp.insert(temp.begin(), -1);
                }
            }
            else {
                if (j + i * w <= n) {
                    temp.push_back(j + i * w);

                    if (j + i * w == num) {
                        index = j - 1;
                        numRow = i;
                    }
                }
                else {
                    temp.push_back(-1);
                }
            }
        }

        boxes.push_back(temp);
    }

    for (int i = numRow; i < boxes.size(); i++) {
        if (boxes[i][index] != -1) {
            answer += 1;
        }
    }

    return answer;
}