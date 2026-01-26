#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    sort(skip.begin(),skip.end());
     for (int i = 0; i < (int)s.length(); i++) {
            int moved = 0;
            while (moved < index) {
                s[i] += 1;
                if (s[i] > 'z') {
                    s[i] -= ('z' - 'a' + 1);
                }
                if (binary_search(skip.begin(), skip.end(), s[i])) {
                    continue;
                }
                moved++;
            }
    }
    answer = s;
    return answer;
}