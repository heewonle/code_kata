#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int solution(vector<vector<int>> signals) {
    int n = signals.size();
    vector<int> cycles;
    for (auto& s : signals) {
        cycles.push_back(s[0] + s[1] + s[2]);
    }

    int limit = cycles[0];
    for (int i = 1; i < n; i++) {
        limit = lcm(limit, cycles[i]);
    }

    for (int t = 1; t <= limit; t++) {
        bool allYellow = true;

        for (int i = 0; i < n; i++) {
            int G = signals[i][0];
            int Y = signals[i][1];
            int R = signals[i][2];

            int cycle = G + Y + R;
            int pos = (t - 1) % cycle;

            if (!(G <= pos && pos < G + Y)) {
                allYellow = false;
                break;
            }
        }

        if (allYellow) {
            return t;
        }
    }

    return -1;
}