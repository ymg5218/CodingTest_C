#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n, false);

    for (int start_v = 0; start_v < n; start_v++) {
        if (visited[start_v]) continue;

        queue<int> q;
        q.push(start_v);
        visited[start_v] = true;

        while (!q.empty()) {
            int now_v = q.front();
            q.pop();

            for (int next_v = 0; next_v < n; next_v++) {
                if (next_v == start_v) continue;
                if (computers[now_v][next_v] == 1 && !visited[next_v]) {
                    q.push(next_v);
                    visited[next_v] = true;
                }
            }
        }

        answer++;
    }

    return answer;
}