#include <iostream>
#include <vector>
#include <queue>
#define INF 1'000'000'000

using namespace std;

vector<vector<pair<int, int>>> set_graph(int n, vector<vector<int>> paths) {
    vector<vector<pair<int, int>>> graph(n + 1);
    for (const auto& p : paths) {
        int u = p[0];
        int v = p[1];
        int w = p[2];
        
        graph[u].push_back({ v, w });
        graph[v].push_back({ u, w });
    }
    return graph;
}

vector<int> set_node_kinds(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> node_kind(n + 1, 0);    // 0 : 쉼터, 1 : 출입구, 2 : 산봉우리
    
    for (auto n : gates) {
        node_kind[n] = 1;
    }
    for (auto n : summits) {
        node_kind[n] = 2;
    }
    
    return node_kind;
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer = {-1, INF};
    
    auto graph = set_graph(n, paths);
    auto node_kind = set_node_kinds(n, paths, gates, summits);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  // {거리, 목적 노드}
    for (const auto& now_gate : gates) {
        vector<bool> visited(n + 1, false);
        pq.push({ 0, now_gate });
        int max_dis = 0;
        while (!pq.empty()) {
            auto [now_w, now_v] = pq.top();
            pq.pop();
            if (visited[now_v]) continue;
            max_dis = max(max_dis, now_w);
            if (node_kind[now_v] == 2) {
                if (answer[1] > max_dis || (answer[1] == max_dis && answer[0] > now_v)) {
                    answer[0] = now_v;
                    answer[1] = max_dis;
                }
                continue;
            }
            visited[now_v] = true;

            for (const auto& [next_v, w] : graph[now_v]) {
                if (visited[next_v] || node_kind[next_v] == 1 || w > answer[1]) continue;
                pq.push({ w, next_v });
            }
        }
    }

    return answer;
}

int main(void) {
    int n = 6;
    vector<vector<int>> paths = { {1, 2, 3}, {2, 3, 5}, {2, 4, 2}, {2, 5, 4}, {3, 4, 4}, {4, 5, 3}, {4, 6, 1}, {5, 6, 1} };
    vector<int> gates = { 1, 3 };
    vector<int> summits = { 5 };
    auto result = solution(n, paths, gates, summits);
    cout << result[0] << " " << result[1];
}
