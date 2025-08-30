// 1017 소수 쌍
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define endl "\n"

using namespace std;

int N;
vector<int> v1, v2;
vector<vector<int>> adj;
vector<int> match_v2; // v2의 매칭 상대 (v1의 인덱스)
vector<bool> is_prime;
vector<bool> visited;

void set_prime() {
    is_prime.assign(2001, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i <= sqrt(2000); i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= 2000; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

bool dfs(int now_idx, int fixed_v2) {
    for (int v : adj[now_idx]) {
        if (v == fixed_v2) continue; // 고정된 v2는 탐색 금지
        if (visited[v]) continue;
        visited[v] = true;
        if (match_v2[v] == -1 || dfs(match_v2[v], fixed_v2)) {
            match_v2[v] = now_idx;
            return true;
        }
    }
    return false;
}


int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

    cin >> N;

    int n;
    cin >> n;
    v1.push_back(n);

    for (int i = 1; i < N; i++) {
        cin >> n;
        if (v1[0] % 2 == n % 2)
            v1.push_back(n);
        else
            v2.push_back(n);
    }

    if (v1.size() != v2.size()) {
        cout << -1 << endl;
        return 0;
    }

    set_prime();

    vector<int> answers;

    // v1[0] 과 연결될 후보 v2[j] 찾기
    for (int j = 0; j < N / 2; j++) {
        if (!is_prime[v1[0] + v2[j]]) continue;

        // 인접 리스트 구성
        adj.assign(N / 2, {});
        for (int i = 0; i < N / 2; i++) {
            for (int k = 0; k < N / 2; k++) {
                if (is_prime[v1[i] + v2[k]])
                    adj[i].push_back(k);
            }
        }

        match_v2.assign(N / 2, -1);
        match_v2[j] = 0; // v1[0] - v2[j] 고정 매칭

        int match_cnt = 1;
        for (int i = 1; i < N / 2; i++) {
            visited.assign(N / 2, false);
            if (dfs(i, j)) match_cnt++;
        }

        if (match_cnt == N / 2)
            answers.push_back(v2[j]);
    }

    if (answers.empty())
        cout << -1 << endl;
    else {
        sort(answers.begin(), answers.end());
        for (auto& r : answers)
            cout << r << " ";
        cout << endl;
    }
}
