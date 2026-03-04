#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Info {
    int deadline, get_cnt;
};

bool compareInfo(const Info& a, const Info& b) {
    if (a.deadline == b.deadline) return a.get_cnt > b.get_cnt;
    return a.deadline < b.deadline;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    vector<Info> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i].deadline >> v[i].get_cnt;
    }

    sort(v.begin(), v.end(), compareInfo);

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < N; i++) {
        pq.push(v[i].get_cnt);
        if (pq.size() > (size_t)v[i].deadline) {
            pq.pop();
        }
    }
    long long total_cnt = 0;
    while (!pq.empty()) {
        total_cnt += pq.top();
        pq.pop();
    }

    cout << total_cnt << "\n";

    return 0;
}