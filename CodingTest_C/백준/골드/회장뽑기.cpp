// 2660

#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#define INF 1e9

using namespace std;

int N;
vector<vector<int>> floyd;

void init() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (floyd[i][k] < INF && floyd[k][j] < INF) {
					floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
				}	
			}
		}
	}
}



int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	
	cin >> N;
	floyd.resize(N + 1, vector<int>(N + 1, INF));
	for (int i = 0; i <= N; i++) {
		floyd[i][i] = 0;
	}
	while (true) {
		int u, v;
		cin >> u >> v;
		if (u == -1 && v == -1) break;
		floyd[u][v] = 1;
		floyd[v][u] = 1;
	}
	init();

	vector<int> candidates;

	int min_dis = INF;
	for (int i = 1; i <= N; i++) {
		int dis = 0;
		for (int j = 1; j <= N; j++) {
			dis = max(dis, floyd[i][j]);
		}
		if (min_dis > dis) {
			candidates.clear();
			candidates.push_back(i);
			min_dis = dis;
		}
		else if (min_dis == dis)
			candidates.push_back(i);
	}

	cout << min_dis << " " << candidates.size() << endl;
	sort(candidates.begin(), candidates.end());
	for (auto& c : candidates) {
		cout << c << " ";
	}
}