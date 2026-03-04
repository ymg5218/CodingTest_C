// 13306

#include <iostream>
#include <vector>

#define endl "\n"

using namespace std;

vector<pair<int, pair<int, int>>> query;
vector<int> parent;
vector<int> now_parent;
vector<string> result;

int N, Q;

int get_parent(int x) {
	if (x == now_parent[x])
		return x;
	return now_parent[x] = get_parent(now_parent[x]);
}

void set_union(int x, int y) {
	int x_p = get_parent(x);
	int y_p = get_parent(y);

	if (x_p == y_p) return;
	if (x_p < y_p) now_parent[y_p] = x_p;
	else now_parent[x_p] = y_p;
}

void init() {
	cin >> N >> Q;
	parent.resize(N + 1, 0);
	now_parent.resize(N + 1, 0);
	query.resize(N - 1 + Q, {});
	
	parent[1] = 1;
	now_parent[1] = 1;
	for (int i = 2; i <= N; i++) {
		cin >> parent[i];
		now_parent[i] = i;
	}
	
	for (int i = 0; i < N - 1 + Q; i++) {
		int x; cin >> x;
		if (x == 0) {
			int b; cin >> b;
			query[i] = { x, {b, -1} };
		}
		else {
			int c, d; cin >> c >> d;
			query[i] = { x, {c, d} };
		}
	}
}

void run_querys() {
	while (!query.empty()) {
		auto now_query = query.back();
		query.pop_back();

		int cmd = now_query.first; auto [x, y] = now_query.second;
		
		if (cmd == 0) {	// union
			set_union(x, parent[x]);
		}
		else {
			string res = (get_parent(x) == get_parent(y)) ? "YES" : "NO";
			result.push_back(res);
		}
	}

	while (!result.empty()) {
		cout << result.back() << endl;
		result.pop_back();
	}
}

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	init();
	run_querys();
}