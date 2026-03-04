// 11505

#include <iostream>
#include <vector>
#include <cmath>

#define mod 1'000'000'007
#define endl "\n"
#define ll long long

using namespace std;

int N, M, K;
int tree_h, tree_size;
vector<ll> segtree;
vector<int> arr;

ll init(int idx, int l, int r) {
	if (l == r) {
		return segtree[idx] = arr[l];
	}
	int mid = (l + r) / 2;
	ll left_c = init(idx * 2, l, mid) % mod;
	ll right_c = init(idx * 2 + 1, mid + 1, r) % mod;
	segtree[idx] = left_c * right_c % mod; 
	
	return segtree[idx];
}

ll mul(int idx, int s, int e, int l, int r)	// s, e : 해당 인덱스의 노드가 포함하고 있는 범위,
{											// l, r : 우리가 구하고자하는 범위
	if (l > e || r < s) return 1;			// 1. [s, e]에 [l, r]이 전혀 포함되지 않을 때
	if (l <= s && e <= r) return segtree[idx];	// 2. [s, e]에 [l, r]이 완전히 포함될 때

											// 3. 일부만 포함될 때
	int mid = (s + e) / 2;
	ll left_res = mul(idx * 2, s, mid, l, r) % mod;
	ll right_res = mul(idx * 2 + 1, mid + 1, e, l, r) % mod;
	return (left_res * right_res) % mod;
}

ll update(int idx, int s, int e, int target_idx, ll val) {
	if (target_idx < s || target_idx > e) return segtree[idx];
	if (s == e) return segtree[idx] = val;

	int mid = (s + e) / 2;
	ll left_res = update(idx * 2, s, mid, target_idx, val);
	ll right_res = update(idx * 2 + 1, mid + 1, e, target_idx, val);
	return segtree[idx] = (left_res * right_res) % mod;
}

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	cin >> N >> M >> K;
	tree_h = (int)ceil(log2(N));
	tree_size = (1 << (tree_h + 1));
	segtree.resize(tree_size);
	arr.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	
	init(1, 0, N - 1);
	
	for (int i = 0; i < M + K; i++) {
		int a, b, c; cin >> a >> b >> c;
		if (a == 1) {
			arr[b - 1] = c;
			update(1, 0, N - 1, b - 1, c);
		}
		else {
			cout << mul(1, 0, N - 1, b - 1, c - 1) << endl;
		}
	}
}