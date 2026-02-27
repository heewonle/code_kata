#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    unordered_map<string, int> need;
    need.reserve(want.size() * 2);
    for (int i = 0; i < (int)want.size(); i++) {
        need[want[i]] = number[i];
    }

    unordered_map<string, int> cur;
    cur.reserve(64);

    auto add = [&](const string& item, int delta) {
        int next = (cur.count(item) ? cur[item] : 0) + delta;
        if (next == 0) cur.erase(item);
        else cur[item] = next;
    };

    auto isMatch = [&]() -> bool {
        for (int i = 0; i < (int)want.size(); i++) {
            auto it = cur.find(want[i]);
            int have = (it == cur.end() ? 0 : it->second);
            if (have != need[want[i]]) return false;
        }
        return true;
    };

    if ((int)discount.size() < 10) return 0;

    for (int i = 0; i < 10; i++) add(discount[i], +1);

    if (isMatch()) answer++;

    for (int i = 10; i < (int)discount.size(); i++) {
        add(discount[i - 10], -1); 
        add(discount[i], +1);      
        if (isMatch()) answer++;
    }
    
    return answer;
}