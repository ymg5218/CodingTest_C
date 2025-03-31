// 4803

#include <iostream>
#include <vector>
#include <queue>
#define endl "\n"

using namespace std;

int test_case = 1;

class Graph {
private:
	vector<vector<int>> graph;
	vector<int> parent;
	vector<bool> visited;
	vector<int> constructed_vertexs;
	int n, m;
	int tree_cnt;
	bool cycled = false;
public:
	Graph(int n, int m) {
		this->n = n;
		this->m = m;
		this->tree_cnt = 0;
		graph.resize(n + 1);
		visited.resize(n + 1);
		for (int i{ 0 }; i <= n; i++) {
			parent.push_back(i);
		}
	}

	void setGraph(int v1, int v2) {
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}

	int find_parent(int v) {
		if (v == parent[v]) return v;
		return parent[v] = find_parent(parent[v]);
	}

	void union_parent(int v1, int v2) {
		v1 = find_parent(v1);
		v2 = find_parent(v2);
		if (v1 > v2) parent[v1] = v2;
		else parent[v2] = v1;
	}

	bool parent_isSame(int v1, int v2) {
		if (find_parent(v1) == find_parent(v2)) return true;
		else return false;
	}

	void dfs(int now_v, int prev_v) {
		if (now_v <= 0) return;
		visited[now_v] = true;
		constructed_vertexs.push_back(now_v);
		for (int next_v : graph[now_v]) {
			if (next_v == prev_v) {
				continue;
			}
			if (find_parent(now_v) == find_parent(next_v)) this->cycled = true;
			if (!visited[next_v]) {
				union_parent(now_v, next_v);
				dfs(next_v, now_v);
			}
		}
	}

	void solution() {
		for (int i{ 1 }; i <= n; i++) {
			this->cycled = false;
			if (!visited[i]) {
				dfs(i, -1);
				if (!cycled) {
					this->tree_cnt++;
				}
			}
		}

		if (tree_cnt > 1) {
			cout << "Case " << test_case << ": A forest of " << tree_cnt << " trees." << endl;
		}
		else if (tree_cnt == 1) {
			cout << "Case " <<  test_case << ": There is one tree." << endl;
		}
		else {
			cout << "Case " << test_case << ": No trees." << endl;
		}
	}

};

int main(void) {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

	int n, m;
	int v1, v2;
	
	while (true) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		Graph totalGraph(n, m);
		
		
		while (m--) {
			cin >> v1 >> v2;
			totalGraph.setGraph(v1, v2);
		}
		totalGraph.solution();
		test_case++;
	}
}