#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, M, K;
int a, b;
long long int c;
vector<long long int> arr;
vector<long long int> tree;

long long int init(int node, int start, int end) {
    if (start == end) return tree[node] = arr[start];
    int mid = (start + end) / 2;

    return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

long long int sum(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;

    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int index, long long int diff) {
    if (index < start || index > end) return;
    tree[node] += diff;

    if (start != end) {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, index, diff);
        update(node * 2 + 1, mid + 1, end, index, diff);
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(NULL);

    cin >> N >> M >> K;

    arr.resize(N);

    int h = (int)ceil(log2(N));
    int tree_size = (1 << (h + 1));
    tree.resize(tree_size);

    long long int x;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    init(1, 0, N - 1);

    for (int i = 0; i < M + K; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            update(1, 0, N - 1, b - 1, c - arr[b - 1]);
            arr[b - 1] = c;
        }
        else {
            cout << sum(1, 0, N - 1, b - 1, c - 1) << "\n";
        }
    }
}