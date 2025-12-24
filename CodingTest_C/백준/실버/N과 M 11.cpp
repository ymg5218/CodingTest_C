#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> arr;
vector<int> seq;

void backtracking(int depth) {
    if (depth == M) {
        for (int x : seq) {
            cout << x << " ";
        }
        cout << "\n";
        return;
    }

    int prev = -1;
    for (int i = 0; i < N; i++) {
        if (arr[i] == prev) continue;

        prev = arr[i];
        seq.push_back(arr[i]);
        backtracking(depth + 1);
        seq.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    arr.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    backtracking(0);
}
