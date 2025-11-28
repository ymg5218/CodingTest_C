// 2887

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define endl "\n"
#define ll long long

using namespace std;

int N;
vector<pair<ll, int>> X;	// {谅钎蔼, 青己 锅龋}
vector<pair<ll, int>> Y;
vector<pair<ll, int>> Z;
vector<pair<ll, pair<int, int>>> adj;	// 牢立 芭府, {牢立茄 青己 1, 牢立茄 青己 2}

vector<int> parent;

void init() {
	cin >> N;
	parent.resize(N);

	for (int i = 0; i < N; i++) {
		ll x, y, z;
		cin >> x >> y >> z;
		X.push_back({ x, i });
		Y.push_back({ y, i });
		Z.push_back({ z, i });
		parent[i] = i;
	}

	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	sort(Z.begin(), Z.end());

	for (int i = 0; i < N - 1; i++) {
		adj.push_back({ abs(X[i].first - X[i + 1].first), {X[i].second, X[i + 1].second} });
		adj.push_back({ abs(Y[i].first - Y[i + 1].first), {Y[i].second, Y[i + 1].second} });
		adj.push_back({ abs(Z[i].first - Z[i + 1].first), {Z[i].second, Z[i + 1].second} });
	}
	
	sort(adj.begin(), adj.end());
}

int get_parent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = get_parent(parent[x]);
}

void set_union(int x, int y) {
	x = get_parent(x);
	y = get_parent(y);
	
	if (x > y) swap(x, y);
	parent[y] = x;
}

ll solution() {
	ll total_len = 0;

	for (int i = 0; i < adj.size(); i++) {
		auto [x, y] = adj[i].second;
		ll dis = adj[i].first;
		
		if (get_parent(x) != get_parent(y)) {
			set_union(x, y);
			total_len += dis;
		}
	}

	return total_len;
}

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	init();
	cout << solution() << endl;
}
