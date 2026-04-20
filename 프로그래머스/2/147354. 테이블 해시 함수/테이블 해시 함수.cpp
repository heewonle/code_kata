#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
        sort(data.begin(), data.end(), [&](const vector<int>& a, const vector<int>& b) {
        if (a[col - 1] != b[col - 1]) return a[col - 1] < b[col - 1];
        return a[0] > b[0];
    });
    for (int i = row_begin; i <= row_end; i++) {
        int sum = 0;
        for (int num : data[i - 1]) {
            sum += num % i;
        }
        answer ^= sum;
    }
    return answer;
}