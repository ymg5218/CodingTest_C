// 1976

#include <iostream>
#include <vector>
#define endl "\n"

using namespace std;

vector<vector<int>> graph;
vector<int> parent;
vector<bool> visited;
vector<int> travel;

int getParent(int x) {
	if (parent[x] == x) return x;
	else return parent[x] = getParent(parent[x]);
}

void setUnion(int x, int y) {
	x = getParent(x);
	y = getParent(y);
	if (x != y) {
		parent[x] = x >= y ? y : x;
		parent[y] = x <= y ? x : y;
	}
}

void solution() {
	for (int v = 1; v < graph.size(); v++) {
		for (int u = 0; u < graph[v].size(); u++) {
			setUnion(v, graph[v][u]);
		}
	}
	
	for (int i = 1; i < travel.size(); i++) {
		if (parent[travel[i]] != parent[travel[i - 1]]) {
			cout << "NO"; return;
		}
	}
	cout << "YES";
}

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);

	
	int N, M;
	cin >> N >> M;
	graph.resize(N + 1);
	parent.resize(N + 1);
	visited.resize(N + 1, false);
	travel.resize(M);
	for (int i = 0; i < N; i++) {
		parent[i + 1] = i + 1;
		for (int j = 0; j < N; j++) {
			int c;
			cin >> c;
			if (c) {
				graph[i + 1].push_back(j + 1);
			}
		}
	}
	
	for (int i = 0; i < M; i++) {
		cin >> travel[i];
	}
	solution();
	
}