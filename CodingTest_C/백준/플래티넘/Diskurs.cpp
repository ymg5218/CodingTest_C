#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define endl "\n"

using namespace std;

const int MAX_SIZE = (1 << 20);
int dist[MAX_SIZE];

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);

    fill(dist, dist + (1 << m), -1);

    queue<int> q;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (dist[a[i]] == -1) {
            dist[a[i]] = 0;
            q.push(a[i]);
        }
    }

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int i = 0; i < m; i++) {
            int next_val = curr ^ (1 << i);

            if (dist[next_val] == -1) {
                dist[next_val] = dist[curr] + 1;
                q.push(next_val);
            }
        }
    }

    int all_ones = (1 << m) - 1;
    for (int i = 0; i < n; i++) {
        int target = a[i] ^ all_ones;
        cout << m - dist[target] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
}