// 2357

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define endl "\n"
#define ll long long

using namespace std;

int N, M;
vector<pair<ll, ll>> tree;
vector<ll> arr;
unordered_map<ll, int> idx;

void init(int node, int start, int end) {
	if (start == end) {
		idx[arr[start]] = node;
		tree[node] = { arr[start], arr[start] };
		return;
	}
	
	int mid = (start + end) / 2;
	init(node * 2, start, mid);
	init(node * 2 + 1, mid + 1, end);
	ll max_element = max(tree[node * 2].first, tree[node * 2 + 1].first);
	ll min_element = min(tree[node * 2].second, tree[node * 2 + 1].second);
	tree[node] = { max_element, min_element };
	return;
}

pair<ll, ll> find(int node, int start, int end, int left, int right) {
	if (right < start || end < left) 
		return { 0, 1e9 };
	
	if (left <= start && end <= right) 
		return tree[node];

	pair<ll, ll> l, r;
	int mid = (start + end) / 2;
	l = find(node * 2, start, mid, left, right);
	r = find(node * 2 + 1, mid + 1, end, left, right);
	int max_element = max(l.first, r.first);
	int min_element = min(l.second, r.second);
	return {max_element, min_element};
}




int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	cin >> N >> M;
	arr.resize(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	tree.resize(4 * N);

	init(1, 0, N - 1);

	while (M--) {
		int left, right;
		cin >> left >> right;

		auto [max_res, min_res] = find(1, 0, N - 1, left - 1, right - 1);

		cout << min_res << " ";
		cout << max_res << endl;
	}
}