// 34547

#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

ll dp[501][501];
ll prefix_max[501];
ll suffix_max[501];

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

    int N, A, B, K;
    cin >> N >> A >> B >> K;

    int S = A + B;

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= S; j++) {
            dp[i][j] = -1;
        }
    }

    dp[0][A] = 0;

    for (int i = 1; i <= N; i++) {
        prefix_max[0] = dp[i - 1][0];
        for (int j = 1; j <= S; j++) {
            prefix_max[j] = max(prefix_max[j - 1], dp[i - 1][j]);
        }

        suffix_max[S] = dp[i - 1][S];
        for (int j = S - 1; j >= 0; j--) {
            suffix_max[j] = max(suffix_max[j + 1], dp[i - 1][j]);
        }

        for (int j = 0; j <= S; j++) {
            ll prev_best = -1;

            if (j - K >= 0) {
                prev_best = max(prev_best, prefix_max[j - K]);
            }

            if (j + K <= S) {
                prev_best = max(prev_best, suffix_max[j + K]);
            }

            if (prev_best != -1) {
                dp[i][j] = prev_best + (ll)j * (S - j);
            }
        }
    }

    ll ans = 0;
    for (int j = 0; j <= S; j++) {
        ans = max(ans, dp[N][j]);
    }

    cout << ans << "\n";

    return 0;
}