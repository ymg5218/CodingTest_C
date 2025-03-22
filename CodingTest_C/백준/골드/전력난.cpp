// 6497

#include <iostream>
#include <queue>

using namespace std;

class Kruskal {
private:
	int parent[200001];
	priority_queue<pair<long long int, pair<int, int>>> pq;
	
	long long int EchoCost = 0;
	long long int TotalCost = 0;
	int MSTcnt;
public:
	Kruskal(int n) {
		this->MSTcnt = n - 1;
		for (int i = 1; i <= n; i++) {
			parent[i] = i;
		}
	}
	
	void SetCity(long long int cost, int v1, int v2) {
		pq.push({ cost * -1, {v1, v2} });
		TotalCost += cost;
	}

	int GetParent(int v) {
		if (v == parent[v]) return v;
		return parent[v] = GetParent(parent[v]);
	}

	void Union_Find(int v1, int v2) {
		v1 = GetParent(v1);
		v2 = GetParent(v2);
		if (v1 > v2) parent[v1] = v2;
		else parent[v2] = v1;
	}

	void MST() {
		int now_v1, now_v2;

		EchoCost += (pq.top().first * -1);
		now_v1 = pq.top().second.first;
		now_v2 = pq.top().second.second;
		Union_Find(now_v1, now_v2);
		pq.pop();
		MSTcnt--;
		
		while (MSTcnt > 0) {
			now_v1 = pq.top().second.first;
			now_v2 = pq.top().second.second;
			if (GetParent(now_v1) == GetParent(now_v2)) pq.pop();
			else {
				Union_Find(now_v1, now_v2);
				MSTcnt--;
				EchoCost += (pq.top().first * -1);
				pq.pop();
			}
		}
		
		cout << TotalCost - EchoCost << "\n";
	}

};

int main(void) {
	cin.tie(NULL); ios::sync_with_stdio(false);

	int n, m;


	int v1, v2;
	long long int cost;
	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		Kruskal solution(n);
		for (int i = 0; i < m; i++) {
			cin >> v1 >> v2 >> cost;
			solution.SetCity(cost, v1, v2);
			
		}
		solution.MST();
	}


	
}