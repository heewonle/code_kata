#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int k, vector<int> tangerine) {
    unordered_map<int, int> freq;
    freq.reserve(tangerine.size());

    for (int x : tangerine) freq[x]++;

    vector<int> counts;
    counts.reserve(freq.size());
    for (auto &p : freq) counts.push_back(p.second);

    sort(counts.begin(), counts.end(), greater<int>());

    int sum = 0;
    int types = 0;
    for (int c : counts) {
        sum += c;
        types++;
        if (sum >= k) return types;
    }
    return types;
}