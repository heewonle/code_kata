#include <vector>
#include <queue>

using namespace std;

int solution(int N, vector<vector<int>> road, int K) {
    vector<vector<pair<int, int>>> graph(N + 1);

    for (const auto& r : road) {
        int a = r[0];
        int b = r[1];
        int c = r[2];

        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }
    
    vector<int> dist(N + 1, 500000);
    
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        int currentCost = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        if (currentCost > dist[currentNode]) {
            continue;
        }
        for (const auto& next : graph[currentNode]) {
            int edgeCost = next.first;
            int nextNode = next.second;

            int newCost = currentCost + edgeCost;

            if (newCost < dist[nextNode]) {
                dist[nextNode] = newCost;
                pq.push({newCost, nextNode});
            }
        }
    }

    int answer = 0;
    for (int i = 1; i <= N; i++) {
        if (dist[i] <= K) {
            answer++;
        }
    }

    return answer;
}