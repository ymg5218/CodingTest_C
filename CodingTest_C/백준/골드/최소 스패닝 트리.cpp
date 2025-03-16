#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int node_parent[10001];

class Edge {
public:
	int node[2];
	int distance;
	Edge(int a, int b, int distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}

	// 정렬할 때, 간선의 길이 기준으로 정렬하도록 세팅
	bool operator< (Edge& edge) {
		return this->distance < edge.distance;
	}
};

int get_Parent(int v) {
	if (node_parent[v] == v) return v;
	else return node_parent[v] = get_Parent(node_parent[v]);
}

bool is_Cycle(int v1, int v2) {
	v1 = get_Parent(v1);
	v2 = get_Parent(v2);
	if (v1 == v2) return true;
	else return false;
}

void union_Parent(int v1, int v2) {
	v1 = get_Parent(v1);
	v2 = get_Parent(v2);
	if (v1 <= v2) node_parent[v2] = v1;
	else node_parent[v1] = v2;
}


/*

7 11
1 7 12
1 4 23
1 2 26
2 3 36
2 4 21
2 5 45
3 5 29
3 6 37
3 7 55
4 7 20
5 6 30

*/

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int V, E;
	cin >> V >> E;
	for (int i = 1; i <= V; i++) {
		node_parent[i] = i;
	}

	vector<Edge> graph;

	int v1, v2, dis;
	for (int i = 0; i < E; i++) {
		cin >> v1 >> v2 >> dis;
		graph.push_back(Edge(v1, v2, dis));
	}

	sort(graph.begin(), graph.end());

	int MST_nodeCnt = 0;
	long long int result = 0;

	for (int i = 0; i < graph.size(); i++) {
		if (!is_Cycle(graph[i].node[0], graph[i].node[1])) {
			result += graph[i].distance;
			union_Parent(graph[i].node[0], graph[i].node[1]);
			MST_nodeCnt++;
		}
		if (MST_nodeCnt == V - 1) break;
	}

	cout << result;

}