// 11266

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define endl "\n"

using namespace std;

int V, E;
vector<vector<int>> graph;
vector<int> search_seq;
vector<bool> visited;
set<int> cut_vertex;
int seq = 0;

void init() {
	cin >> V >> E;
	graph.resize(V + 1, {});
	int u, v;
	for (int i = 0; i < E; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	search_seq.resize(V + 1);
	visited.resize(V + 1, false);
}



int dfs(int now_v, int parent_v) {
	seq++;
	search_seq[now_v] = seq;
	int lsv = search_seq[now_v];
	visited[now_v] = true;
	int child_cnt = 0;

	for (auto child_v : graph[now_v]) {
		if (child_v == parent_v)
			continue;

		if (visited[child_v]) {
			lsv = min(lsv, search_seq[child_v]);
			continue;
		}
		child_cnt++;
		int subtree_lsv = dfs(child_v, now_v);
		lsv = min(subtree_lsv, lsv);

		if (parent_v != 0 && subtree_lsv >= search_seq[now_v]) {
			/*
				subtree_lsv > search_seq[now_v] : child_v의 서브트리에서 now_v로 돌아오는 간선이 없다.
				subtree_lsv == search_seq[now_v] : child_v의 서브트리는 now_v에게만 돌아오는 간선(back-edge)가 있다
					ex)		now_v
							/	\
					   child_v   x
					child_v -> now_v로 돌아갈 수 있음. 하지만 now_v를 제거하면 child_v의 서브트리는 외부와 영원히 단절
			*/
			cut_vertex.insert(now_v);
		}
	}

	if (parent_v == 0 && child_cnt >= 2)
		cut_vertex.insert(now_v);

	return lsv;
}


int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	init();
	for (int i = 1; i <= V; i++) {
		if (visited[i]) continue;
		dfs(i, 0);
	}
	
	cout << cut_vertex.size() << endl;
	for (auto& x : cut_vertex) {
		cout << x << " ";
	}
}