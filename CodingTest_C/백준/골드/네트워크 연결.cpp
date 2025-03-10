// 1922

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> edge[100001];
bool isMST[1001] = { false, };


int Prim() {
	priority_queue<pair<int, int>> pq;
	for (int i = 0; i < edge[1].size(); i++) {
		int v = edge[1][i].first;
		int cost = edge[1][i].second;
		pq.push({-1 * cost, v});
	}
	
	isMST[1] = true;
	int nowCost, toV;
	while (!pq.empty()) {
		nowCost = pq.top().first * -1;
		toV = pq.top().second;

	}

}

int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	int v1, v2, c;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> v1 >> v2 >> c;
		edge[v1].push_back({ v2, c });
		edge[v2].push_back({ v1, c });
	}

	cout << Prim() << endl;
}
