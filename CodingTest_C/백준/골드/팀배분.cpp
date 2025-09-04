// 1953

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define endl "\n"

using namespace std;


int N;
vector<int> color;
vector<vector<int>> hate;

void solution() {
	vector<int> v1;
	vector<int> v2;

	queue<int> q;

	for (int i = 1; i <= N; i++) {
		if (color[i] != -1) continue;
		color[i] = 0;
		v1.push_back(i);
		q.push(i);
		
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			int now_color = color[now];
			for (const auto x : hate[now]) {
				if (color[x] == -1) {
					q.push(x);
					color[x] = (now_color + 1) % 2;
					if (color[x] == 0)
						v1.push_back(x);
					else
						v2.push_back(x);
				}
			}
		}
		
	 }

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	cout << v1.size() << endl;
	for (const auto& v : v1) {
		cout << v << " ";
	}
	cout << endl;

	cout << v2.size() << endl;
	for (const auto& v : v2) {
		cout << v << " ";
	}
	cout << endl;
}

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	
	cin >> N;
	color.assign(N + 1, -1);
	hate.assign(N + 1, {});
	
	for (int i = 1; i <= N; i++) {
		int cnt;
		cin >> cnt;
		while (cnt--) {
			int x;
			cin >> x;
			hate[i].push_back(x);
		}
	}
	solution();
}