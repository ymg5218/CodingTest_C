// 2261

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#define INF 1e9
#define endl "\n"

using namespace std;

int n;
vector<pair<int, int>> p;
set<pair<int, int>> s;

void init() {
	cin >> n;
	p.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i].first >> p[i].second;
	}
	sort(p.begin(), p.end());
	
	s.insert({ p[0].second, p[0].first });
	s.insert({ p[1].second, p[1].first });
}

int get_dist(const pair<int, int> x, const pair<int, int> y) {
	return (x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second);
}

void solution() {
	int min_dis = get_dist(p[0], p[1]);
	int idx = 0;

	for (int i = 2; i < n; i++) {
		while (idx < i) {
			int d = p[i].first - p[idx].first;
			if (d * d <= min_dis)
				break;
			s.erase({ p[idx].second, p[idx].first });
			idx++;
		}
		auto start = s.lower_bound({ p[i].second - sqrt(min_dis), -INF });
		auto end = s.upper_bound({ p[i].second + sqrt(min_dis), INF });
		for (auto it = start; it != end; it++) {
			min_dis = min(min_dis, get_dist({ it->second, it->first }, p[i]));
		}
		s.insert({ p[i].second, p[i].first });
	}
	cout << min_dis << endl;
}

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	init();
	solution();

}