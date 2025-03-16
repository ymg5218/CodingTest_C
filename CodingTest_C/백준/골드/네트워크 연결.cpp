// 1922

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> graph[1001];
bool isMST[1001] = { false, };


int Prim() {
	// first : cost * -1, second : destination vertex
	priority_queue<pair<int, int>> pq;
	auto MST_TotalLength = 0;

	isMST[1] = true;
	for (int i{ 0 }; i < graph[1].size(); i++) {
		pq.push({ graph[1][i].first * -1, graph[1][i].second });
	}

	int cost, v;
	while (!pq.empty()) {
		if (isMST[pq.top().second]) {
			pq.pop();
		}
		else {
			cost = pq.top().first * -1;
			v = pq.top().second;
			pq.pop();
			isMST[v] = true; MST_TotalLength += cost;

			for (int i{ 0 }; i < graph[v].size(); i++) {
				if (!isMST[graph[v][i].second]) {
					pq.push({ graph[v][i].first * -1, graph[v][i].second });
				}
			}
		}
	}

	return MST_TotalLength;
}

int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	int v1, v2, c;
	cin >> N >> M;

	for (int i{ 0 }; i < M; i++) {
		cin >> v1 >> v2 >> c;
		graph[v1].push_back({ c, v2 });
		graph[v2].push_back({ c, v1 });
	}

	cout << Prim() << endl;
}
