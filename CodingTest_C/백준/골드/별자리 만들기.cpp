// 4386

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int n;
// {xÁÂÇ¥, yÁÂÇ¥}
vector<pair<double, double>> graph;

// { cost, {v1, v2}}
priority_queue <pair<double, pair<int, int>>> pq;


int parent[100] = { 0, };



int FindParent(int v1) {
	if (parent[v1] == v1) return v1;
	return parent[v1] = FindParent(parent[v1]);
}

void UnionParent(int v1, int v2) {
	v1 = FindParent(v1);
	v2 = FindParent(v2);
	if (v1 > v2) parent[v1] = v2;
	else parent[v2] = v1;
}

double Kruscal() {
	double TotalCost = 0;
	int MSTEdgeCnt = 0;

	int v1, v2;
	double cost;
	while (MSTEdgeCnt < n - 1) {
		if (FindParent(pq.top().second.first) == FindParent(pq.top().second.second)){
			pq.pop();
		}
		else {
			cost = -1 * pq.top().first;
			v1 = pq.top().second.first;
			v2 = pq.top().second.second;
			
			pq.pop();
			
			UnionParent(v1, v2);
			
			TotalCost += cost;
			MSTEdgeCnt++;
		}
	}

	return TotalCost;
}

int main(void) {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	
	double x, y;
	double x2, y2;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}

	for (int i{ 0 }; i < n; i++) {
		cin >> x >> y;
		graph.push_back({ x, y });
		if (i > 0) {
			for (int v1{ 0 }; v1 < i; v1++) {
				x2 = graph[v1].first;
				y2 = graph[v1].second;
				pq.push({ -1 * sqrt(pow(x - x2, 2) + pow(y - y2, 2)), {i, v1} });
			}
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << Kruscal();
}