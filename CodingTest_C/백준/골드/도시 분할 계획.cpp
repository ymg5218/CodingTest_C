// 1647

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<pair<int, int>> graph[100001];
bool isMST[100001] = { false, };
int N, M;
int A, B, C;

auto Prim() {
	auto totalCost = 0;
	auto MaxEdgeCost = 0;
	int MSTNodeCnt = 0;
	
	priority_queue<pair<int, int>> pq;
	for (int i = 0; i < graph[1].size(); i++) {
		pq.push({ graph[1][i].first * -1, graph[1][i].second });
	}
	isMST[1] = true;
	MSTNodeCnt++;

	int cost, v;
	while (!pq.empty()) {
		if (MSTNodeCnt == N) break;

		if (isMST[pq.top().second]) {
			pq.pop();
		}
		else {
			cost = pq.top().first * -1;
			totalCost += cost;
			v = pq.top().second;
			pq.pop();
			if (MaxEdgeCost < cost) MaxEdgeCost = cost;
			isMST[v] = true;
			MSTNodeCnt++;
			for (int i = 0; i < graph[v].size(); i++) {
				pq.push({ graph[v][i].first * -1 , graph[v][i].second });
			}
		}
	}
	return totalCost - MaxEdgeCost;
}

int main(void) {
	cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i{ 0 }; i < M; i++) {
		cin >> A >> B >> C;
		graph[A].push_back({ C, B });
		graph[B].push_back({ C, A });
	}
	
	cout << Prim();
}