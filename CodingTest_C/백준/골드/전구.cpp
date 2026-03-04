#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> sw_to_idx(N + 1);
    vector<int> sw_order(N);
    for (int i = 0; i < N; i++) {
        cin >> sw_order[i];
        sw_to_idx[sw_order[i]] = i;
    }

    vector<int> pos(N);
    for (int i = 0; i < N; i++) {
        int bulb;
        cin >> bulb;
        pos[i] = sw_to_idx[bulb];
    }

    vector<int> length(N, 1);
    vector<int> parent(N, -1);

    for (int target = 0; target < N; target++) {
        for (int comp = 0; comp < target; comp++) {
            if (pos[target] > pos[comp]) {
                if (length[target] < length[comp] + 1) {
                    length[target] = length[comp] + 1;
                    parent[target] = comp;
                }
            }
        }
    }

    int max_len = 0;
    int last_idx = 0;
    for (int i = 0; i < N; i++) {
        if (length[i] > max_len) {
            max_len = length[i];
            last_idx = i;
        }
    }

    cout << max_len << "\n";

    vector<int> res;
    int curr = last_idx;
    while (curr != -1) {
        res.push_back(sw_order[pos[curr]]);
        curr = parent[curr];
    }

    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << (i == res.size() - 1 ? "" : " ");
    }

}