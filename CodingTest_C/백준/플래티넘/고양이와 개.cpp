// 3683

#include <iostream>
#include <vector>

#define endl "\n"

using namespace std;

vector<pair<string, string>> votes;
vector<vector<int>> graph;	// 의견이 충돌되는 두 사람을 잇는 이분 그래프
vector<bool> visited;
vector<int> checked; 

int c, d, v;

void init() {
	cin >> c >> d >> v;
	votes.assign(v, {});
	graph.assign(v, {});
	checked.assign(v, -1);

	for (int i = 0; i < v; i++) {
		cin >> votes[i].first >> votes[i].second;
	}
}

void set_bigraph() {
	for (int i = 0; i < v; i++) {
		for (int j = i + 1; j < v; j++) {
			if (votes[i].first == votes[j].second || votes[i].second == votes[j].first) {
				if (votes[i].first[0] == 'D')	// 개를 좋아하는 사람이 왼쪽 그룹, 고양이를 좋아하는 사람이 오른쪽 그룹으로 통일
					graph[i].push_back(j);
				else
					graph[j].push_back(i);
			}
		}
	}
}

int dfs(int now_v) {
	for (const auto& x : graph[now_v]) {
		if (visited[x]) continue;
		visited[x] = true;

		if (checked[x] == -1 || dfs(checked[x])) {
			checked[x] = now_v;
			return 1;
		}
	}
	return 0;
}

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	int T; cin >> T;
	while (T--) {
		init();
		set_bigraph();
		
		int conflict_cnt = 0;
		
		for (int i = 0; i < v; i++) {
			visited.assign(v, false);
			if (dfs(i)) conflict_cnt++;
		}
		
		cout << v - conflict_cnt << endl;
	}
}