// 17228

#include <iostream>
#include <vector>
#include <string>
#include <deque>
#define ll long long

using namespace std;

int N;
vector<vector<pair<int, char>>> tree;
vector<bool> visited;
string P;
deque<char> now_T;
int cnt = 0;

ll pattern_hash = 0;
ll prime = 1'000'000'007;

void init() {
	cin >> N;
	tree.resize(N + 1);
	int u, v;
	char c;
	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v >> c;
		tree[u].push_back({ v, c });
	}
	visited.resize(N + 1, false);
	
	cin >> P;
}

bool is_match() {
	bool is_find = true;
	for (int i = 0; i < P.size(); i++) {
		if (now_T[i] != P[i]) {
			is_find = false;
			break;
		}
	}
	return is_find;
}

void dfs(int now_v, ll text_hash, ll now_power) {
	int m = P.size();

	if (text_hash == pattern_hash && now_T.size() == m) {
		if (is_match())
			cnt++;
	}

	if (tree[now_v].empty()) {
		return;
	}

	for (const auto& [next_v, next_c] : tree[now_v]) {
		if (visited[next_v]) continue;
		visited[next_v] = true;

		if (now_T.size() == m) {
			char temp = now_T.front();
			now_T.pop_front();
			now_T.push_back(next_c);

			ll h = (text_hash - ((ll)temp * now_power) % prime + prime) % prime;
			h = (h * 403) % prime;
			h = (h + (ll)next_c) % prime;

			dfs(next_v, h, now_power);

			now_T.pop_back();
			now_T.push_front(temp);
		}
		else {
			now_T.push_back(next_c);
			ll nh = ((text_hash * 403) % prime + (ll)next_c) % prime;
			dfs(next_v, nh, now_power);
			now_T.pop_back();
		}
		visited[next_v] = false;
	}
}



int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	init();

	ll power = 1;
	for (int i = 0; i < P.size(); i++) {
		pattern_hash = ((pattern_hash * 403) % prime) + int(P[i]) % prime;
	}

	for (int i = 1; i < P.size(); i++) {
		power = (power * 403) % prime;
	}
	if (P.size() <= N)
		dfs(1, 0, power);

	cout << cnt;
	
}