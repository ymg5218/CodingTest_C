// 1939 - 중량제한
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#define endl "\n"
#define ll long long
#define INF LLONG_MAX

using namespace std;

int N, M;
vector<vector<pair<int, ll>>> bridges;
vector<ll> max_weight;

void dijkstra(int v1, int v2) {
    priority_queue<pair<ll, int>> pq;
<<<<<<< HEAD
    max_weight[v1] = INF; 
=======
    max_weight[v1] = INF;
>>>>>>> dca016cacaf980c44063ad3079e0a02f665da7a4
    pq.push({ INF, v1 });

    while (!pq.empty()) {
        auto [now_w, now_v] = pq.top();
        pq.pop();

<<<<<<< HEAD
        if (now_v == v2) { 
=======
        if (now_v == v2) {
>>>>>>> dca016cacaf980c44063ad3079e0a02f665da7a4
            cout << now_w << endl;
            return;
        }

        if (max_weight[now_v] > now_w) continue;

        for (auto [next_v, w] : bridges[now_v]) {
            ll next_w = min(now_w, w);
            if (next_w > max_weight[next_v]) {
                max_weight[next_v] = next_w;
                pq.push({ next_w, next_v });
            }
        }
    }
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

    cin >> N >> M;
    bridges.assign(N + 1, {});
    max_weight.assign(N + 1, 0);

    for (int i = 0; i < M; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        bridges[u].push_back({ v, w });
        bridges[v].push_back({ u, w });
    }

    int v1, v2;
    cin >> v1 >> v2;

    dijkstra(v1, v2);
}
