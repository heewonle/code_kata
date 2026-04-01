#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int n = sequence.size();

    int left = 0;
    long long sum = 0;

    int bestLeft = 0;
    int bestRight = n - 1;

    for (int right = 0; right < n; right++) {
        sum += sequence[right];
        while (sum > k && left <= right) {
            sum -= sequence[left];
            left++;
        }
        if (sum == k) {
            int currentLen = right - left;
            int bestLen = bestRight - bestLeft;
            if (currentLen < bestLen || (currentLen == bestLen && left < bestLeft)) {
                bestLeft = left;
                bestRight = right;
            }
        }
    }
    answer = {bestLeft,bestRight};
    return answer;
}