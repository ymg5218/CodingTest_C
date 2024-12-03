#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
    int N, M;
    cin >> N >> M;

    int* inDegree = new int[N + 1] {0};
    vector<int>* graph = new vector<int>[N + 1];

    int v1, v2;

    for (int i = 0; i < M; i++) {
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        inDegree[v2]++;
    }

    priority_queue<int> pq;

    for (int idx = N; idx > 0; idx--) {
        if (inDegree[idx] == 0) {
            // 최대 힙 구조이므로, -1을 곱하여 삽입
            pq.push(idx * -1);
        }
    }

    int now_v, next_v;
    int* result = new int[N] { 0 };
    int seq = 0;

    while (!pq.empty()) {
        now_v = pq.top() * -1;
        result[seq] = now_v;
        seq++;
        pq.pop();

        for (int i = 0; i < graph[now_v].size(); i++) {
            next_v = graph[now_v][i];
            inDegree[next_v]--;
            if (inDegree[next_v] == 0) {
                pq.push(next_v * -1);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << result[i] << " ";
    }

    return 0;
}