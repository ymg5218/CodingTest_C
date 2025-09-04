#include <iostream>
#include <vector>
#include <queue>
#define endl "\n"

using namespace std;

int N, K;

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

    cin >> N >> K;
    queue<pair<int, int>> q; 
    vector<int> max_k(N, -1);
    q.push({ 1, K });  

    for (int i = 0; i < N; i++) {
        int M;
        cin >> M;
        vector<int> now_tree(M);
        for (int j = 0; j < M; j++) cin >> now_tree[j];

        if (q.empty()) {  
            for (++i; i < N; ++i) {
                int M2; cin >> M2;
                for (int j = 0, tmp; j < M2; ++j) cin >> tmp;
            }
            break;
        }

        const int HMAX = 21;
        vector<int> best(HMAX, -1);

        queue<pair<int, int>> _q;

        while (!q.empty()) {
            auto [now_h, now_k] = q.front(); q.pop();

            for (int x : now_tree) {

                bool ok = false;
                if (now_h == x) ok = true;                               // O
                else if (now_h + 1 == x) ok = true;                      // A
                else if (min(now_h * 2, 20) == x) ok = true;             // B
                else if (max(now_h - 1, 0) == x) ok = true;              // C

                int nk = now_k;
                if (!ok) {
                    if (nk == 0) continue;
                    nk -= 1;
                }

                if (0 <= x && x < HMAX && best[x] < nk) {
                    best[x] = nk;
                }
            }
        }

        // 다음 레벨 큐 구성
        int this_max = -1;
        for (int h = 0; h < HMAX; ++h) {
            if (best[h] >= 0) {
                this_max = max(this_max, best[h]);
                q.push({ h, best[h] });
            }
        }
        max_k[i] = this_max;
    }

    cout << max_k[N - 1] << endl;
    return 0;
}
