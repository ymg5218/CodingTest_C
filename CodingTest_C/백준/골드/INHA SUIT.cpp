#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl "\n"

using namespace std;

int N, K;

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

    cin >> N >> K;
    vector<int> prev(21, -1);
    prev[1] = K;
    for (int i = 0; i < N; i++) {
        int M;
        cin >> M;
        vector<int> now(21, -1);
        while (M--) {
            int h;
            cin >> h;
            for (int prev_h = 1; prev_h <= 20; prev_h++) {
                if (prev[prev_h] == -1) continue;
                if (h == prev_h || h == min(prev_h + 1, 20) || h == min(prev_h * 2, 20) || h == max(prev_h - 1, 1))
                    now[h] = max(now[h], prev[prev_h]);
                else {
                    if (prev[prev_h] > 0)
                        now[h] = max(now[h], prev[prev_h] - 1);
                }
            }
        }
        prev = now;
    }
    int result = *max_element(prev.begin(), prev.end());
    if (result == -1) cout << -1;
    else cout << K - result;
}
