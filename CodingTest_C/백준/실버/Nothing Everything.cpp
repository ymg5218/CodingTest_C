// 32760

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<int> degree;
vector<bool> removed;
int N, M;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	cin >> N >> M;
	graph.assign(N + 1, {});
	degree.assign(N + 1, 0);
	removed.assign(N + 1, false);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    string res = "";
    int active_cnt = N;

    for (int i = N; i >= 2; i--) {
        if (degree[i] == active_cnt - 1) {
            res += 'E';
            for (int now_v : graph[i]) 
                if (!removed[now_v]) 
                    degree[now_v]--;
        }

        else if (degree[i] == 0) {
            res += 'N';
        }
        else {
            cout << -1;
            return 0;
        }

        removed[i] = true;
        active_cnt--;
    }

    reverse(res.begin(), res.end());
    cout << res;
}