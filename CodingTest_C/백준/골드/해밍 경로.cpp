// 2481

#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <map>
#include <queue>
#define endl "\n"
#define uint unsigned int
#define ll long long

using namespace std;

map<uint, uint> m;
vector<vector<uint>> adj;
vector<int> visited;
int N, K, M;

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	
	cin >> N >> K;
	adj.resize(N + 1);
	visited.resize(N + 1, false);
	for (int i = 1; i < N + 1; i++) {
		string w_str;
		cin >> w_str;
		uint w = 0;
		int p = 1;
		for (int j = K - 1; j >= 0; j--) {
			if (w_str[j] == '1')
				w += p;
			p *= 2;
		}
		m[w] = i;
	}
	
	for (auto& word : m) {
		for (int digit = 0; digit < K; digit++) {
			if (m.find(word.first ^ (1 << digit)) != m.end())
				adj[word.second].push_back(m[word.first ^ (1 << digit)]);
		}
	}

	queue<ll> q;
	visited[1] = 1;
	q.push(1);

	while (!q.empty()) {
		ll node = q.front();
		q.pop();

		for (auto& i : adj[node]) {
			if (!visited[i]) {
				visited[i] = node;
				q.push(i);
			}
		}
	}

	cin >> M;
	
	while (M--) {
		ll w;
		cin >> w;
		if (!visited[w]) {
			cout << -1 << endl;
			continue;
		}
		int x = w;
		vector<int> ans;
		cout << 1 << ' ';
		while (x != 1) {
			ans.push_back(x);
			x = visited[x];
		}
		for (int i = ans.size() - 1; i >= 0; i--) {
			cout << ans[i] << " ";
		}
		cout << endl;
	}
}