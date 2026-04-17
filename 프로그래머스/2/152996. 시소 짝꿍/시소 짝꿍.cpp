#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    
    sort(weights.begin(), weights.end());
    
    unordered_map<int, long long> freq;
    
    for (int w : weights) {
        answer += freq[w];
        if ((w * 2) % 3 == 0) {
            answer += freq[(w * 2) / 3];
        }
        if (w % 2 == 0) {
            answer += freq[w / 2];
        }
        if ((w * 3) % 4 == 0) {
            answer += freq[(w * 3) / 4];
        }
        freq[w]++;
    }
    
    return answer;
}