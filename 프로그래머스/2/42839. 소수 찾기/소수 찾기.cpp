#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
unordered_set<int> visited;
int answer = 0;

bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

void dfs(string& numbers, vector<bool>& used, int current) {
    if (visited.find(current) == visited.end()) {
        visited.insert(current);
        if (isPrime(current)) {
            answer++;
        }
    }
    for (int i = 0; i < numbers.size(); i++) {
        if (used[i]) continue;
        used[i] = true;
        int next = current * 10 + (numbers[i] - '0');
        dfs(numbers, used, next);
        used[i] = false;
    }
}

int solution(string numbers) {
    vector<bool> used(numbers.size(), false);
    dfs(numbers,used,0);
    return answer;
}